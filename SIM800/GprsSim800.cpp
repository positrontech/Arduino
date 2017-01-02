/*
  Rfid.h - Rfid library for Reading RFID Cards
  Copyright (c) 2016 Positron Technologies.  All right reserved.
*/

// include this library's description file
#include "SIM800.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

GprsSim800::GprsSim800(int rx,int tx):GSM(rx,tx)
{
  // initialize this instance's variables
  //this->pin = pin;
  GSM.begin(9600);
  //Serial.begin(9600);
  GSM.setTimeout(200);  
}

bool GprsSim800::dataSend(String url,String data)
{
	clear();
	
}

void GprsSim800::init(String apn)
{
	bool success=sendAtCmd("AT");
	success=sendAtCmd("AT");
	clear();
	success=sendAtCmd("AT+SAPBR=3,1,\"Contype\",\"GPRS\"");
	
	String cmd="AT+SAPBR=3,1,\"APN\",\""+apn+"\"";
	success=sendAtCmd(cmd);
	
	success=sendAtCmd("AT+SAPBR=1,1");
	success=sendAtCmd("AT+SAPBR=1,1");
	success=sendAtCmd("AT+DDET=1");
	success=sendAtCmd("AT+CLIP=1");
	success=sendAtCmd("AT&W");
}

