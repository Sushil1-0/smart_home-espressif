
#ifndef CTSENSOR0_H__
#define CTSENSOR0_H__

#include "esp_adc_cal.h"
#include "driver/adc.h"
#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#define ADC_CHANNEL ADC1_CHANNEL_4
#define ADC_WIDTH ADC_WIDTH_BIT_12
#define ACrange 120;
// static esp_adc_cal_characteristics_t adc1_chars;
extern float readACcurrentValue();

#endif