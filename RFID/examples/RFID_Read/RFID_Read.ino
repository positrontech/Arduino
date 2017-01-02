#include <ReceiveOnlySoftwareSerial.h>
#include <Rfid.h>

Rfid RFID(2);    //To initialize RFID at PIN 2

void setup() 
{
  Serial.begin(9600);      //Initialize Hardware Serial to check RFID Data
}

void loop() 
{
  String str=RFID.read();  //Read RFID Card
    
  if(str!="")
    Serial.println(str);  //Print RFID Card Number on Serial  
}
