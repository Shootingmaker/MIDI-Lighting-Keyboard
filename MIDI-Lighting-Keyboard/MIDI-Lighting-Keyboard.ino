/* -----------------------------------------------------------------------------
[MIDI Lighting Keyboard Project.]
Kotohiro Masdua. 2019/2/14
source code from MIDI library example : Input.ino
source code from Aidafruit NeoPix library example : simple.ino

-----------------------------------------------------------------------------*/


#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
// -----------------------------------------------------------------------------

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      144
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 2; // delay for test

// -----------------------------------------------------------------------------

#define LED 13                   // LED pin on Arduino Uno

// -----------------------------------------------------------------------------
// LED Blink control. 

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  digitalWrite(LED,HIGH);        // LED pin on Arduino Uno Blink 
  if (velocity == 0) {  // 　Note ON "Velocity = 0" is NOTE Off.
    pixels.setPixelColor(pitch, pixels.Color(0,0,0));
    pixels.show(); 
  } else {
    switch (channel) {  //  Select Ch       //　Blink velocity power!
      case 1:
        pixels.setPixelColor(pitch, pixels.Color(0,velocity,0));
        break;
      case 2:
        pixels.setPixelColor(pitch, pixels.Color(0,0,velocity));
        break;
      case 3:
        pixels.setPixelColor(pitch, pixels.Color(velocity,0,0));
        break;
    }
    pixels.show(); 
  }
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  switch (channel) {
    case 1:
    case 2:
    case 3:
      pixels.setPixelColor(pitch, pixels.Color(0,0,0));
      pixels.show();
  }
  digitalWrite(LED,LOW);
}

void handleControlChange(byte channel , byte number , byte value )
{

  //120 is All sound Off //121 Reset All controller // 123 All Note Off  : All LED OFF
  
  if (120 == number||121 == number||123 == number) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
   } 
  pixels.show();
  digitalWrite(LED,LOW);
}


// -----------------------------------------------------------------------------

void setup()
{
    pinMode(LED, OUTPUT);
    
    // UsehandleNoteOn Handler with MIDI Library ,after NoteOn Call Back Handler
    MIDI.setHandleNoteOn(handleNoteOn);  //argument is Handler [function].

    // Use NoteOff Handler like as "Note On"
    MIDI.setHandleNoteOff(handleNoteOff);

    //
    MIDI.setHandleControlChange(handleControlChange);

    // All Ch read with MIDI instance initialize.
    MIDI.begin(MIDI_CHANNEL_OMNI);
    Serial.begin(38400); //for Hairless MIDI software <-> Serial Bridge

    //LED test All On! after OFF
    pixels.begin(); // This initializes the NeoPixel library.
    for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,10,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    }
    delay(10);
    for(int i=NUMPIXELS;i>0;i--){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    }
    
}

void loop()
{
    MIDI.read();    
}
