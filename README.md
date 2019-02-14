# MIDI-Lighting-Keyboard

I want to make MIDI input LED Lighting Keyboard

[![Watch the video](https://img.youtube.com/vi/wxcFKcL9LIE/maxresdefault.jpg)](https://youtu.be/wxcFKcL9LIE)
https://www.youtube.com/watch?v=wxcFKcL9LIE


# Hardware.
Arduino Uno + NeoPix(WS2812) 128pcs

## Hardware Connection.
 PC USB --> Arduino Uno --> 470 Ohm --> Neopix

# Software.

Loop MIDI 
(https://www.tobias-erichsen.de/software/loopmidi.html)

Hair LessMIDI
https://projectgus.github.io/hairless-midiserial/


# Arduino library
FortySevenEffects/arduino_midi_library
https://github.com/FortySevenEffects

adafruit/Adafruit_NeoPixel
https://github.com/adafruit/Adafruit_NeoPixel


# Software Setting.
1. Loop MIDI (for Windows.)
  "+" to create new port.

2. Hairless MIDI<-> Serial Bridge

   setting at File -> Preferences ->  "38400bps"
 
   "MIDI In"  set "loopMIDI Port" 
 
   "Serial Port " set "Arduino Uno (COM*)"

# Program with Arduino IDE 
if you Program Arduino, Loop midi "Serial <-> MIDI Bridge " turn OFF!!!



# Problem 
1. timing Little delay?

2. After  Lighting.
"Note Off" and "Volocity 0"  //That ch note LED OFF.
and "ControlChange"　120 is All sound Off //121 Reset All controller // 123 All Note Off  : All LED OFF

but Still Light LED there...
