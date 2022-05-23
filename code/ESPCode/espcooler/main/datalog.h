#ifndef DATALOG_H_
#define DATALOG_H_


/************************************************************
 * Log structure
 * stores battery and temperature info up to 1 week
 * 
 ***********************************************************/
typedef struct {
    int16_t curpos;
    int8_t temperature[10080];
    int8_t batt[10080];
    int32_t cur_batt_1_voltage;
    int32_t cur_batt_2_voltage;
    int32_t cur_batt_3_voltage;
    int32_t cur_temp_1;
    int32_t cur_temp_2;
    int32_t cur_temp_3;
} LOG_STR;

void datalogInit();