/*
  Rfid.h - Rfid library for Reading RFID Cards
  Copyright (c) 2016 Positron Technologies.  All right reserved.
*/

// include this library's description file
#include "Rfid.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

Rfid::Rfid(int pin):RFID(pin)
{
  // initialize this instance's variables
  //this->pin = pin;
  RFID.begin(9600);
  RFID.setTimeout(200);
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

String Rfid::read(void)
{
  return RFID.readStringUntil(13);
}

bool Rfid::cmp(String rfid1,String rfid2)
{
  return rfid1.equals(rfid2);
}

