/* -----------------------------------------------------------------------------
[MIDI Lighting Keyboard Project.]
Kotohiro Masdua. 2019/2/14
source code from MIDI library example : Input.ino
source code from Aidafruit NeoPix library example : simple.ino
-----------------------------------------------------------------------------*/


#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
// -----------------------------------------------------------------------------
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 144
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

int delayval = 2; // delay for test

// -----------------------------------------------------------------------------

#define LED 13                   // LED pin on Arduino Uno

// -----------------------------------------------------------------------------
// LED Blink control. 

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  if (velocity == 0) {  // 　Note ON "Velocity = 0" is NOTE Off.
    leds[pitch].setRGB( 0, 0, 0);
    FastLED.show();
  } else {
    switch (channel) {  //  Select Ch       //　Blink velocity power!
      case 1:
        leds[pitch] = 0x008000;
        break;
      case 2:
        leds[pitch] = 0x0000FF;
        break;
      case 3:
        leds[pitch] = 0xFF0000;
        break;
      case 4:
        leds[pitch] = 0xFFFF00;
        break;
      case 5:
        leds[pitch] = 0xFFA500;
        break;
      case 6:
        leds[pitch] = 0xFF00FF;
        break;
      case 7:
        leds[pitch] = 0x00BFFF;
        break;
      case 8:
        leds[pitch] = 0xFFE4E1;
        break; 
      case 9:
        leds[pitch] = 0xADFF2F;
        break;
      case 10:
        leds[pitch] = 0x00008B;
        break;
      case 11:
        leds[pitch] = 0x00FFFF;
        break;
      case 12:
        leds[pitch] = 0xF08080;
        break;
      case 13:
        leds[pitch] = 0x800080;
        break;
      case 14:
        leds[pitch] = 0xB22222;
        break;
      case 15:
        leds[pitch] = 0x00BFFF;
        break;
      case 16:
        leds[pitch] = 0xF5F5F5;
        break;        
    }
    FastLED.show();
  }
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  switch (channel) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
      leds[pitch].setRGB( 0, 0, 0);
      FastLED.show();
  }
}

void handleControlChange(byte channel , byte number , byte value )
{

  //120 is All sound Off //121 Reset All controller // 123 All Note Off  : All LED OFF
  
  if (120 == number||121 == number||123 == number) {
    for(int i=0;i<NUM_LEDS;i++){
      leds[i].setRGB( 0, 0, 0);
      }
   } 
  FastLED.show();  
}


// -----------------------------------------------------------------------------

void setup()
{
    pinMode(LED, OUTPUT);

    // -----------------------------------------------------------------------------
    // UsehandleNoteOn Handler with MIDI Library ,after NoteOn Call Back Handler
    MIDI.setHandleNoteOn(handleNoteOn);  //argument is Handler [function].

    // Use NoteOff Handler
    MIDI.setHandleNoteOff(handleNoteOff);

    // Use ControlChange Handler
    MIDI.setHandleControlChange(handleControlChange);

    // All Ch read with MIDI instance initialize.
    MIDI.begin(MIDI_CHANNEL_OMNI);
    //Serial.begin(38400); //for Hairless MIDI software <-> Serial Bridge
    // -----------------------------------------------------------------------------

    
    //LED test All On! after OFF
    // -----------------------------------------------------------------------------
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    
    for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot].setRGB( 20, 0, 0);
            FastLED.show();
            // clear this led for the next time around the loop
            delay(delayval); // Delay for a period of time (in milliseconds).
            }

    for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot].setRGB( 0, 20, 0);
            FastLED.show();
            // clear this led for the next time around the loop
            delay(delayval); // Delay for a period of time (in milliseconds).
            }
               
    for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot].setRGB( 0, 0, 20);
            FastLED.show();
            // clear this led for the next time around the loop
            delay(delayval); // Delay for a period of time (in milliseconds).
            }
            
    for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot].setRGB( 0, 0, 0);
            FastLED.show();
            // clear this led for the next time around the loop
            delay(delayval); // Delay for a period of time (in milliseconds).
            }

}


void loop()
{
    MIDI.read();    
}
