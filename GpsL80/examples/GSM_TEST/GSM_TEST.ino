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
  String sms=GSM.monitor();
  
  if(GSM.event==GSM.SMS)
  {
    Serial.print("SMS From ");
    Serial.println(GSM.source);
    Serial.println(sms);
  }
    
  if(GSM.event==GSM.CALL)
  {
    Serial.print("Call ");
    Serial.println(GSM.source);
    GSM.call(GSM.ANSWER);
  }
  
  if(GSM.event==GSM.DTMF)
  {
    Serial.print("DTMF ");
    Serial.println(sms);
  }
    
}