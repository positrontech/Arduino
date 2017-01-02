/*
  SIM800.h - Library for GSM Working
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef SIM800_h
#define SIM800_h

// include types & constants of Wiring core API
#include "arduino.h"
#include<SoftwareSerial.h>

// library interface description
class SIM800
{
  // user-accessible "public" interface
  public:
    SIM800(int,int);					//Constructor
	//~SIM800();							//Destructor
	void init(void);
    bool sendAtCmd(String);			//Send AT Command to GSM without returning Response
	String sendAtCmdRes(String);	//Send AT Command to GSM and return the Response for same
	String read();					//Read data from GSM Serial
	void call(byte);
	bool call(String);				//Call to a desired Number provided as Argument
	bool sms(String,String);		//Send SMS to Desired Number(ARG1) with the SMS Content in ARG2
	String monitor();				//Read SMS received
	bool dataSend(String,String);	//Send data to URL(ARG1) and data to be sent as ARG2
	void clear();

	String source;
	
	byte event;						//event=0 => Nothing
									//event=1 => Call
									//event=2 => SMS
									//event=3 => DTMF
									
	const byte CALL=1;
	const byte SMS=2;
	const byte DTMF=3;
	const byte NONE=0;
	const byte ANSWER=1;
	const byte REJECT=2;
	const byte DIAL=3;

  // library-accessible "private" interface
  private:
	SoftwareSerial GSM;	//Software Serial for GSM
	bool busy;	
};

#endif

