#include <ReceiveOnlySoftwareSerial.h>
#include <GpsL80.h>

GpsL80 GPS(2);    //To initialize RFID at PIN 2

void setup() 
{
  Serial.begin(9600);      //Initialize Hardware Serial to check RFID Data
}

void loop() 
{
  GPS.read();  //Read RFID Card
  
  Serial.print("LAT = "); 
  Serial.println(GPS.lat);
  Serial.print("LONGI = ");
  Serial.println(GPS.longi);
  Serial.print("SPEED = ");
  Serial.println(GPS.speed);
  Serial.print("DATE = ");
  Serial.println(GPS.date);
  Serial.print("TIME = ");
  Serial.println(GPS.time);
  
}
