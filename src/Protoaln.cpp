#include <Protoaln.h>
#include "Protoaln_v.h"


void Protoaln::convertToASCII(int16_t input[maxSizeMessage], int inputSize, int16_t output[maxVariables+1], int outputSize) {
  int outputIndex = 0;
  int16_t currentNumber = 0;
  bool negative = false;
  int i = 0; 

  while (i < inputSize && input[i] != 64) {
    if (input[i] == 44) { 
      if (negative) {
        currentNumber = -currentNumber;
        negative = false;
      }
      output[outputIndex++] = currentNumber;
      currentNumber = 0;
    } else if (input[i] == 45) {  
      negative = true;
    } else {
      currentNumber = currentNumber * 10 + (input[i] - '0');
    }
    i++;
  }

  if (negative) {
    currentNumber = -currentNumber;
  }

  output[outputIndex] = currentNumber;
}


int16_t Protoaln::checksumSend( int16_t mensageReceived[maxVariables]) 
{      
  int16_t checksum = 0;
    for (int i = 0; i < maxVariables; i++) {
      checksum = checksum+mensageReceived[i];
    }
    int16_t checksumResult= checksum+6;
    return checksumResult;
}

void Protoaln::sendSerial( int16_t mensageReceived[maxVariables]) 
{    
    Serial.print ('#');
    for (int i = 0; i < maxVariables; i++) {
      Serial.print (mensageReceived[i]);
      Serial.print (',');
    }

    int16_t variableCheck = checksumSend( mensageReceived); 
    Serial.print (variableCheck);
    Serial.print ('@');
}

void Protoaln::getVariablesSerial( int16_t variablesReceived[maxVariables]) 
{
  int16_t mensageReceived[maxSizeMessage];
  int16_t vetor[maxVariables+1];
  int16_t readSerial = 0;
  int variableMaxReal=0;
  if (Serial.available())
  {
  
    readSerial = Serial.read();
  
    if (readSerial == '#')
    {
      int i = 0;
      
      while (readSerial != '@')
      {
        readSerial= Serial.read();
        mensageReceived[i] = readSerial; 
        i++;
        variableMaxReal=i;
        
        if (i == maxSizeMessage-1)
        {
          readSerial='@';
        }
      }  

      convertToASCII(mensageReceived, maxSizeMessage, vetor, maxVariables+1);
      
      if (checksumSend(vetor )==vetor[maxVariables])
      {
        
        for(int i=0; i<7;i++)
        {
          variablesReceived[i]=vetor[i];
        }
      }
    }
  }
}

