/*
  SIM800.h - Library for GSM Working
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef GPRSSIM800_h
#define GPRSSIM800_h

// include types & constants of Wiring core API
#include "arduino.h"
#include<SoftwareSerial.h>
#inclde<SIM800.h>
#include <Ethernet.h>

// library interface description
class GprsSim800 : public SIM800
{
  // user-accessible "public" interface
  public:
    GprsSim800(int,int);					//Constructor
	//~SIM800();							//Destructor
	void init(String);
	bool gprs(bool);
	bool http(bool);
	bool tcp(bool);
	bool send(byte,String,String);				//For HTTP(URL, Data String)
	bool send(byte,String,String,String);		//For TCP(IP, PORT, Data)
	
	bool tcpInit=false;
	bool httpInit=false;
	bool gprsInit=false;
	
	const bool CONNECT=true;
	const bool DISCONNECT=false;
	const bool CONNECTED=true;
	const bool DISCONNECTED=false;
	const bool SENT=true;
	const bool FAILED=false;
	
	const byte TCP=1;
	const byte HTTP=2;
	//const byte EMAIL=3;	

  // library-accessible "private" interface
  private:
	IPAddress strToIp(String);
	
};

#endif

