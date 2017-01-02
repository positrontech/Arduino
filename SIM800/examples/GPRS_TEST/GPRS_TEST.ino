#include <SoftwareSerial.h>
#include <GprsSim800.h>

GprsSim800 GPRS(2,3);    //To initialize GSM at PIN2(RX) and PIN3(TX)

void setup() 
{
  Serial.begin(9600);
  GPRS.init("airtelgprs.com");
}

void loop() 
{
  bool success=GPRS.http(GPRS.CONNECT);    
  
  if(success==GPRS.CONNECTED)
  {
    Serial.print("IP = ");
    Serial.println(GPRS.IP);
    success=GPRS.send(GPRS.HTTP,"cnir.in/iot/recieve.php","pid=00001&lat=Car_ID");
    
    if(success==GPRS.SENT) Serial.println("Data Sent");
    
    if(success==GPRS.FAILED) Serial.println("Sending Failed");
    
    delay(20000);    
  }
}