#include <SoftwareSerial.h>

#ifndef Soundgin_H
  #define Soundgin_H
  #include <Arduino.h>

  class Soundgin {
    private:
      int CTS;      // Pin used for CTS input.

    public:
      Soundgin();
      void Setup(int a, int b, int c, int d);
      void writeByte(byte a);
      void writeArray(byte a[], int b);
      void ShutUp();
      void SayHello();   
      void Demo();
  };

  // Soundgin Phonemes from the Soundgin datasheet.
  // We need this enum for when we want to refer to the phonemes by their
  // "name". See "SayHello()" for an example.
  enum eSoundPreset {
      PH_A    = 192,          // Hat, Fast, Fan
      PH_AA   = 193,          // Father, Fall
      PH_AE   = 194,          // Gate, Ate, Ray
      PH_AIR  = 195,          // Hair, Stair, Repair
      PH_AU   = 196,          // Hot, Clock, Fox
      PH_BE   = 197,          // Bear, Bird, Beed
      PH_BO   = 198,          // Bone, Book Brown
      PH_EB   = 199,          // Cab, Crib, Web
      PH_OB   = 200,          // Bob, Sub, Tub
      PH_CH   = 201,          // Church, Feature, March
      PH_DE   = 202,          // Deep, Date, Divide
      PH_DO   = 203,          // Do, Dust, Dog
      PH_ED   = 204,          // Could, Bird
      PH_OD   = 205,          // Bud, Food
      PH_E    = 206,          // Met, Check, Red
      PH_EE   = 207,          // See, Even, Feed
      PH_ER   = 208,          // Fir, Bird, Burn
      PH_F    = 209,          // Food, Effort, Off
      PH_GE   = 210,          // Get, Gate, Guest,
      PH_GO   = 211,          // Got, Glue, Goo
      PH_HE   = 212,          // Help, Hand, Hair
      PH_HO   = 213,          // Hoe, Hot, Hug
      PH_I    = 214,          // Sit, Fix, Pin
      PH_IE   = 215,          // Mice, Fight, White
      PH_J    = 216,          // Dodge, Jet, Savage
      PH_KE   = 217,          // Can't, Clown, Key
      PH_KO   = 218,          // Comb, Quick, Fox
      PH_EK   = 219,          // Speak, Task
      PH_OK   = 220,          // Book, Took, October
      PH_LE   = 221,          // Lake, Alarm, Lapel
      PH_LO   = 222,          // Clock, Plus, Hello
      PH_M    = 223,          // Milk, Famous, Broom
      PH_NE   = 224,          // Nip, Danger, Thin
      PH_NO   = 225,          // No, Snow, On
      PH_NGE  = 226,          // Think, Ping
      PH_NGO  = 227,          // Hung, Song
      PH_OE   = 228,          // Go, Hello, Snow
      PH_OI   = 229,          // Boy, Toy, Voice
      PH_OO   = 230,          // Book, Could, Should
      PH_OU   = 231,          // Our, Ouch, Owl
      PH_OR   = 232,          // Corn, Four, Your
      PH_PE   = 233,          // People, Computer
      PH_PO   = 234,          // Pow, Copy
      PH_R    = 235,          // Ray, Brain, Over
      PH_SE   = 236,          // See, Vest, Plus
      PH_SO   = 237,          // So, Sweat
      PH_SH   = 238,          // Ship, Fiction, Leash
      PH_T    = 239,          // Part, Little, Sit
      PH_TH   = 240,          // Thin, month
      PH_THH  = 241,          // There, That, This
      PH_TS   = 242,          // Parts, Costs, Robots
      PH_U    = 243,          // Luck, Jump, Plus
      PH_UE   = 244,          // Food, June
      PH_V    = 245,          // Vest, Even, Twelve
      PH_W    = 246,          // Wool, Sweat
      PH_Y    = 247,          // Yes, Yarn, Million
      PH_Z    = 248,          // Zoo, Zap
      PH_ZH   = 249,          // Azure, Treasure
      PH_PA0  = 250,          // (pause 0)
      PH_PA1  = 251,          // (pause 1)
      PH_PA2  = 252,          // (pause 2)
      PH_FD0  = 253,          // (different pause?)
      PH_FD1  = 254,          // (different pause?)
      PH_FD2  = 255           // (different pause?)
  };
#endif
