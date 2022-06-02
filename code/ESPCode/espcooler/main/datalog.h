#ifndef DATALOG_H_
#define DATALOG_H_

/************************************************************
 * Log structure
 * stores battery and temperature info up to 8 hours
 * celcius
 ***********************************************************/
struct LOG_STR{
    uint8_t data_ready;
    uint16_t curpos;
    int8_t temperature[500];
    int8_t batt;
};




/*******************************************************
 * datalogInit
 * call at startup to start datalogging
 * 
 * 
 ******************************************************/
void datalogInit(int8_t PRIORITY);


/******************************************************
 * get_data_log
 * returns the logged data structure
 * 
 *****************************************************/
struct LOG_STR get_data_log();


/******************************************************
 * data_log_ready
 * mutex check for log structure
 * 
 *****************************************************/
uint8_t data_log_ready();
#endif