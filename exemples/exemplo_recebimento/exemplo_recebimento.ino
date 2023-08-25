
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
