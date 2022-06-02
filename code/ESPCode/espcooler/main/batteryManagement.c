#include "stdlib.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "adc.h"
#include "GPIO.h"
#include "batteryManagement.h"

static void batteryManagementTask(void * arg)
{
    uint8_t mgmtState = 0;
    for(;;)
    {
        switch (mgmtState)
        {
            case 0:
                //idle mode
                //check every 30s for power detection
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
                struct ADC_DATA adcbuf = readBatteryADC();
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
                            write_pin(CELL_3_DISCHG_PIN, HIGH);
                            write_pin(CELL_1_DISCHG_PIN, LOW);
                            write_pin(CELL_2_DISCHG_PIN, LOW);
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

