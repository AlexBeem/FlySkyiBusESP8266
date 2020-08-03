/*
	FlySkyiBus Decoder Library for the ESP8266

    Source code: https://github.com/Dave4675/FlySkyiBus/

    Edited 03-08-2020
    By Dave4675

*/

#ifndef FlySkyiBusESP8266
#include "FlySkyiBusESP8266.h"
#endif

void FlySkyiBusESP8266::read_serial(void) {

    if (swSer.available() >= 32) {
        if (swSer.read() == 0x20) { // Start bit of frame
            uint8_t buffer[32];
            buffer[0] = 0x20;

            uint8_t i;
            for (i=1; i<32; i++) {
                buffer[i] = swSer.read();
            }

            if (FlySkyiBusESP8266::frame_validation(buffer) == true) {
                FlySkyiBusESP8266::set_data(buffer);
                return;
            }
        }
        return read_serial();

    }
}

bool FlySkyiBusESP8266::frame_validation(uint8_t *buffer) {
    uint8_t i;
    uint16_t checksum = 0xFFFF;
    uint16_t rxChecksum = 0x0000;

    for (i=0; i<30; i++) {
        checksum -= buffer[i];
    }

    rxChecksum = buffer[30] + (buffer[31] << 8);

    if (rxChecksum == checksum) {
        return true;
    } else {
        return false;
    }
}

void FlySkyiBusESP8266::set_data(uint8_t *buffer) {

    uint8_t i;

    for (i=1; i<CHANNEL_SIZE+1; i++) {
        data[i-1] = buffer[i * 2] + (buffer[i * 2 + 1] << 8);
    }
}

uint16_t FlySkyiBusESP8266::readChannel(uint8_t channel) {
    read_serial();
    return data[channel];
}

uint16_t FlySkyiBusESP8266::get_channel(uint8_t channel) {
    return data[channel];
}

bool FlySkyiBusESP8266::readSwitchChannel(uint8_t channel){
    uint16_t value = readChannel(channel);

    if(value > switchOffset)
        return true;

    return false;
}

int FlySkyiBusESP8266::readOffsetChannel(uint8_t channel){
    uint16_t value = readChannel(channel);
    return value - offset;
}

void FlySkyiBusESP8266::setChannelSize(uint8_t channel){
    CHANNEL_SIZE = channel;
    int chSize = CHANNEL_SIZE;
    uint16_t newArray[chSize];
    *data = *newArray;
    read_serial();
}

uint8_t FlySkyiBusESP8266::getChannelSize(){
    return CHANNEL_SIZE;
}

void FlySkyiBusESP8266::setFrequency(uint8_t freq){
    frequency = freq;
    frequencyInUs = 1000000 / frequency;
}

uint8_t FlySkyiBusESP8266::getFrequency(){
    return frequency;
}

long unsigned int FlySkyiBusESP8266::getFrequencyUs(){
    return frequencyInUs;
}

void FlySkyiBusESP8266::setOffset(uint16_t off){
    offset = off;
}

uint16_t FlySkyiBusESP8266::getOffset(){
    return offset;
}

void FlySkyiBusESP8266::setSwitchOffset(uint16_t swOff){
    switchOffset = swOff;
}

uint16_t FlySkyiBusESP8266::getSwitchOffset(){
    return switchOffset;
}

bool FlySkyiBusESP8266::readyToRead(){
    unsigned long now = micros();
    if(now - precRead >= frequencyInUs){
        precRead = now;
        return true;
    }

    return false;
}

bool FlySkyiBusESP8266::isReceiverConnected(){
    int value = readChannel(0);
    if(value <= 1)
        return false;

    int channelSize = CHANNEL_SIZE;

    std::fill_n(data, channelSize, 0);

    return true;
}

void FlySkyiBusESP8266::setRSSIChannel(uint8_t channel){
    isRSSISet = true;
    RSSIChannel = channel - 1;
}

int FlySkyiBusESP8266::getRSSI(){
    if(!isRSSISet)
        return -1;

    int value = readChannel(RSSIChannel);
    if(value == 0)
        return -1;
    
    value -= 1000;
    return map(value, 0, 1000, 0, 100);
}

String  FlySkyiBusESP8266::getRSSIAsString(){
    if(!isRSSISet)
        return "RSSI Channel not configured, configure RSSI channel";
    int RSSI = getRSSI();
    return String(RSSI)+"%";
}
