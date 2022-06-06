#include "stdlib.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "adc.h"
#include "GPIO.h"
#include "batteryManagement.h"
struct CUR_BATT_STR {
    uint8_t ready;
    uint8_t battery_percentage;
};
struct CUR_BATT_STR curbatt;

uint8_t get_battery_level()
{
    while(!curbatt.ready)
    {
        vTaskDelay(portTICK_PERIOD_MS);
    }
    return curbatt.battery_percentage;
}


static void batteryManagementTask(void * arg)
{
    uint8_t mgmtState = 0;
    for(;;)
    {
        curbatt.ready = false;
        //measure and calculate cell voltages
        struct ADC_DATA adcbuf = readBatteryADC();

        //voltage of a single cell, on average
#ifdef TWO_CELL
        float avg_cell_voltage = (adcbuf.data[1] * CELL_2_VOLTIGE_DIV_RATIO) / 2.0;
#else
        float avg_cell_voltage = (adcbuf.data[2] * CELL_3_VOLTIGE_DIV_RATIO) / 3.0;
#endif
        curbatt.battery_percentage = (uint8_t)(((avg_cell_voltage - MIN_CELL_VOLTAGE) / (MAX_CELL_VOLTAGE-MIN_CELL_VOLTAGE)) * 100.0);
        curbatt.ready = true;

        switch (mgmtState)
        {
            case 0:
                //idle mode
                //check every 30s for power detection and batter level
                vTaskDelay(30000 / portTICK_PERIOD_MS);
                write_pin(CELL_1_DISCHG_PIN, LOW);
                write_pin(CELL_2_DISCHG_PIN, LOW);
                write_pin(CELL_3_DISCHG_PIN, LOW);
                mgmtState = read_pin(USB_PWR_DETECT_PIN);
            break;
            case 1:
                //active mode
                //update every 1ms
                vTaskDelay(portTICK_PERIOD_MS);
                uint8_t maxindex = 0;
                float maxdiff = 0;     //records largest cell voltage difference
                //find the cell with the greatest voltage
                for (uint8_t i = 0; i < 3; i++)
                {
                    if (adcbuf.data[i] > adcbuf.data[maxindex])
                    {
                        maxindex = i;
                    }
                    if (abs(adcbuf.data[i] - adcbuf.data[maxindex]) > maxdiff)
                    {
                        maxdiff = abs(adcbuf.data[i] - adcbuf.data[maxindex]);
                    }
                }

                //check for if cell voltage difference is great enough to warrant balancing
                if (maxdiff > MAX_CELL_VOLTAGE_DIFF)
                {
                    switch (maxindex)
                    {
                        case 0:
                            write_pin(CELL_1_DISCHG_PIN, HIGH);
                            write_pin(CELL_2_DISCHG_PIN, LOW);
                            write_pin(CELL_3_DISCHG_PIN, LOW);
                        break;
                        case 1:
                            write_pin(CELL_2_DISCHG_PIN, HIGH);
                            write_pin(CELL_1_DISCHG_PIN, LOW);
                            write_pin(CELL_3_DISCHG_PIN, LOW);
                        break;
                        case 2:
#ifndef TWO_CELL
                            write_pin(CELL_3_DISCHG_PIN, HIGH);
                            write_pin(CELL_1_DISCHG_PIN, LOW);
                            write_pin(CELL_2_DISCHG_PIN, LOW);
#endif
                        break;
                        default:
                            ESP_LOGE("batteryManagementTask", "maxindex default case entered");
                        break;
                    }
                }
                else
                {
                    write_pin(CELL_1_DISCHG_PIN, LOW);
                    write_pin(CELL_2_DISCHG_PIN, LOW);
                    write_pin(CELL_3_DISCHG_PIN, LOW);
                }
                mgmtState = read_pin(USB_PWR_DETECT_PIN);
            break;
            default:
                ESP_LOGE("batteryManagementTask", "mgmtState default case entered");
            break;
        }
    }
}

void batteryManagementInit(uint8_t PRIORITY)
{
    init_pin(CELL_1_DISCHG_PIN, OUTPUT);
    init_pin(CELL_2_DISCHG_PIN, OUTPUT);
    init_pin(CELL_3_DISCHG_PIN, OUTPUT);
    init_pin(USB_PWR_DETECT_PIN, INPUT);
    write_pin(CELL_1_DISCHG_PIN, LOW);
    write_pin(CELL_2_DISCHG_PIN, LOW);
    write_pin(CELL_3_DISCHG_PIN, LOW);
    xTaskCreate(batteryManagementTask, "batteryManagementTask", 2048, NULL, PRIORITY, NULL);
}

