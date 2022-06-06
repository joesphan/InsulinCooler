#ifndef TEMPERATURE_CONTROLLER_H_
#define TEMPERATURE_CONTROLLER_H_


//#define PELTIER_INVERT //uncomment to invert peltier pins (hot/cold)

//temperature params

//temperature limits, degrees C
//limits of insulin are 2.22 to 7.778 degrees C
#define MAX_TEMPERATURE (273.15 + 7)
#define MIN_TEMPERATURE (273.15 + 3)
#define MID_TEMPERATURE ((((float)MAX_TEMPERATURE - (float)MIN_TEMPERATURE) / 2.00) + (float)MIN_TEMPERATURE)


//pwm cycles. duty cycle = 1/PELTIER_PWM * 100 %
#define PELTIER_PWM 3
//calcs
#define PELTIER_PWM_COUNT (uint8_t)PELTIER_PWM

#define KELVIN 273.15
//beta value for ntc resistor
#define NTC_B 3950
//R value at T0
#define NTC_R 10000
//T0 temperature celcius
#define NTC_T0 (KELVIN + 25)
//R1 value, the other resistor in the divider
#define R1 10000
//voltage of the north of voltage divider
#define VCC 3.3

#define C1 (NTC_R * exp(-(NTC_B/NTC_T0)))




/***************************************************************
 * temperate controller intialization
 * initializes the ADC, GPIO/PWM
 **************************************************************/
void temp_control_init(int8_t PRIORITY);


/***************************************************************
 * get_peltier_temperature
 * returns the temperature in kelvins
 **************************************************************/
float get_peltier_temperature();
/***************************************************************
 * peltier_temperature_ready
 * returns the state of the mutex of the temperature
 **************************************************************/
uint8_t peltier_temperature_ready();

#endif