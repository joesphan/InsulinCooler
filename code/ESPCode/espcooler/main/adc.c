#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "esp_log.h"

#include "adc.h"


/**********************************************************************
 * ADC data storage for battery, to return 3 measurements at once
 *********************************************************************/
static struct ADC_DATA battery_adc_data;



/**********************************************************************
 * ADC paramaters struct
 * contains pinmappings and required initialization parameters
 * pinmappings found on page 15 https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf
 *********************************************************************/
static struct ap {
    //general params
    const adc_bits_width_t width;
    esp_adc_cal_characteristics_t adc_chars;
    const adc_atten_t atten;
    const adc_unit_t adcunit;

    //per-channel params
    //const adc_channel_t TEMP_SENSE_3_ch = ADC_CHANNEL_8;
    //const adc_channel_t TEMP_SENSE_2_ch = ADC_CHANNEL_9;
    const adc_channel_t TEMP_SENSE_1_ch;
    const adc_channel_t CELL_MEAS_3_ch;
    const adc_channel_t CELL_MEAS_2_ch;
    const adc_channel_t CELL_MEAS_1_ch;
} adc_params = {
    .width = ADC_WIDTH_BIT_12, 
    .atten = ADC_ATTEN_DB_11, 
    .adcunit = ADC_UNIT_2, 
    .TEMP_SENSE_1_ch = ADC_CHANNEL_7, 
    .CELL_MEAS_3_ch = ADC_CHANNEL_4, 
    .CELL_MEAS_2_ch = ADC_CHANNEL_3, 
    .CELL_MEAS_1_ch = ADC_CHANNEL_2};


float readTemperatureADC()
{
    uint32_t adc_reading = 0;
    //Multisampling
    for (int i = 0; i < NO_OF_SAMPLES; i++) {
        int raw;
        adc2_get_raw((adc2_channel_t)adc_params.TEMP_SENSE_1_ch, adc_params.width, &raw);
        adc_reading += raw;
    }
    adc_reading = adc_reading / NO_OF_SAMPLES;
    return ((float)esp_adc_cal_raw_to_voltage(adc_reading, &adc_params.adc_chars) / 1000.0);
    //ESP_LOGI("readADCTask: ", "temperature_adc_data: %f\n", temperature_adc_data.data_1);
}

struct ADC_DATA readBatteryADC()
{
    uint32_t adc_reading = 0;
    //Multisampling
    for (int i = 0; i < NO_OF_SAMPLES; i++) {
        int raw;
        adc2_get_raw((adc2_channel_t)adc_params.CELL_MEAS_3_ch, adc_params.width, &raw);
        adc_reading += raw;
    }
    adc_reading = adc_reading / NO_OF_SAMPLES;
    battery_adc_data.data[2] = (float)esp_adc_cal_raw_to_voltage(adc_reading, &adc_params.adc_chars) / 1000.0;
    //ESP_LOGI("readADCTask: ", "battery_adc_data_3: %f\n", battery_adc_data.data_3);
    
    adc_reading = 0;
    //Multisampling
    for (int i = 0; i < NO_OF_SAMPLES; i++) {
        int raw;
        adc2_get_raw((adc2_channel_t)adc_params.CELL_MEAS_2_ch, adc_params.width, &raw);
        adc_reading += raw;
    }
    adc_reading = adc_reading / NO_OF_SAMPLES;
    battery_adc_data.data[1] = (float)esp_adc_cal_raw_to_voltage(adc_reading, &adc_params.adc_chars) / 1000.0;
    //ESP_LOGI("readADCTask: ", "battery_adc_data_2: %f\n", battery_adc_data.data_2);

    adc_reading = 0;
    //Multisampling
    for (int i = 0; i < NO_OF_SAMPLES; i++) {
        int raw;
        adc2_get_raw((adc2_channel_t)adc_params.CELL_MEAS_1_ch, adc_params.width, &raw);
        adc_reading += raw;
    }
    adc_reading = adc_reading / NO_OF_SAMPLES;
    battery_adc_data.data[0] = (float)esp_adc_cal_raw_to_voltage(adc_reading, &adc_params.adc_chars) / 1000.0;
    //ESP_LOGI("readADCTask: ", "battery_adc_data_1: %f\n", battery_adc_data.data_1);
    return battery_adc_data;
}

void adcInit(int8_t PRIORITY)
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
    

    //Characterize ADC
    //adc_params.adc_chars = calloc(1, sizeof(esp_adc_cal_characteristics_t));
    esp_adc_cal_characterize(adc_params.adcunit, adc_params.atten, adc_params.width, DEFAULT_VREF, &adc_params.adc_chars);

    adc2_config_channel_atten((adc2_channel_t)adc_params.TEMP_SENSE_1_ch, adc_params.atten);
    adc2_config_channel_atten((adc2_channel_t)adc_params.CELL_MEAS_3_ch, adc_params.atten);
    adc2_config_channel_atten((adc2_channel_t)adc_params.CELL_MEAS_2_ch, adc_params.atten);
    adc2_config_channel_atten((adc2_channel_t)adc_params.CELL_MEAS_1_ch, adc_params.atten);
}
