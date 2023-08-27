
/*To receive the messages, a string of int16 with 7 positions must be created, where up to 7 messages of 16 bytes each will be received.*/

#include "Protoaln.h"
Protoaln p;
int16_t mensageReceived [7];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  p.getVariablesSerial(mensageReceived);
  
  for(int i=0;i<7;i++){
    Serial.print("mensageReceived [");
    Serial.print(i);
    Serial.print("]=");
    Serial.print(mensageReceived[i]);
  }
  Serial.print("\n");
delay(1000);
}
