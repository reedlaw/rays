#include <math.h>
#include "floating_point.h"

class Vector {
public:
  float x, y, z;
  typedef float RawType;      // float -> double for different output

  Vector() {
  }
  inline Vector(float x1, float y1, float z1)  {
    x=x1;
    y=y1;
    z=z1;
  }

  inline bool operator== (const Vector &rhs) const{
    return ( (FloatingPoint<RawType>(x).AlmostEquals(FloatingPoint<RawType>(rhs.x))) &&
             (FloatingPoint<RawType>(y).AlmostEquals(FloatingPoint<RawType>(rhs.y))) &&
             (FloatingPoint<RawType>(z).AlmostEquals(FloatingPoint<RawType>(rhs.z))) );
  }

  inline virtual Vector operator+ (const Vector &rhs) const{
    return Vector(x+rhs.x, y+rhs.y, z+rhs.z);
  }

  inline Vector operator- (const Vector &rhs) const {
    Vector ret (x-rhs.x, y-rhs.y, z-rhs.z);
    return ret;
  }

  inline Vector operator* (const float &scalar) const {
    Vector ret (x*scalar, y*scalar, z*scalar);
    return ret;
  }

  inline Vector operator/ (const float &scalar) const {
    Vector ret (x/scalar, y/scalar, z/scalar);
    return ret;
  }

  inline Vector normalize() const {
    if (x==0.0f && y==0.0f && z==0.0f) {
      throw 20;
    }
    float length = sqrt((x*x) + (y*y) + (z*z));
    Vector ret (x/length, y/length, z/length);
    return ret;
  }

  static Vector cross (const Vector &vec1, const Vector &vec2) {
    Vector ret (vec1.y*vec2.z - vec1.z*vec2.y, vec1.z*vec2.x - vec1.x*vec2.z, vec1.x*vec2.y - vec1.y*vec2.x);
    return ret;
  }

  inline float operator* (const Vector &vec) const {
    float ret = x*vec.x + y*vec.y + z*vec.z;
    return ret;
  }


private:
  float dir;
};
