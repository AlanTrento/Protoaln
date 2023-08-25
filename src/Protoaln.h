#ifndef PROTOALN_H
#define PROTOALN_H

#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "Protoaln_v.h"

class Protoaln {
  private:
   
    int16_t checksumSend(int16_t mensageReceived[maxVariables]);
    void convertToASCII(int16_t input[maxSizeMessage], int inputSize, int16_t output[maxVariables+1], int outputSize);
  
  public:
    void sendSerial( int16_t mensageReceived[maxSizeMessage]);   
    void getVariablesSerial( int16_t variablesReceived[maxVariables]); 
};

#endif
