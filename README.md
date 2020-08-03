# FlySky iBus Decoder Library for the ESP8266
This librarry allows to decode the iBus protocol for the ESP8266

Default library supported cannels is 10.

## Usage

Open the example from your arduino enviroment after you have copied this library into your arduino library folder
There are two example sketch that show most of the functions that this library can offer.

What has this library more than the one that was forked from?
First of all:
This library is specifically designed to work with the ESP8266
Second:
Channel size is easely changeble by calling a function
Third:
You can set a global offset and a switch offset, see the iBus example
Fourth:
You can set a RSSI channel and get it as a value from 0 to 100, even as int or string
and finally:
You can know when the receiver is connected and receiveing data, you can use that to manage the failsafe, for example

Why I did this library?
I'm going to use this library for a future project that involves the ESP8266

