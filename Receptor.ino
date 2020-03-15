#include <SPI.h>
#include <RF24.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// direccion I2C del lcd, y su dimension
LiquidCrystal_I2C lcd(0x27,20,4);

// se definen los pines del modulo nRF24 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);
 
// Direccion de radio del nRF24
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
// array para los datos a recibir
float data[5];
 
void setup(){
    lcd.init(); // inicia el lcd 
    lcd.backlight(); // se enciende la luz del lcd
    lcd.setCursor(0,0); // se posiciona en 0,0
    lcd.print("Estacion Climatica:"); // escribimos en el lcd
    radio.begin(); // iniciamos la comunicacion por radio
    Serial.begin(9600); // iniciamos la comunicacion serial

    // se comienza a escuchar por radio
    radio.openReadingPipe(1, pipe);
    radio.startListening();
}
 
void loop(){
    // lemos los datos que recibimos
    radio.read(data, sizeof data);

    // imprimimos todo lo que llega en el puerto serial 
    Serial.print(data[1]);
    Serial.print(",");
    Serial.print(data[2]);
    Serial.print(",");
    Serial.print(data[3]);
    Serial.print(",");
    Serial.println(data[4]);

    // imprimimos los datos en el lcd
    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.setCursor(5,1);
    lcd.print(data[1]);
    lcd.setCursor(10,1);
    lcd.print("C");

    lcd.setCursor(0,2);
    lcd.print("Hum:");
    lcd.setCursor(5,2);
    lcd.print(data[2]);
    lcd.setCursor(10,2);
    lcd.print("%");

    lcd.setCursor(0,3);
    lcd.print("M/nm:");
    lcd.setCursor(6,3);
    lcd.print(data[4]);
    lcd.setCursor(12,3);
    lcd.print("m");

    // esperamos 2 segundos
    delay(2000);

    // si siguen llegando limpiamos el lcd
    if (radio.available()){  
      lcd.clear();
    }
}
