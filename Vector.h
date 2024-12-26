#ifndef Vector_h
#define Vector_h

#include "Arduino.h"

class Vect {
  public:
    // Components
    float x; float y; float z;

    // Constructor
    Vect(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {};

    // Other methods
    float dot(const Vect& other) const;
    Vect cross(const Vect& other) const;
    float norm() const;
    float angle(const Vect& other) const;
    Vect normalize() const;
    String str() const;

    // Operator overloads
    float& operator[](int index);
    const float& operator[](int index) const;
    Vect operator+(const Vect& other) const;
    Vect operator-(const Vect& other) const;
    Vect& operator+=(const Vect& other);
    Vect& operator-=(const Vect& other);
    void print() const;
};

#endif