#include <Wire.h>
#include <OneWire.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2          //DHT data is connected to pin2
#define DHTTYPE DHT11     //  sensor type DHT11
#define mainDelay 2000
  
DHT dht(DHTPIN, DHTTYPE); //global object dht
Adafruit_BMP085 bmp; //global object bmp

     
    void setup()
    {
      Serial.begin(9600);     // serial port init
      dht.begin();            // sensor init
      if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, wiring!");
	while (1) {}
      }
    }
     
    void loop()
    {
        float p = bmp.readPressure();     // read pressure
        float t = bmp.readTemperature();  // read temperature
        float h = dht.readHumidity();     // read humidity
     
      if (isnan(t) || isnan(h))
      {
        Serial.print("DHT read error!");
      }
      else
      {
        Serial.print("humidity ");
        Serial.println(h);
        Serial.print("temperature ");
        Serial.println(t);
        Serial.print("pressure ");
        Serial.println(p);
      }
      
      delay(mainDelay);    //delay
    }
