#ifndef BATTERYMANAGEMENT_H_
#define BATTERYMANAGEMENT_H_

#define MAX_CELL_VOLTAGE_DIFF .02

/*******************************
 * batteryManagementInit
 * call at startup to start detect charger and perform cell balancing
 ******************************/
void batteryManagementInit(uint8_t PRIORITY);
#endif