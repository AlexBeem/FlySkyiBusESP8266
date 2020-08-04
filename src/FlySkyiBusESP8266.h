/*
	FlySkyiBus Decoder Library fot the ESP8266

    Source code: https://github.com/Dave4675/FlySkyiBusESP8266

    Edited 03-08-2020
    By Dave4675

*/


#ifndef Arduino
#include  "Arduino.h"
#endif

#ifndef SoftwareSerial
#include "SoftwareSerial.h"
#endif

class FlySkyiBusESP8266{
    
private:
    bool isRSSISet = false;
    uint8_t RSSIChannel = 0;
    uint8_t CHANNEL_SIZE = 10;
    uint16_t data[10];
    uint8_t frequency = 50;
    uint16_t offset = 1500;
    uint16_t switchOffset = 1200;
    unsigned long int frequencyInUs = 1000000 / frequency;
    unsigned long int precRead = 0;
    SoftwareSerial swSer; //Needed for the ESP8266
    void set_data(uint8_t*);
    bool frame_validation(uint8_t*);

public:
    FlySkyiBusESP8266(uint8_t rx, uint8_t tx){
        swSer.begin(115200, SWSERIAL_8N1, rx, tx, false, 256);
    };

    void read_serial(void);
    uint16_t get_channel(uint8_t);

    uint16_t readChannel(uint8_t);
    int readOffsetChannel(uint8_t);
    bool readSwitchChannel(uint8_t);

    void setChannelSize(uint8_t);
    uint8_t getChannelSize();

    void setFrequency(uint8_t);
    uint8_t getFrequency();
    long unsigned int getFrequencyUs();

    void setOffset(uint16_t);
    uint16_t getOffset();
    void setSwitchOffset(uint16_t);
    uint16_t getSwitchOffset();

    bool readyToRead();
    bool isReceiverConnected();

    void setRSSIChannel(uint8_t);
    int getRSSI();
    String getRSSIAsString();
};
