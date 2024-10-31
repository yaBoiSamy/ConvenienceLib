#include "ArduinoButton.h"
#include "Arduino.h"

ArduinoButton::ArduinoButton(int _pin){
  pin = _pin;
  state = 0;
  pinMode(pin, OUTPUT);
}

bool ArduinoButton::read(){
  isBouncing = isBouncing && !(millis() - lastStateChange > debounceDelay); // Update isBouncing in case it's timer ran out

  if (!isBouncing){
    bool stateChanged = digitalRead(pin)!=state; 
    isBouncing = stateChanged; // if there is a state change, button is bouncing
    state = state ^ stateChanged; // refresh value of state in case of state change (Xor acts like triggerable NOT gate)
    lastStateChange = millis();
  }

  return state;
}

int ArduinoButton::debounceDelay = 40;