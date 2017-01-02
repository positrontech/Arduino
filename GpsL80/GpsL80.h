/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Rfid_h
#define Rfid_h

// include types & constants of Wiring core API
#include "arduino.h"
#include<ReceiveOnlySoftwareSerial.h>

// library interface description
class Rfid
{
  // user-accessible "public" interface
  public:
    Rfid(int);
    String read(void);
	bool cmp(String,String);

  // library-accessible "private" interface
  private:
    //byte init;
	byte pin;
	ReceiveOnlySoftwareSerial RFID;
};

#endif

