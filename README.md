# MIDI-Lighting-Keyboard

I want to make MIDI input LED Lighting Keyboard

[![Watch the video](https://img.youtube.com/vi/wxcFKcL9LIE/maxresdefault.jpg)](https://youtu.be/wxcFKcL9LIE)
https://www.youtube.com/watch?v=wxcFKcL9LIE


# Hardware.
Arduino Uno + NeoPix(WS2812) 128pcs

# Hardware Connection.
 PC USB --> Arduino Uno --> 470 Ohm --> Neopix

# now Testing... Arduino MIDI <-> Serial Bridge
PATTERN1: LoopMIDI + HairLessMIDI  (because,windows CANNOT open "31250bps" MIDI speed.)
PATTERN2: Change Arduino USB-MIDI (Use "Moco Lufa(atmega16u2)")


# Software.

Loop MIDI 
(https://www.tobias-erichsen.de/software/loopmidi.html)

Hair LessMIDI
(https://projectgus.github.io/hairless-midiserial/)

Moco Lufa
https://github.com/kuwatay/mocolufa
Click "Raw" to Left Click and "save as a new file" 
https://github.com/kuwatay/mocolufa/blob/master/HEX/dualMoco.hex

Flip (for atmega16u2 flash)
https://www.microchip.com/developmenttools/ProductDetails/FLIP

# Arduino library
FortySevenEffects/arduino_midi_library
(https://github.com/FortySevenEffects)

adafruit/Adafruit_NeoPixel
(https://github.com/adafruit/Adafruit_NeoPixel)

Fast LED
https://github.com/FastLED/FastLED


# Software Setting.
1. Loop MIDI (for Windows.)  

    "+" to create new port.

2. Hairless MIDI<-> Serial Bridge

   setting at File -> Preferences ->  "38400bps"
 
   "MIDI In"  set "loopMIDI Port" 
 
   "Serial Port " set "Arduino Uno (COM*)"
   
 
# Program with Arduino IDE 
if you Program Arduino, Loop midi "Serial <-> MIDI Bridge " turn OFF!!!

# Arduino Uno -> USB-MIDI
Use "Moco Lufa".
If you Windows "Microchip FLIP"

If you Mac "dfu-programmer"
https://qiita.com/yasuraok/items/8ae995b7484e140b071f
https://sourceforge.net/projects/dfu-programmer/files/dfu-programmer/

1. USB Cable off Arduino Uno
2. ICSP 5-6 Short (atmega16u2 ,near USB connector)
3. USB Cable Set Arduino Uno
4. Flash "Flip" or "dfu-programmer"  <dualMoco.hex> at Atmega16U2
5. ICSP 5-6 Open
6. USB Cable Off-Set

7. ICSP 4-6 Short to USB Cable Set (Arduino mode)
8. ICSP 4-6 Open to USB Cable Set (MIDI-USB mode)

# Problem 
1. timing Little delay?

2. After  Lighting.
    "Note Off" and "Volocity 0"  //That ch note LED OFF.  

    and "ControlChange"  

    120 is All sound Off //121 Reset All controller // 123 All Note Off  : All LED OFF

    but Still Light LED there... Maybe, Serial or Handller Problem...

# reference
Arduino MIDI Library の使い方
https://qiita.com/yudai220/items/3bde9461f282d56d1ac2

DTM技術情報
https://www.g200kg.com/jp/docs/tech/midi.html

ＭＩＤＩ「超」入門(データ編)
http://magarchive.halfmoon.jp/nifty/midi/vvesymidi2.html

DTM・宅録で始める音楽ライフ。
http://takuroq.hatenablog.com/entry/2017/02/21/080000
