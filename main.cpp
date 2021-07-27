#include "mbed.h"
#include "DHT.h"
#include "ssd1306.h"
#include <cstdio>

#define I2C_SDA PTE25  // I2C data pin.
#define I2C_SCL PTE24  // I2C clock pin.
#define DHT_PIN PTC16  // connects to data pin of dht22.

SSD1306 oled (I2C_SDA, I2C_SCL);  // init oled display object with I2C pin names. 

#define DELAY 5000ms  // delay for dht temperature readings.
DHT dht(DHT_PIN, DHT::DHT22);  // init dht22 with pin defined above.

void OLEDInitialise(){
    ThisThread::sleep_for(1000ms);
    oled.cls();
    oled.display();
}  // function to clear oled display.

int main(void) {
    float temp;  // variable for dht22 temp readings. 
    float humidity;  // variable for dht22 humidity readings.
    oled.speed (SSD1306::Medium);  // set working frequency.
    oled.init();  // init oled display object.
    OLEDInitialise();  // clear and reset oled screen.
    while(1) {
        ThisThread::sleep_for(DELAY);  // sleep for 5 seconds before next temp and humidity readings.
        int err = dht.read();  // function that attempts to read temp and humidity from dht22.
        OLEDInitialise();  // clear screen to prepare display for next set of readings.
        if (err == DHT::SUCCESS) {  // block to execute if dht.read() is successful
            temp = dht.getTemperature(DHT::CELCIUS);  // save temperature reading to 'temp' variable in celsius.
            humidity = dht.getHumidity();  // save humidity reading to 'humidity' variable.
            oled.locate(2,1);  // indicate where on oled screen to data.
            oled.printf("T = %.1f C", temp);  // write temp reading to oled display.
            oled.locate(4,1);
            oled.printf("H = %.1f rh", humidity);  // write humidity reading to oled display.
            oled.redraw();  // finalize writing to display.
            printf("T = %.1f°C\r\n", temp);  // write readings to console as well.
            printf("H = %.1f rh\r\n", humidity);
            if (temp < 25.0)
            {
                sleep();
            }  // put system to sleep (i.e. turn fan off) until temp reading exceeds 25°C.
        } else {  // show error message if dht.read() is unsuccessful. 
            printf("Error code : %d\r\n", err);
        }
    }
}


