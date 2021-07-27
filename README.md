# auto-fan
I have had trouble implementing version control from Mbed studio, so I have had to manually drag the files over. 

This is a project I am working on as part of my Technical Project course - I call it, the AutoFanometer. The original idea was to have a 5V DC fan triggered by a hardcoded temp
reading from the DHT22 sensor. That files I have uploaded demostrate this functionality. But I've since revised my idea so that a user is able to select a temperature that works for them at runtime. I figured there wouldn't be much point to automating fan control if a user is forced to operate the device at a preset temperature. So to incorporate the new functionality I'll be adding a keypad input to the FRDM-K64F microcontroller which will enable a user to select a temperature in celcius that should turn on the fan when exceeded, and turn it off when once the room cools before that temp level is reached.  
