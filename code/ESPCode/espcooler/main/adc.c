#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

#include "adc.h"


/**********************************************************************
 * ADC data storage
 *********************************************************************/
static ADC_DATA temperature_adc_data;
static ADC_DATA battery_adc_data;

/**********************************************************************
 * ADC paramaters struct
 * contains pinmappings and required initialization parameters
 * pinmappings found on page 15 https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf
 *********************************************************************/
static const struct adc_params {
    //general params
    const adc_bits_width_t width = ADC_WIDTH_BIT_12;
    esp_adc_cal_characteristics_t *adc_chars;
    const adc_atten_t atten = ADC_ATTEN_DB_3;
    const adc_unit_t adcunit = ADC_UNIT_2;

    //per-channel params
    const adc_channel_t TEMP_SENSE_3_ch = ADC_CHANNEL_8;
    const adc_channel_t TEMP_SENSE_2_ch = ADC_CHANNEL_9;
    const adc_channel_t TEMP_SENSE_1_ch = ADC_CHANNEL_7;
    const adc_channel_t CELL_MEAS_3_ch = ADC_CHANNEL_4;
    const adc_channel_t CELL_MEAS_2_ch = ADC_CHANNEL_3;
    const adc_channel_t CELL_MEAS_1_ch = ADC_CHANNEL_2;
};


bool temperature_data_ready()
{
    return temperature_adc_data.ready;
}

bool batt_data_ready()
{
    return battery_adc_data.ready;
}


ADC_DATA get_temperature_data()
{
    ADC_DATA temp_adc_data = temperature_adc_data;
    temperature_adc_data.ready = false;
    return temp_adc_data;
}

ADC_DATA get_cell_data()
{
    ADC_DATA temp_adc_data = battery_adc_data;
    battery_adc_data.ready = false;
    return temp_adc_data;
}

void adcInit()
{
    //Check if Two Point or Vref are burned into eFuse
    //Check if TP is burned into eFuse
    if (esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_TP) == ESP_OK) {
        printf("eFuse Two Point: Supported\n");
    } else {
        printf("eFuse Two Point: NOT supported\n");
    }
    //Check Vref is burned into eFuse
    if (esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_VREF) == ESP_OK) {
        printf("eFuse Vref: Supported\n");
    } else {
        printf("eFuse Vref: NOT supported\n");
    }
    
    adc2_config_channel_atten((adc2_channel_t)adc_params.TEMP_SENSE_3_ch, adc_params.atten);
    adc2_config_channel_atten((adc2_channel_t)adc_params.TEMP_SENSE_2_ch, adc_params.atten);
    adc2_config_channel_atten((adc2_channel_t)adc_params.TEMP_SENSE_1_ch, adc_params.atten);
    adc2_config_channel_atten((adc2_channel_t)adc_params.CELL_MEAS_3_ch, adc_params.atten);
    adc2_config_channel_atten((adc2_channel_t)adc_params.CELL_MEAS_2_ch, adc_params.atten);
    adc2_config_channel_atten((adc2_channel_t)adc_params.CELL_MEAS_1_ch, adc_params.atten);

    //Characterize ADC
    adc_params.adc_chars = calloc(1, sizeof(esp_adc_cal_characteristics_t));
    esp_adc_cal_value_t val_type = esp_adc_cal_characterize(unit, adc_params.atten, adc_params.width, DEFAULT_VREF, adc_params.adc_chars);
    adcdata.ready = true;
    xTaskCreate(readADCTask, "readADCTask", 2048, NULL, 1, NULL);
}

/**********************************************************
 * readADCtask
 * reads and loads ADC values into memory
 * 
 *********************************************************/
static void readADCTask(void * arg) 
{
    for(;;) {
        vTaskDelay(30000 / portTICK_PERIOD_MS);
        temperature_adc_data.ready = false;
        battery_adc_data.ready = false;
        //write adc data into adc_data
        uint32_t adc_reading = 0;
        //Multisampling
        for (int i = 0; i < NO_OF_SAMPLES; i++) {
            int raw;
            adc2_get_raw((adc2_channel_t)adc_params.TEMP_SENSE_3_ch, adc_params.width, &raw);
            adc_reading += raw;
        }
        temperature_adc_data.data_3 = esp_adc_cal_raw_to_voltage(adc_reading, adc_params.adc_chars);
        
        adc_reading = 0;
        //Multisampling
        for (int i = 0; i < NO_OF_SAMPLES; i++) {
            int raw;
            adc2_get_raw((adc2_channel_t)adc_params.TEMP_SENSE_2_ch, adc_params.width, &raw);
            adc_reading += raw;
        }
        temperature_adc_data.data_2 = esp_adc_cal_raw_to_voltage(adc_reading, adc_params.adc_chars);
        
        adc_reading = 0;
        //Multisampling
        for (int i = 0; i < NO_OF_SAMPLES; i++) {
            int raw;
            adc2_get_raw((adc2_channel_t)adc_params.TEMP_SENSE_1_ch, adc_params.width, &raw);
            adc_reading += raw;
        }
        temperature_adc_data.data_1 = esp_adc_cal_raw_to_voltage(adc_reading, adc_params.adc_chars);
        
        adc_reading = 0;
        //Multisampling
        for (int i = 0; i < NO_OF_SAMPLES; i++) {
            int raw;
            adc2_get_raw((adc2_channel_t)adc_params.CELL_MEAS_3_ch, adc_params.width, &raw);
            adc_reading += raw;
        }
        battery_adc_data.data_3 = esp_adc_cal_raw_to_voltage(adc_reading, adc_params.adc_chars);
        
        adc_reading = 0;
        //Multisampling
        for (int i = 0; i < NO_OF_SAMPLES; i++) {
            int raw;
            adc2_get_raw((adc2_channel_t)adc_params.CELL_MEAS_2_ch, adc_params.width, &raw);
            adc_reading += raw;
        }
        battery_adc_data.data_2 = esp_adc_cal_raw_to_voltage(adc_reading, adc_params.adc_chars);

        adc_reading = 0;
        //Multisampling
        for (int i = 0; i < NO_OF_SAMPLES; i++) {
            int raw;
            adc2_get_raw((adc2_channel_t)adc_params.CELL_MEAS_1_ch, adc_params.width, &raw);
            adc_reading += raw;
        }
        battery_adc_data.data_1 = esp_adc_cal_raw_to_voltage(adc_reading, adc_params.adc_chars);

        temperature_adc_data.ready = true;
        battery_adc_data.ready = true;
    }
    vTaskDelete(NULL);
}
