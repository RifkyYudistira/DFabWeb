
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

void setup() 
{
Serial.begin(9600);
Serial.println(F("Sensing temperature.."));

dht.begin();

  
lcd.begin(16,2);
lcd.backlight();

lcd.print("Sensing"); 
delay(1000);
lcd.setCursor(0,1);  
lcd.print("temperature..");
delay(3000); 


}

void loop() 
{
   delay(1000);

  float t = dht.readTemperature();
 
  float F = dht.readTemperature(false);

  
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hic = dht.computeHeatIndex(t, false);

 
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
 

lcd.setCursor(0,0); 



lcd.clear();
lcd.setCursor(0,0); 
lcd.print("Temperature:");
lcd.setCursor(0,1);
lcd.print(F);
lcd.print("C");
delay(1000); 
}
