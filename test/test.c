#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define LED_PIN GPIO_NUM_32
#define middle_pin GPIO_NUM_15
#define lower_pin GPIO_NUM_2
#define upper_pin GPIO_NUM_4
#define BUTTON_PIN GPIO_NUM_36


void app_main(void)
{
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_set_direction(middle_pin, GPIO_MODE_INPUT);
    gpio_set_direction(lower_pin, GPIO_MODE_INPUT);
    gpio_set_direction(upper_pin, GPIO_MODE_INPUT);
    while (1)
    {
        int state = gpio_get_level(lower_pin);
        if (state == 0)
        {
            printf("off");
        }
        else if (state == 1)
        {
            printf("on");
        }
        else{
            printf("error");
        }
        // if (gpio_get_level(upper_pin) == 0 && gpio_get_level(middle_pin)==0 && gpio_get_level(lower_pin)==0)
        // {
        //     gpio_set_level(LED_PIN, 1);
        //     printf("led on");
        // }
        // else
        // {
        //     gpio_set_level(LED_PIN, 0);
        //     printf("led off");
        // }
        vTaskDelay(1); // Add 1 tick delay (10 ms) so that current task does not starve idle task and trigger watchdog timer
    }
}
// // The setup routine runs once when you press reset:
// void setup() {
//   // initialize serial communication at 9600 bits per second:
//   Serial.begin(9600);
//   // make the pushbutton's pin an input:
//   pinMode(Level1, INPUT);
//   pinMode(Level2, INPUT);
//   pinMode(Level3, INPUT);
// }

// // the loop routine runs over and over again forever:
// void loop() {

//   if(digitalRead(Level3)==LOW){
//     Serial.println("Water reaches Level-3 Water Quantity= 900 Liters ");
//   }
//   else if(digitalRead(Level2)==LOW){
//     Serial.println("Water reaches Level-2 Water Quantity= 600 Liters ");
//   }
//   else if(digitalRead(Level1)==LOW){
//     Serial.println("Water reaches Level-1 Water Quantity= 300 Liters ");
//   }
//   else {
//     Serial.println("Water at Dead level");
//     }

// }