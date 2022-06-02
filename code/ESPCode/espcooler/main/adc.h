#ifndef ADC_H_
#define ADC_H_

#define DEFAULT_VREF    1100        //Use adc2_vref_to_gpio() to obtain a better estimate
#define NO_OF_SAMPLES   64          //Multisampling


/**************************************************************************
 * adcInit
 * initializes the ADC
 * call at startup
 * 
 *************************************************************************/
void adcInit(int8_t PRIORITY);

/**********************************************************************
 * ADC data struct
 * used to store ADC voltages
 * ready flag indicates data is ready to be read; set to false after read
 *********************************************************************/
struct ADC_DATA{
    float data[3];
};



/**********************************************************
 * readBatteryADC
 * reads and loads ADC values into memory
 * used by the task, as well as callable to get immediate ADC values
 *********************************************************/
struct ADC_DATA readBatteryADC();

/**********************************************************
 * readTemperatureADC
 * reads and loads ADC values into memory
 * used by the task, as well as callable to get immediate ADC values
 *********************************************************/
float readTemperatureADC();




/**********************************************************************
 * ADC current data get
 * returns ADC_DATA data structure
 *********************************************************************/
struct ADC_DATA get_battery_adc_data();
struct ADC_DATA get_thermistor_adc_data();


/*********************************************************************
 * data_ready
 * returns the ready potion of the adc data
 * 
 ********************************************************************/
uint8_t thermistor_adc_data_ready();
uint8_t battery_adc_data_ready();

#endif