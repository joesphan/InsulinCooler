#include "adc.h"
#include "temperature_controller.h"

void temp_control_init(void)
{
    

}

typedef enum {
    TEMP_OK,
    TEMP_HEATING,
    TEMP_COOLING
} TEMP_STATE_T;
static TEMP_STATE_T temperatureState;


static void temperatureControlTask(void * arg) 
{
    //wait for mutex to clear
    while (!temperature_data_ready())
    {
        vTaskDelay(portTICK_PERIOD_MS);
    }
    ADC_DATA databuf = get_temperature_data();
    //T=B/ln(Rthermistor/(10k*e^-(B/25C)))
    uint32_t temp = NTC_B / log((databuf.data_1*NTC_R) / (VCC - databuf.data_1) / C1);
    ESP_LOGI("TemperatureControlTask", "temperature: %d\n", temp);
    //state machine for temperature decision
    switch (temperatureState)
    {
        case TEMP_OK:
        break;
        case TEMP_HEATING:
        break;
        case TEMP_COOLING:
        break;
        default:
        break;
    }
}
