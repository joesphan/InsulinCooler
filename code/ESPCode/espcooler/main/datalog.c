#include "datalog.h"
#include "adc.h"
//log of temperature and battery

static LOG_STR log;


void storeDataPoint(uint8_t temp, uint8_t batt)
{
    
}

void datalogInit()
{
    xTaskCreate(datalogTask, "datalogTask", 2048, NULL, 2, NULL);
}

/*************************************************************************
 * responsible for converting and storing the temperature and battery info
 * 
 * 
 *************************************************************************/
static void datalogTask(void * arg) 
{
    ADC_DATA adc_temp_data;

    while(!data_ready())
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        //delay 1ms and check again if data not ready
    }

    adc_temp_data = get_adc_data();

    //cell 1 voltage conversions
    log.cur_batt_1_voltage = adc_convert(adc_temp_data.CELL_MEAS_1_RAW);

    //cell 2 voltage conversions
    log.cur_batt_2_voltage = adc_convert(adc_temp_data.CELL_MEAS_2_RAW);

    //cell 3 voltage conversions
    log.cur_batt_3_voltage = adc_convert(adc_temp_data.CELL_MEAS_3_RAW);

    //Temp Sensor 1 Conversions
    log.cur_temp_1 = adc_convert(adc_temp_data.TEMP_SENSE_1_RAW);

    //Temp Sensor 2 Conversions
    log.cur_temp_2 = adc_convert(adc_temp_data.TEMP_SENSE_2_RAW);
    
    //Temp Sensor 3 Conversions
    log.cur_temp_3 = adc_convert(adc_temp_data.TEMP_SENSE_3_RAW);
    
    //calculate and store avg temperature
    log.temperature[log.curpos] = (log.cur_temp_1 + log.cur_temp_2 + log.cur_temp_3) / 3.00;

    //calculate and store battery percentage
    log.batt[log.curpos] = 


}

void getCurTemperature() 
{

}
void getCurBatt() 
{

}