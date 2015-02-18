// 
//   FILE:  dht11_test1.pde
// PURPOSE: DHT11 library test sketch for Arduino
//


//

//
//#include <LiquidCrystal.h>
//
//LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

#include <dht11.h>

dht11 DHT11;

#define DHT11PIN 2

void setup()
{
  Serial.begin(115200);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
//  
//  lcd.begin(16, 2);
//  lcd.setCursor(0,0);
//  lcd.write("Temp: ");
//  lcd.setCursor(0,1);
//  lcd.write("Hum:  ");
}

void loop()
{
  Serial.println("\n");

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK: 
		Serial.println("OK"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.println("Checksum error"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.println("Time out error"); 
		break;
    default: 
		Serial.println("Unknown error"); 
		break;
  }

  int temp = DHT11.temperature;
  int tempCorrected = temp - 2;
  int humidity = DHT11.humidity;
  Serial.print("Temperature (C): ");
  Serial.println(temp);
  Serial.print("Temperature corrected (C): ");
  Serial.println(tempCorrected);
//  lcd.setCursor(7,0);
//  lcd.print((float)DHT11.temperature, 2);

  Serial.print("Humidity (%): ");
  Serial.println(humidity);
//  lcd.setCursor(7,1);
//  lcd.print((float)DHT11.humidity, 2);

  delay(5000);
}
//
// END OF FILE
//
