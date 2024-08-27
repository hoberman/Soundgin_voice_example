# Soundgin_voice_example
 
This is demo code for the allophone/phoneme-based voice synthesis function of the
SSG01 Sound Coprocessor (aka "Soundgin") from Savage Innovations, LLC. Visit:

  htps://speechchips.com

for more information on this chip, which is available from the seller's associated
store on eBay.

This code is written to work with a Soundgin Tester Board mounted on an Arduino Uno.
Communications with the Soundgin are over a serial interface at 9600 baud. Because the
Uno doesn't have a second hardware serial interface, serial port software emulation is
used. It's left to the reader to adapt the tester board (or maybe just the raw chip!)
and software to different hardware, but it shouldn't be that difficult.

Note that this code is for the original Soundgin, not the newer SoundginZ, which uses I2C
for its communications.