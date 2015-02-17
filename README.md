# homemadehawking
An Arduino-based speech synthesizer just like Stephen Hawking.

See it in action at : http://youtu.be/1eSkpLIrBUQ

## Components

* Arduino
* Shift register - 74HC595
* Narrator - SPO256
* Wires. Lots of wires.

## Notes

You can probably do without the shift register if you use all the analog pins as digital outputs.

You can also save pins by handling the reset and clock via discrete components, instead of letting the Arduino do so from its software.

## Credits

All code and hacking by Steven Goodwin, except where noted.

The SPO256 code is a refactor from this excellent piece of work:

   http://nsd.dyndns.org/speech/
