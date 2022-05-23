#ifndef TEMPERATURE_CONTROLLER_H_
#define TEMPERATURE_CONTROLLER_H_


//temperature params

//temperature limits, degrees C
#define MAX_TEMPERATURE 7.778
#define MIN_TEMPERATURE 2.222
#define MID_TEMPERATURE ((MAX_TEMPERATURE - MIN_TEMPERATURE) / 2) + MIN_TEMPERATURE

//beta value for ntc resistor
#define NTC_B 3950
//R value at T0
#define NTC_R 10000
//T0 temperature celcius
#define NTC_T0 273.15 + 25
//R1 value, the other resistor in the divider
#define R1 10000
//voltage of the north of voltage divider
#define VCC 3.3

#define C1 NTC_R * exp(-(NTC_B/NTC_T0))

/***************************************************************
 * temperate controller intialization
 * initializes the ADC, GPIO/PWM
 **************************************************************/
void temp_control_init(void);