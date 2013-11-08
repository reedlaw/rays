#include <gtest/gtest.h>
#include "floating_point.h"

class Vector {
public:
  Vector(float x1, float y1, float z1);
  float x, y, z;
  typedef float RawType;      // float -> double for different output
  inline bool operator== (const Vector &rhs) const
  {
    return ( (FloatingPoint<RawType>(x).AlmostEquals(FloatingPoint<RawType>(rhs.x))) &&
             (FloatingPoint<RawType>(y).AlmostEquals(FloatingPoint<RawType>(rhs.y))) &&
             (FloatingPoint<RawType>(z).AlmostEquals(FloatingPoint<RawType>(rhs.z))) );
  }
  inline Vector operator+ (const Vector &rhs) const
  {
    Vector ret (x+rhs.x, y+rhs.y, z+rhs.z);
    return ret;
  }
  inline Vector operator- (const Vector &rhs) const
  {
    Vector ret (x-rhs.x, y-rhs.y, z-rhs.z);
    return ret;
  }

private:
  float dir;
};

Vector::Vector(float x1, float y1, float z1) {
  x=x1;
  y=y1;
  z=z1;
}
