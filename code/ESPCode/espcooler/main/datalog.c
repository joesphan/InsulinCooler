
#include "stdlib.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "datalog.h"
#include "temperature_controller.h"
//log of temperature and battery
struct LOG_STR data_log;
/*
data_log = {
    .data_ready = 0,
    .curpos = 0,
    .temperature = {-128},
    .batt = -1
    };
*/

uint8_t data_log_ready()
{
    return data_log.data_ready;
}

struct LOG_STR get_data_log() 
{
    return data_log;
}





/*************************************************************************
 * datalogTask
 * converts and stores the temperature and battery info
 * 
 * 
 *************************************************************************/
static void datalogTask(void * arg) 
{
    
    for(;;) {
        vTaskDelay(30000 / portTICK_PERIOD_MS);
        data_log.data_ready = 0;
        //calculate and store avg temperature
        //celcius
        data_log.temperature[data_log.curpos] = (int8_t)(get_peltier_temperature() - (float)273.15);
        if (data_log.curpos < 499)
        {
            data_log.curpos = data_log.curpos + 1;
        }
        else
        {
            data_log.curpos = 0;
        }
        data_log.data_ready = 1;
    }

}

void datalogInit(int8_t PRIORITY)
{
    xTaskCreate(datalogTask, "datalogTask", 2048, NULL, PRIORITY, NULL);
}
