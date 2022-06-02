#include "stdlib.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "esp_log.h"
#include "math.h"
#include "adc.h"
#include "GPIO.h"
#include "temperature_controller.h"

struct CUR_TEMP_STR {
    uint8_t ready;
    float peltier_temperature;
};
struct CUR_TEMP_STR curtemp;


enum TEMP_STATE_T {
    TEMP_OK, 
    TEMP_HEATING, 
    TEMP_COOLING
    };
enum TEMP_STATE_T temperatureState;



float get_peltier_temperature()
{
    while(!curtemp.ready)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    return curtemp.peltier_temperature;
}
static void temperatureControlTask(void * arg) 
{
    
    for(;;) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        ESP_LOGI("TemperatureControlTask", "\n");
        //detect power switch
        if (read_pin(PWR_SW_PIN))
        {
            float temperature_adc = readTemperatureADC();  //read temperature

            curtemp.ready = false;
            //eqn: https://imgur.com/a/uP0DlLb
            curtemp.peltier_temperature = 1.00 / ((log((R1*(temperature_adc/(VCC-temperature_adc)))/NTC_R)/NTC_B)+(1.00/(NTC_T0)));
            curtemp.ready = true;
            ESP_LOGI("TemperatureControlTask", "temperature_adc: %f\n", temperature_adc);
            ESP_LOGI("TemperatureControlTask", "temperature: %f\n", (curtemp.peltier_temperature - KELVIN));
            //state machine for temperature decision
            switch (temperatureState)
            {
                case TEMP_OK:
                    //delay 29 more seconds in "idle" mode
                    vTaskDelay(29000 / portTICK_PERIOD_MS);
                    ESP_LOGI("TemperatureControlTask", "temperatureState: TEMP_OK:");
                    if (curtemp.peltier_temperature < MIN_TEMPERATURE)
                    {
                        temperatureState = TEMP_HEATING;
                    }
                    else if (curtemp.peltier_temperature > MAX_TEMPERATURE)
                    {
                        temperatureState = TEMP_COOLING;
                    }
                    else
                    {
                        //turn peltiers off
                        write_pin(DRIVER_EN_PIN, LOW);
                    }
                break;
                case TEMP_HEATING:
                    //no extra delay in "active" mode
                    ESP_LOGI("TemperatureControlTask", "temperatureState: TEMP_HEATING:");
                    if (curtemp.peltier_temperature < MID_TEMPERATURE)
                    {
                        //keep heating
        #ifdef PELTIER_INVERT
                        write_pin(DRIVER_DIR_PIN, HIGH);
        #else
                        write_pin(DRIVER_DIR_PIN, LOW);
        #endif
                        write_pin(DRIVER_EN_PIN, HIGH);
                    }
                    else
                    {
                        //stop heating
                        write_pin(DRIVER_EN_PIN, LOW);
                        temperatureState = TEMP_OK;
                    }
                break;
                case TEMP_COOLING:
                    ESP_LOGI("TemperatureControlTask", "temperatureState: TEMP_COOLING:");
                    //no extra delay in "active" mode
                    if (curtemp.peltier_temperature > MID_TEMPERATURE)
                    {
                        //keep cooling
        #ifdef PELTIER_INVERT
                        write_pin(DRIVER_DIR_PIN, LOW);
        #else
                        write_pin(DRIVER_DIR_PIN, HIGH);
        #endif
                        write_pin(DRIVER_EN_PIN, HIGH);
                    }
                    else
                    {
                        //stop cooling
                        write_pin(DRIVER_EN_PIN, LOW);
                        temperatureState = TEMP_OK;
                    }
                break;
                default:
                break;
            }
        }
        else
        {
            //disable
            write_pin(DRIVER_EN_PIN, LOW);
        }
    }
}

void temp_control_init(int8_t PRIORITY) 
{
    init_pin(PWR_SW_PIN, INPUT);
    init_pin(DRIVER_EN_PIN, OUTPUT);
    init_pin(DRIVER_DIR_PIN, OUTPUT);
    xTaskCreate(temperatureControlTask, "temperatureControlTask", 2048, NULL, PRIORITY, NULL);
}