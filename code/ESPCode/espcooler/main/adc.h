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
void adcInit(void);

/**********************************************************************
 * ADC data struct
 * used to store ADC voltages
 * ready flag indicates data is ready to be read; set to false after read
 *********************************************************************/
typedef struct {
    bool ready;
    uint32_t data_1;
    uint32_t data_2;
    uint32_t data_3;
} ADC_DATA;


/**********************************************************************
 * ADC current data get
 * returns ADC_DATA data structure
 *********************************************************************/
ADC_DATA get_cell_data();
ADC_DATA get_temperature_data();


/*********************************************************************
 * data_ready
 * returns the ready potion of the adc data
 * 
 ********************************************************************/
bool temperature_data_ready();
bool batt_data_ready();