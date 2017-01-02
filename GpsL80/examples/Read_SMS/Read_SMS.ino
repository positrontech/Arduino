#include <SoftwareSerial.h>
#include <SIM800.h>

SIM800 GSM(2,3);    //To initialize GSM at PIN2(RX) and PIN3(TX)

void setup() 
{
  Serial.begin(9600);
  GSM.init();
}

void loop() 
{
  String sms=GSM.read();
  
  if(sms!="")
	Serial.println(sms);
}