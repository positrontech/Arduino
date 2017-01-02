#include <ReceiveOnlySoftwareSerial.h>
#include <Rfid.h>

Rfid RFID(2);    //To initialize RFID at PIN 2
int RFID_OK=12;
int RFID_NOK=13;

void setup() 
{
  Serial.begin(9600);      	//Initialize Hardware Serial to check RFID Data
  pinMode(RFID_OK,OUTPUT);	   	//Card Match LED
  pinMode(RFID_NOK,OUTPUT);		//Card Mismatch LED
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
      digitalWrite(RFID_NOK,LOW);
      digitalWrite(RFID_OK,HIGH);
      Serial.println("Match");
    }
    else
    {
      digitalWrite(RFID_OK,LOW);
      digitalWrite(RFID_NOK,HIGH);
      Serial.println("Mis-Match");
    }
  }  
}
