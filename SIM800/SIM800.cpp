/*
  Rfid.h - Rfid library for Reading RFID Cards
  Copyright (c) 2016 Positron Technologies.  All right reserved.
*/

// include this library's description file
#include "SIM800.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

SIM800::SIM800(int rx,int tx):GSM(rx,tx)
{
  // initialize this instance's variables
  //this->pin = pin;
  GSM.begin(9600);
  //Serial.begin(9600);
  GSM.setTimeout(200);  
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

String SIM800::read(void)
{
	unsigned long t_start,t_stop=0;
	String str="";
	
	t_start=millis();
	
	while(t_stop<6000)
	{
		char c=GSM.read();
		
		if(c>31) str=str+c;
			
		if(c==10) break;
		
		t_stop=millis()-t_start;
	}	

	//Serial.println(str);
	return str;
}

bool SIM800::sendAtCmd(String cmd)
{
	GSM.println(cmd);
	//Serial.println(cmd);
	String str=read();
	
	return !(cmd.equals("ERROR"));
}

String SIM800::sendAtCmdRes(String cmd)
{
	GSM.println(cmd);
	return this->read();
}

bool SIM800::call(String num)
{
	clear();
	
	String cmd="ATD "+num+';';
	return this->sendAtCmd(cmd);
/*	
	while(success)
	{
		String str=read();
		
		if(str.equalsIgnoreCase("NO CARRIER")) break;
		
	}
	*/
}

void SIM800::call(byte res)
{
	if(res==ANSWER)
		GSM.println("ATA");
		
	if(res==REJECT)
		GSM.println("ATH");
	
}

bool SIM800::sms(String num,String msg)
{
	clear();
	
	String cmd="AT+CMGS=\""+num+"\"";
	//clear();
	GSM.println(cmd);
	char resp;
	
	while(1)
	{
		resp=GSM.read();
		
		if(resp=='>') break;
	}
	
	char ctrl_z=26;
	
	msg=msg+ctrl_z;
	
	return this->sendAtCmd(msg);
}

String SIM800::monitor()
{	
	String msg;
	event=NONE;
	
	if(GSM.available()>0)
	{
		msg=read();
		
		int pos=msg.indexOf("+CMT:");		//Check if received data is SMS
		int end;
		
		if(pos>=0)
		{
			event=SMS;						//SMS Received
			
			pos=msg.indexOf("\"");
			pos++;
			end=msg.indexOf("\"",pos);
			//end--;
			source=msg.substring(pos,end);
			
			return read();
		}
		
		pos=msg.indexOf("+CLIP:");		//Check if received data is SMS
		
		if(pos>=0)
		{
			event=CALL;
			
			pos=msg.indexOf("\"");
			pos++;
			end=msg.indexOf("\"",pos);
			//end--;
			source=msg.substring(pos,end);
			source="+"+source;
			
			return "";
			
		}
		
		pos=msg.indexOf("+DTMF:");		//Check if received data is SMS
		
		if(pos>=0)
		{
			event=DTMF;
			
			pos=msg.indexOf(":");
			pos=pos+2;
			end=pos+1;
			return msg.substring(pos,end);
			
		}
			
	}
	
	return "";
}

bool SIM800::dataSend(String url,String data)
{
	clear();
	
}

void SIM800::clear()
{
	while(GSM.read()>0);
}

void SIM800::init(void)
{
	bool success=sendAtCmd("AT");
	success=sendAtCmd("AT");
	delay(10000);
	clear();
	success=sendAtCmd("ATE0");
	success=sendAtCmd("AT+CMGF=1");
	success=sendAtCmd("AT+CSCS=\"GSM\"");
	success=sendAtCmd("AT+CNMI=2,2,0,0,0");
	success=sendAtCmd("AT+DDET=1");
	success=sendAtCmd("AT+CLIP=1");
	success=sendAtCmd("AT&W");
}

