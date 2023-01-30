#include "esp_client.h"

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

void send_data()
{
    esp_http_client_config_t config_post = {
        .url = "http://192.168.1.2:8080/sensor",
        .method = HTTP_METHOD_POST,
        .cert_pem = NULL,
        .event_handler = client_event_post_handler};
    esp_http_client_handle_t client = esp_http_client_init(&config_post);
    int sensor_value = 100;
    char data[20];
    sprintf(data, "{\"value\": %d}", sensor_value);
    esp_http_client_set_post_field(client, data, strlen(data));
    esp_http_client_set_header(client, "Content-Type", "application/json");

    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}