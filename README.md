# MIDI-Lighting-Keyboard

i want to make MIDI input LED Lighting Keyboard


Arduino Uno + NeoPix(WS2812) 128pcs


1. Loop MIDI (for Windows.)
 "+" to Creat new port.

2. Hairless MIDI<-> Serial Bridge
 setting at 38400bps
 "MIDI In"  set "loopMIDI Port" 
 "Serial Port " set "Arduino Uno (COM*)"

if you Program Arduino, Loop midi "Serial <-> MIDI Bridge " OFF!


Problem 
1. timing Little delay?

2. After  Lighting.
"Note Off" and "Volocity 0"  //That ch note LED OFF.
and "ControlChange"　120 is All sound Off //121 Reset All controller // 123 All Note Off  : All LED OFF

but Still Light LED there...
