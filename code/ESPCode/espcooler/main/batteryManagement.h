#ifndef BATTERYMANAGEMENT_H_
#define BATTERYMANAGEMENT_H_

#define MAX_CELL_VOLTAGE_DIFF .02


//#define TWO_CELL      //uncomment for only 2 cells

//cell voltage measurement 1/divider ratios
#define CELL_1_VOLTIGE_DIV_RATIO ((510.0 + 620.0) / 620.0)
#define CELL_2_VOLTIGE_DIV_RATIO ((180.0 + 68.0) / 68.0)
#define CELL_3_VOLTIGE_DIV_RATIO ((180.0 + 40.3) / 40.3)

//li-ion capabilities
#define MIN_CELL_VOLTAGE 3.7
#define MAX_CELL_VOLTAGE 4.1

/*******************************
 * batteryManagementInit
 * call at startup to start detect charger and perform cell balancing
 ******************************/
void batteryManagementInit(uint8_t PRIORITY);


/*******************************
 * get_battery_level
 * returns battery level in single percents
 ******************************/
uint8_t get_battery_level();

#endif