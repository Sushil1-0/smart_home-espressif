#ifndef ESP_CLIENT_H__
#define ESP_CLIENT_H__
#include "esp_http_client.h"

esp_err_t client_event_post_handler(esp_http_client_event_handle_t evt);
void send_data();

#endif 