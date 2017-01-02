#include <ReceiveOnlySoftwareSerial.h>
#include <Rfid.h>

Rfid RFID(2);    //To initialize RFID at PIN 2

void setup() 
{
  Serial.begin(9600);      	//Initialize Hardware Serial to check RFID Data
  pinMode(12,OUTPUT);	   	//Card Match LED
  pinMode(13,OUTPUT);		//Card Mismatch LED
  digitalWrite(12,LOW);		
  digitalWrite(13,LOW);
}

void loop() 
{
  String str=RFID.read();  //Read RFID Card
    
  if(str!="")	//If any Card is Read
  {
    if(RFID.cmp(str,"Write Your Card Number Here")==true)	//If Read Card Matches
    {
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      Serial.println("Match");
    }
    else
    {
      digitalWrite(12,LOW);
      digitalWrite(13,HIGH);
      Serial.println("Mis-Match");
    }
  }  
}