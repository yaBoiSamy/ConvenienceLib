#include "Vector.h"
#include "Arduino.h"

// Constructor
Vect::Vect(float _x, float _y, float _z) {
  arr[0] = _x;
  arr[1] = _y;
  arr[2] = _z;
}

// Getter methods
float Vect::x() const { return arr[0]; }
float Vect::y() const { return arr[1]; }
float Vect::z() const { return arr[2]; }

// Setter methods
void Vect::setx(float x) { arr[0] = x; }
void Vect::sety(float y) { arr[1] = y; }
void Vect::setz(float z) { arr[2] = z; }

// Dot product
float Vect::dot(const Vect& other) const {
  return x() * other.x() + y() * other.y() + z() * other.z();
}

// Cross product
Vect Vect::cross(const Vect& other) const {
  return Vect(
    y() * other.z() - z() * other.y(),
    z() * other.x() - x() * other.z(),
    x() * other.y() - y() * other.x()
  );
}

// Norm (magnitude) of the vector
float Vect::norm() const {
  return sqrt(x()*x() + y()*y() + z()*z());
}

// Angle between two vectors
float Vect::angle(const Vect& other) const {
  return acos(dot(other)/(norm()*other.norm()));
}

// Normalize the vector (unit vector)
Vect Vect::normalize() const {
  float n = norm();
  if (n == 0) {
    return Vect(0, 0, 0);  // Avoid division by zero
  }
  return Vect(x()/ n, y()/ n, z()/n);
}

// String conversion for printing
String Vect::str() const {
  return "( " + String(x()) + " , " + String(y()) + " , " + String(z()) + " )";
}

// Overloading the [] operator for reading and writing
float& Vect::operator[](int index) {
  return arr[index];
}

// Overloading the [] operator for const objects (read-only)
const float& Vect::operator[](int index) const {
  return arr[index];
}


