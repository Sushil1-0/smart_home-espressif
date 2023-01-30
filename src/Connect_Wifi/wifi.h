#ifndef WIFI_H__
#define WIFI_H__
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <string.h>

extern void event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
extern void initialise_wifi(void);
extern bool wifi_ap(void);
extern bool wifi_sta(int timeout_ms);
extern bool wifi_apsta(int timeout_ms);


#endif