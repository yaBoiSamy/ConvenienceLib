#include "Vector.h"
#include "Arduino.h"

// Dot product
float Vect::dot(const Vect& other) const {
  return x * other.x + y * other.y + z * other.z;
}

// Cross product
Vect Vect::cross(const Vect& other) const {
  return Vect(
    y * other.z - z * other.y,
    z * other.x - x * other.z,
    x * other.y - y * other.x
  );
}

// Norm (magnitude) of the vector
float Vect::norm() const {
  return sqrt(x*x + y*y + z*z);
}

// Angle between two vectors
float Vect::angle(const Vect& other) const {
  return acos(dot(other)/(norm()*other.norm()));
}

// Normalize the vector (unit vector)
Vect Vect::normalize() const {
  float n = norm();
  return n==0 ? Vect(0, 0, 0) : Vect(x/n, y/n, z/n);
}

// String conversion for printing
String Vect::str() const {
  return "( " + String(x) + " , " + String(y) + " , " + String(z) + " )";
}

// Overloading the [] operator for reading and writing
float& Vect::operator[](int index) {
  switch(index){
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
  }
}

// Overloading the [] operator for const objects (read-only)
const float& Vect::operator[](int index) const {
  switch(index){
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
  }
}

// Overload + operator
Vect Vect::operator+(const Vect& other) const {
  return Vect(x + other.x, y + other.y, z + other.z);
}

// Overload - operator
Vect Vect::operator-(const Vect& other) const {
  return Vect(x - other.x, y - other.y, z - other.z);
}

// Overload += operator
Vect& Vect::operator+=(const Vect& other) {
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

// Overload -= operator
Vect& Vect::operator-=(const Vect& other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

// Print method for easy output
void Vect::print() const {
  Serial.println(str());
}


