#include <gtest/gtest.h>

class Vector {
public:
  Vector(float x1, float y1, float z1);
  float x, y, z;
  inline bool operator == (const Vector &b) const
  {
    return ( (b.x==x) &&
             (b.y==y) &&
             (b.z==z) );
  }
private:
  float dir;
};

Vector::Vector(float x1, float y1, float z1) {
  x=x1;
  y=y1;
  z=z1;
}
