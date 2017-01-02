#include <SoftwareSerial.h>
#include <SIM800.h>

SIM800 GSM(2,3);    //To initialize GSM at PIN2(RX) and PIN3(TX)

void setup() 
{
  GSM.init();
}

void loop() 
{
  bool success=GSM.sms("8890154444","Test SMS");
	
  delay(5000);
	
  if(success==true)
  {
    while(1);
  }
}