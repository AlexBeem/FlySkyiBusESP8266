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
#
Откройте пример из среды arduino после того, как вы скопировали эту библиотеку в папку библиотеки arduino, есть два примера эскиза, 
которые показывают большинство функций, которые может предложить эта библиотека.

Что есть в этой библиотеке больше, чем та, из которой она была разветвлена? 
Во-первых: Эта библиотека специально разработана для работы с ESP8266 
Во-вторых: Размер канала легко изменить, вызвав функцию 
В-третьих: Вы можете установить глобальное смещение и смещение переключателя, см. Пример IBUS 
В-четвертых: Вы можете установить канал RSSI и получить его в качестве значения от 0 до 100, 
даже в виде int или строки и, наконец: 
Вы можете знать, когда приемник подключен и получает данные, вы можете использовать это для управления отказоустойчивостью,
например

Зачем я сделал эту библиотеку? Я собираюсь использовать эту библиотеку для будущего проекта, который включает ESP8266


