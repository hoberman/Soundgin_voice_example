#include "Soundgin.h"

#include <SoftwareSerial.h>
extern SoftwareSerial SerialPort;     // SerialPort object created in the top level program

// Constructor for new Soundgin object. Nothing to do here.
Soundgin::Soundgin() {
}

void Soundgin::Setup(int ClearToSendPin, int BaudPin, int DemoPin, int ResetPin) {
  // Set the Arduino's I/O lines
  pinMode(ResetPin, OUTPUT);       digitalWrite(ResetPin,LOW);    // Hold reset LOW while setting up lines

  CTS=ClearToSendPin;                                       // Copy CTS pin to a private variable to use it in writeByte().
  pinMode(CTS, INPUT);                                      // We'll see a HIGH from Soundgin when internal queue is > 50% full

  pinMode(DemoPin,OUTPUT); digitalWrite(DemoPin,HIGH);
  pinMode(BaudPin,OUTPUT); digitalWrite(BaudPin,HIGH);      // Always use 9600 baud.

  SerialPort.begin(9600);                                   // Always use 9600 baud.

  digitalWrite(ResetPin,HIGH);                              // Done with reset so set this HIGH
  delay(250);                                               // Need a short delay after reset or Soundgin loses some data.
}

// This writes a single byte out the software serial interface to the Soundgin.
void Soundgin::writeByte(byte byteToWrite) {
  // We can't just do a write() to the Soundgin because we're likely to overrun
  // the 16-byte internal speech queue. Instead, monitor the CTS line, which goes high when the
  // queue is half full. If we see the signal high, we'll wait until it goes low again (meaning
  // there's ample room in the queue for more data) before writing the next byte to the chip. We could
  // get a little fancier here and implement our own local sub-queue that writes a few bytes past
  // a CTS-went-high condition in order to keep the internal queue a bit more full, but so far
  // I haven't seen a need for that.

  while (digitalRead(CTS)==HIGH) {
    delay(20);   // 20-100 ms delay between checks works well enough.
  }
  SerialPort.write(byteToWrite);
}

// This takes an array of bytes and sends them to the Soundgin. We have to be given the
// count of bytes in the array because we can't use any specific value (like 0x00 in character
// strings) as a terminator.
void Soundgin::writeArray(byte byteArray[], int arraySize) {
  for (int i=0; i<arraySize; i++) {
    writeByte(byteArray[i]);
  }
}

// Send a hard pause to stop any voice output.
void Soundgin::ShutUp(){
  writeByte(PH_PA1);
}

// Send the set of known phonemes, pausing between each one.
void Soundgin::Demo() {
  for (int i=PH_A; i<=PH_Z; i++) {
    writeByte(i);
    writeByte(PH_PA0);
  }
  ShutUp();
}

void Soundgin::SayHello() {
  // Hello message.
  byte talkData[]={
    PH_HE, PH_E, PH_LO, PH_OE, PH_PA2,              // hello + pause
    PH_TH, PH_I, PH_SE,                             // this
    PH_I, PH_Z,                                     // is
    PH_Y, PH_UE, PH_R,                              // your
    PH_SO, PH_OU, PH_NO, PH_J, PH_I, PH_NE,         // Soundgin
    PH_T, PH_AA, PH_KE, PH_EE, PH_NGE,              // talking
  };
  int talkDataCount=sizeof(talkData)/sizeof(talkData[0]);   // Calculate the size of the talkData array.

  writeArray(talkData, talkDataCount);

  ShutUp();
}

