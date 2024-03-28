// The latest version of this code can be found at:
//
// https://github.com/hoberman/Soundgin_voice_example
//
//

#include "Soundgin.h"

Soundgin Soundgin;        // create a Soundgin object.

const int Pin_TX = A1;    // Soundgin's transmit line TO Arduino
const int Pin_RX = A2;    // Soundgin's receive line FROM Arduino

const int Pin_Reset = 13; // Reset. (Active LOW) HIGH = normal operation.
const int Pin_Demo = 11;  // Demo select. (Active LOW) HIGH = normal operation.
const int Pin_Baud = 12;  // Baud Rate select.  HIGH=9600 baud / LOW=2400 baud.
const int Pin_CTS = 2;    // Clear To Send - high from Soundgin means input buffer full (don't send)

#include <SoftwareSerial.h>
SoftwareSerial SerialPort(Pin_TX, Pin_RX); // Soundgin's TX, RX == Arduino's RX, TX  

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println();
  Serial.println("Reset.");
  Serial.println("Soundgin demo program");
  Serial.println();
  Serial.print("Source file: "); Serial.println(__FILE__);
  Serial.print(" Build time: "); Serial.println(__TIMESTAMP__);
  Serial.println();
  Serial.println();

  Soundgin.Setup(Pin_CTS, Pin_Baud, Pin_Demo, Pin_Reset);   // set up Soundgin I/O; initialize software serial to talk to it.
}

void loop() {
  Soundgin.SayHello();

  // Optional: SayHello() again, but with a different pitch. This uses a musical note as a base:
  delay(1000);
  Soundgin.writeByte(0x1b); Soundgin.writeByte(0x08);  // command sequence
  Soundgin.writeByte(0xc0);                            // specify the musical note
  Soundgin.SayHello();

  // Optional: We can also set the pitch using a frequency:
  delay(1000);
  Soundgin.writeByte(0x1b); Soundgin.writeByte(0x09);   // command sequence
  Soundgin.writeByte(0x40); Soundgin.writeByte(0x00);   // specify the frequency (MSB,LSB)
  Soundgin.SayHello();

  Soundgin.writeByte(0x1b); Soundgin.writeByte(0x0b);   // reset voice to default
  
  // optional: speak all the built-in phonemes.
  delay(1000);
  Soundgin.Demo();

  // optional: loop forever so we only do the speech once.
  while (true) { delay(1000); }

  delay(2000);
}

