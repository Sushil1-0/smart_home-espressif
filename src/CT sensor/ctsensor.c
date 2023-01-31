#include "ctsensor0.h"

/***************************************************************
------------------------CT SENOSR DATA--------------------------
****************************************************************/
// const double offset = 0;   // Half the ADC max voltage
// const int numTurns = 3000; // 1:3000 transformer turns
// const int rBurden = 100;   // Burden resistor value

float readACcurrentValue()
{
    adc1_config_width(ADC_WIDTH);
    adc1_config_channel_atten(ADC_CHANNEL, ADC_ATTEN_DB_0);
    // uint32_t adc_reading = adc1_get_raw(ADC_CHANNEL);
    // float voltage = (float)adc_reading / 4096 * 3.3;
    // float ACCurrtntValue = 0;
    float peakVoltage = 0;
    float voltageVirtualValue = 0; // Vrms
    for (int i = 0; i < 5; i++)
    {
        peakVoltage += (uint32_t )adc1_get_raw(ADC_CHANNEL);
        // vTaskDelay(10 / portTICK_RATE_MS);
    }
    peakVoltage = (float)peakVoltage / 5.0;
    voltageVirtualValue = (float)peakVoltage * 0.707;
    voltageVirtualValue = ((float)voltageVirtualValue / 4096 * 3.3);
    // voltageVirtualValue = (voltageVirtualValue / rBurden )*3000;
    // voltageVirtualValue = voltageVirtualValue * 0.707;
    float ACCurrtntValue = voltageVirtualValue * ACrange;
    // printf("%f",ACCurrtntValue);

    return ACCurrtntValue;
}
