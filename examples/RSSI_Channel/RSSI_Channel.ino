#include "FlySkyiBusESP8266.h"

FlySkyiBusESP8266 iBus(D7,D8); //rx and tx pins set to 115200

int RSSIChannel = 14; //Channel 14 as RSSI channel

/*
  Read carefully;
  Most of the fly-sky receiver don't send a RSSI value
  the only way to perform that is to update the firmware,
  then on the channel that the firmware is configured for
  will be used to transmit the RSSI value
*/

void setup() {
  Serial.begin(115200);
  iBus.setRSSIChannel(RSSIChannel);// Set the channel for the RSSI, if you don't do that you will not be able to get the RSSI
  iBus.setChannelSize(14);// set channel size, because the default library reads only 10 channels
}

void loop() {
   if(iBus.readyToRead()){// It becames ready at the default frequency that is 50Hz, also i want to print at 50hz
      if(!iBus.isReceiverConnected()){ //This works both for when the transmitter is correctly binded and transmitting
        Serial.println("Receiver not connected");
        return;
      }
    Serial.println(iBus.getRSSIAsString());
  }
}
