#include "stdlib.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "GPIO.h"


/*************************************
 * convert_gpio
 * converts int gpio to gpio_num_t
 * 
 ************************************/
static gpio_num_t convert_gpio[40] = 
{
    GPIO_NUM_0,
    GPIO_NUM_1,
    GPIO_NUM_2,
    GPIO_NUM_3,
    GPIO_NUM_4,
    GPIO_NUM_5,
    GPIO_NUM_6,
    GPIO_NUM_7,
    GPIO_NUM_8,
    GPIO_NUM_9,
    GPIO_NUM_10,
    GPIO_NUM_11,
    GPIO_NUM_12,
    GPIO_NUM_13,
    GPIO_NUM_14,
    GPIO_NUM_15,
    GPIO_NUM_16,
    GPIO_NUM_17,
    GPIO_NUM_18,
    GPIO_NUM_19,
    GPIO_NUM_20,
    GPIO_NUM_21,
    GPIO_NUM_22,
    GPIO_NUM_23,
    GPIO_NUM_NC,
    GPIO_NUM_25,
    GPIO_NUM_26,
    GPIO_NUM_27,
    GPIO_NUM_28,
    GPIO_NUM_29,
    GPIO_NUM_30,
    GPIO_NUM_31,
    GPIO_NUM_32,
    GPIO_NUM_33,
    GPIO_NUM_34,
    GPIO_NUM_35,
    GPIO_NUM_36,
    GPIO_NUM_37,
    GPIO_NUM_38,
    GPIO_NUM_39  };



/**********************************************
 * read_pin
 * reads from the specified digital pin
 * 
 *********************************************/
uint8_t read_pin(uint8_t digital_pin)
{
    gpio_pad_select_gpio(digital_pin);
    return gpio_get_level(convert_gpio[digital_pin]);
}

/**********************************************
 * write_pin
 * writes to the specified digital pin
 * 
 *********************************************/
void write_pin(uint8_t digital_pin, uint8_t lvl)
{
    gpio_pad_select_gpio(digital_pin);
    gpio_set_level(digital_pin, lvl);
}


void init_pin(uint8_t digital_pin, uint8_t pinMode)
{
    gpio_pad_select_gpio(digital_pin);
    switch(pinMode)
    {
        case INPUT:
            gpio_set_direction(digital_pin, GPIO_MODE_INPUT);
        break;
        case OUTPUT:
            gpio_set_direction(digital_pin, GPIO_MODE_OUTPUT);
        break;
        default:
            ESP_LOGE("GPIO.c, init_pin", "default case entered");
        break;
    }

}