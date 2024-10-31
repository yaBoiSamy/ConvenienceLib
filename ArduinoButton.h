#ifndef ArduinoButton_h
#define ArduinoButton_h

#include "Arduino.h"

class ArduinoButton {
  public:
    ArduinoButton(int pin);
    bool read();
    static int debounceDelay;

  private:
    int pin;

    bool state;
    bool isBouncing;

    int lastStateChange;
};


#endif