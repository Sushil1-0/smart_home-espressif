#include "esp_client.h"
#include "CT sensor/ctsensor0.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
esp_err_t client_event_post_handler(esp_http_client_event_handle_t evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ON_DATA:
        printf("HTTP_EVENT_ON_DATA: %.*s\n", evt->data_len, (char *)evt->data);
        break;

    default:
        break;
    }
    return ESP_OK;
}

//////////////////

// esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc1_chars);

// adc1_config_width(ADC_WIDTH_BIT_DEFAULT);
// adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);
// uint32_t voltage;

// vTaskDelay(500 / portTICK_PERIOD_MS);
// send_data();
// vTaskDelay(1000 / portTICK_RATE_MS);
// }
///////////////////
void send_data()
{
    float Current_Value =0;
    for (int k = 0; k < 60; k++)
    {

        float ACCurrentValue = readACcurrentValue(); // read AC Current Value
        printf("\nA=%f",ACCurrentValue);
        Current_Value =+ ACCurrentValue;
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
    float Rate_of_Current_Value_per_min = Current_Value / 60;

    // adc1_config_width(ADC_WIDTH);
    // adc1_config_channel_atten(ADC_CHANNEL, ADC_ATTEN_DB_0);
    // uint32_t adc_reading = adc1_get_raw(ADC_CHANNEL);
    // float voltage = (float)adc_reading / 4096 * 3.3;
    // int adc_value = adc1_get_raw(ADC1_CHANNEL_4);
    // voltage = esp_adc_cal_raw_to_voltage(adc_value, &adc1_chars);
    // printf("Voltage: %f mV", ACCurrtntValue);
    // printf("\n");
    esp_http_client_config_t config_post = {
        .url = "http://192.168.1.2:8080/sensor",
        .method = HTTP_METHOD_POST,
        .cert_pem = NULL,
        .event_handler = client_event_post_handler};
    esp_http_client_handle_t client = esp_http_client_init(&config_post);
    // int sensor_value = 100;
    char data[20];
    sprintf(data, "{\"value\": %f}", Rate_of_Current_Value_per_min);
    esp_http_client_set_post_field(client, data, strlen(data));
    esp_http_client_set_header(client, "Content-Type", "application/json");

    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}