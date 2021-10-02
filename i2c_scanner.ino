// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011

#include <Wire.h>

void setup() {
  Serial.begin (9600);

  // Leonardo: wait for serial port to connect
  while (!Serial)
    {
    }

  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
 
  Wire.begin();
  Serial.println ("wire.begin");
  for (byte i = 1; i < 127; ++i)
  {
    Serial.print ("i = ");
    Serial.println (i);    
    //Serial.println ("for loop");
    Wire.beginTransmission (i);
    Serial.println ("begin Transmission");
    //delay(6.35);
    if (Wire.endTransmission () == 0)
      {
      Serial.println ("endTransmission");
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      //Serial.println ("for loop");
      delay (15);  // maybe unneeded?
      } // end of good response
     //Serial.println ("after IF == 1");
    if (Wire.endTransmission () == 1)
    {
     Serial.println ("1:data too long to fit in transmit buffer");
   
      }
    if (Wire.endTransmission () == 2)
    {
      //Serial.println ("2:received NACK on transmit of address");
      //Serial.println ("..");

      }
    if (Wire.endTransmission () == 3)
    {
      Serial.println ("3:received NACK on transmit of data");
 
      }
     if (Wire.endTransmission () == 4)
    {
      Serial.println ("4:other error");
      }     
  } // end of for loop
  Serial.println ("Done.");
  Serial.println ("Found ");
  Serial.println (count, DEC);
  Serial.println (" device(s).");
}  // end of setup

void loop() {}
