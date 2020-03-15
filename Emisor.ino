#include <SPI.h>
#include "RF24.h"
#include "Seeed_BME280.h"
#include <Wire.h>

// se definen los pines del modulo nRF24 
const int pinCE = 8;
const int pinCSN = 9;
RF24 radio(pinCE, pinCSN);

// configuramos el sensor como un bme280
BME280 bme280;
 
// Direccion de radio del nRF24
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
// array para los datos a enviae
float data[5];
 
void setup(){
    // iniciamos el sensor
    bme280.init();
    // iniciamos el modulo nRF24
    radio.begin();
    radio.openWritingPipe(pipe);
}
 
void loop(){
    // leemos y asignamos las lecuras del sensor
    float pres = bme280.getPressure();
    data[0] = millis()/1000.0;
    data[1] = bme280.getTemperature();
    data[2] = bme280.getHumidity();
    data[3] = pres;
    data[4] = bme280.calcAltitude(pres);
    // enviamos el array por radio
    radio.write(data, sizeof data);
}
