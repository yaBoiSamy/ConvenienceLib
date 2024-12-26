#ifndef LCD_h
#define LCD_h
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class LCD {
  public:
    LCD(String labels[], float* values[], int labelcount); 
    void begin();
    void update();
    void next();
    void previous();
    void view(int i);
    void view();
    void view(String labelname);
  
  private:
    Adafruit_SSD1306 display;
    void overflowPrint(String input, int maxlen);
    String labels[6];
    float* valueRefs[6];
    int labelcount;
    int carrouselIndex;
};

#endif