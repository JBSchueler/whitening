#include <Whitening.h>
#include <Arduino.h>

char *datastr    = "Hello World!\0";
char dataarr[13] = { 'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println( F("Test\toriginal\twhitened\tdewhitened") );

  Serial.print( F("String\t") );
  Serial.print( datastr );
  Serial.print( F("\t") );
  ComputeWhitening( datastr, 12 );
  Serial.print( datastr );
  Serial.print( F("\t") );
  ComputeWhitening( datastr, 12 );
  Serial.print( datastr );

  Serial.println();

  Serial.print( F("Array\t") );
  Serial.print( dataarr );
  Serial.print( F("\t") );
  ComputeWhitening( dataarr, 12 );
  Serial.print( dataarr );
  Serial.print( F("\t") );
  ComputeWhitening( dataarr, 12 );
  Serial.print( dataarr );

  Serial.println();

  while(1){;}
}
