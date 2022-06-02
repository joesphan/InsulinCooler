#ifndef GPIO_H_
#define GPIO_H_

#define HIGH 1
#define LOW 0
#define INPUT 1
#define OUTPUT 0



#define PWR_SW_PIN 14
#define USB_PWR_DETECT_PIN 35


#define CELL_1_DISCHG_PIN 5
#define CELL_2_DISCHG_PIN 17
#define CELL_3_DISCHG_PIN 16
#define DRIVER_EN_PIN 22
#define DRIVER_DIR_PIN 19


/**********************************************
 * write_pin
 * writes to the specified digital pin
 * 
 *********************************************/
void write_pin(uint8_t digital_pin, uint8_t lvl);


/**********************************************
 * read_pin
 * reads from the specified digital pin
 * 
 *********************************************/
uint8_t read_pin(uint8_t digital_pin);

/**********************************************
 * init_pin
 * reads from the specified digital pin
 * 
 *********************************************/
void init_pin(uint8_t digital_pin, uint8_t pinMode);
#endif