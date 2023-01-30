
#include <string.h>

#include "esp_system.h"
#include "Connect_Wifi/wifi.h"
#include "Client handler/esp_client.h"
#include "nvs_flash.h"
#include "CT sensor/ctsensor0.h"

static const char *TAG = "MAIN";
void app_main()
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);

    initialise_wifi();

#if CONFIG_WIFI_CONNECT_AP
    ESP_LOGW(TAG, "Start AP Mode");

    wifi_ap();
#elif CONFIG_WIFI_CONNECT_STA
    ESP_LOGW(TAG, "Start STA Mode");
    wifi_sta(CONFIG_STA_CONNECT_TIMEOUT * 1000);
#elif CONFIG_WIFI_CONNECT_APSTA
    ESP_LOGW(TAG, "Start APSTA Mode");

    wifi_apsta(CONFIG_STA_CONNECT_TIMEOUT * 1000);

#endif
    // while (1)
    // {
    //     send_data();
    //     vTaskDelay(1000 / portTICK_RATE_MS);
    // }

    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc1_chars);

    adc1_config_width(ADC_WIDTH_BIT_DEFAULT);
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);
    uint32_t voltage;

    while (1)
    {
        int adc_value = adc1_get_raw(ADC1_CHANNEL_4);
        voltage = esp_adc_cal_raw_to_voltage(adc_value, &adc1_chars);
        printf("Voltage: %d mV", voltage);
        printf("\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
        send_data();
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}