#ifndef BLE_H_
#define BLE_H_





#define GATTS_SERVICE_UUID_TEST_A   0x00FF
#define GATTS_CHAR_UUID_TEST_A      0xFF01
#define GATTS_DESCR_UUID_TEST_A     0x3333
#define GATTS_NUM_HANDLE_TEST_A     4

#define DEVICE_NAME            "Insulin Cooler"
#define TEST_MANUFACTURER_DATA_LEN  17

#define CHAR_VAL_LEN_MAX 0x40

#define PREPARE_BUF_MAX_SIZE 1024
#define GATTS_TAG "INSULIN_COOLER"


#define adv_config_flag      (1 << 0)
#define scan_rsp_config_flag (1 << 1)

#define PROFILE_NUM 2
#define APP_ID 0


/***************************************************
 * bleInit
 * call to initialize BLE interrupt handles
 * 
 **************************************************/
esp_err_t bleInit();

#endif