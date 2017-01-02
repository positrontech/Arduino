This is library for Reading RFID Cards using Arduino.

Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries/Positron folder.

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select Rfid.  This will add a corresponding line to the top of your sketch:
#include <Rfid.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "Rfid.o" will appear
in "Arduino/lib/targets/libraries/Positron/Rfid". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "Rfid.cpp" or "Rfid.h"),
then you must first 'unbuild' this library by deleting the "Test.o" file. The
new "Test.o" with your code will appear after the next press of "verify"


