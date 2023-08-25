
#include "Protoaln.h"
/*####################################################################################################################################
To perform data transmission, it is mandatory to create a string of size 7 and fill the positions you will not use with zeros. It is 
possible to send up to 7 variables at once.
The library performs the checksum internally, ensuring the integrity of the messages.

****Warning****
For greater efficiency and control over message transmission and reception, interruptions should be managed and the microcontroller
should be put into sleep mode.
####################################################################################################################################*/

int16_t myVector[7] = {500,1, -1, -1000, -2, 200,0};
Protoaln p;

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  p.sendSerial(myVector);
  delay(1000);
}
