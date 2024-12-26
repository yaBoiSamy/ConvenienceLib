#ifndef Vector_h
#define Vector_h

#include "Arduino.h"

class Vect {
  public:
    // Constructor
    Vect(float x, float y, float z);

    // Getter methods
    float x() const;
    float y() const;
    float z() const;

    // Setter methods
    void setx(float num);
    void sety(float num);
    void setz(float num);

    // Other methods
    float dot(const Vect& other) const;
    Vect cross(const Vect& other) const;
    float norm() const;
    float angle(const Vect& other) const;
    Vect normalize() const;
    String str() const;

  private:
    float arr[3];  // Store x, y, z coordinates
};

#endif