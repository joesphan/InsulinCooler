////////////////////////////
//#include <stdio.h>

//#include <stdlib.h>
//#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "sdkconfig.h"

#include "adc.h"
#include "temperature_controller.h"
#include "datalog.h"
#include "BLE.h"
#include "batteryManagement.h"

void app_main(void)
{
    esp_err_t ret;

    ret = bleInit();
    if (ret)
    {
        ESP_LOGE(GATTS_TAG, "\nbleInit error");
        return;
    }
    adcInit(1);
    temp_control_init(2);
    datalogInit(3);
    batteryManagementInit(4);
    return;
}
