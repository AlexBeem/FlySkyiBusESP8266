#include "FlySkyiBusESP8266.h"

FlySkyiBusESP8266 iBus(D7,D8); //rx and tx pins set to 115200

int channelSize;
int channel = 0;
int frequency;
int frequencyUs;
int offset;
int switchOffset;

void setup() {
  Serial.begin(115200);

  channelSize = iBus.getChannelSize();
  frequency = iBus.getFrequency();
  frequencyUs = iBus.getFrequencyUs();
  offset = iBus.getOffset();
  switchOffset = iBus.getSwitchOffset();
}

void loop() {
  /* this lines are an example for the forked library
  iBus.read_serial();
  Serial.println();
  for (int i = 0; i < 9; i++){ // Read channel as they are transmitted
    int channel = iBus.get_channel(i);
    Serial.print(" CH " + String(i + 1) + " " + String(channel));
  }
  */

   if(iBus.readyToRead()){// It becames ready at the default frequency that is 50Hz, also i want to print at 50hz
      if(!iBus.isReceiverConnected()){ //This works both for when the transmitter is correctly binded and transmitting
        Serial.println("Receiver not connected");
        return;
      }
      Serial.println();
      Serial.println("Channel Size " + String(channelSize));
      Serial.println("Frequency " + String(frequency));
      Serial.println("Frequency in us " + String(frequencyUs));
      Serial.println("Offset " + String(offset));
      Serial.println("Switch offset " + String(switchOffset));
      
    // Channel number [0-9]
      Serial.println();
      for (int i = 0; i < channelSize; i++){ // Read channel as they are transmitted
        channel = iBus.readChannel(i);
        Serial.print(" CH " + String(i + 1) + " " + String(channel));
      }
    
      Serial.println();
      for (int i = 0; i < channelSize; i++){ // Read channel with offset
        channel = iBus.readOffsetChannel(i);
        Serial.print(" CH " + String(i + 1) + " " + String(channel));
      }
    
      Serial.println();
      for (int i = 0; i < channelSize; i++){ // Read channel as switch
        bool ch = iBus.readSwitchChannel(i);
        Serial.print(" CH " + String(i + 1) + " " + ch);
      }
   }
}
