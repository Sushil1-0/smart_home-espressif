// // #include "ctsensor.h"

// // #define ACrange 120;
// // #define REG_VOL_START 0x20

// // /***************************************************************
// // ------------------------CT SENOSR DATA--------------------------
// // ****************************************************************/
// // float ACCurrtntValue = 0;
// // float peakVoltage = 0;
// // float voltageVirtualValue;
// // const double offset = 0;   // Half the ADC max voltage
// // const int numTurns = 3000; // 1:3000 transformer turns
// // const int rBurden = 100;   // Burden resistor value

// // float readACcurrentValue(int fd)
// // {

// //     float ACCurrtntValue = 0;
// //     float peakVoltage = 0;
// //     float voltageVirtualValue = 0; // Vrms
// //     for (int i = 0; i < 5; i++)
// //     {
// //         peakVoltage += wiringPiI2CReadReg16(fd, REG_VOL_START + 4);
// //         delay(1);
// //     }
// //     peakVoltage = peakVoltage / 5.0;
// //     voltageVirtualValue = peakVoltage * 0.707;
// //     voltageVirtualValue = (voltageVirtualValue / 4096 * 3.3);
// //     // voltageVirtualValue = (voltageVirtualValue / rBurden )*3000;
// //     // voltageVirtualValue = voltageVirtualValue * 0.707;
// //     ACCurrtntValue = voltageVirtualValue * ACrange;
// //     // printf("%f",ACCurrtntValue);

// //     return ACCurrtntValue;
// // }

// #include <Wire.h>
// #include "CTSensor.h"
// #include "Adafruit_ADS1015.h"

// #define CHANNEL_COUNT 4

// Adafruit_ADS1115 ads(0x48);

// class ArduinoCTSensor : public CTSensor
// {
// public:
//   ArduinoCTSensor(uint8_t n) : CTSensor(n) {}

//   float get_raw_value_for(uint8_t channel)
//   {
//     int16_t instant = ads.readADC_SingleEnded(channel);
//     return (instant * 0.1875) / 1000;
//   }

//   void print_log(const char *msg)
//   {
//     Serial.println(msg);
//   }

//   void delay(uint16_t miliseconds)
//   {
//     delay(miliseconds);
//   }
// };

// ArduinoCTSensor *sensor;

// void setup(void)
// {
//   Wire.setClock(400000);
//   Serial.begin(9600);
//   ads.begin();

//   sensor = new ArduinoCTSensor(CHANNEL_COUNT);
//   sensor->set_ref_voltage_on_zero_current_for(0, 1.659);
//   sensor->set_ref_voltage_on_zero_current_for(1, 1.6025);
//   sensor->set_ref_voltage_on_zero_current_for(2, 1.654);
//   sensor->set_ref_voltage_on_zero_current_for(3, 1.6888);
//   sensor->init();
//   sensor->print_debug_info();
// }

// void loop(void)
// {
//   sensor->reset();
//   sensor->start_sampling();
//   sensor->print_channels_info();
// }