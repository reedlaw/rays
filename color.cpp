class Color : public Vector {
public:
  int r, g, b;

  Color() {
  }
  Color(float r1, float g1, float b1) : Vector(r1, g1, b1) {
    r=(int)(x * 255.0);
    g=(int)(y * 255.0);
    b=(int)(z * 255.0);
    if (r > 255) { r = 255; }
    if (g > 255) { g = 255; }
    if (b > 255) { b = 255; }
  }
  inline virtual Color operator+ (const Color &rhs) const{
    return Color(x+rhs.x, y+rhs.y, z+rhs.z);
  }
  inline Color operator* (const float &scalar) const {
    return Color(x*scalar, y*scalar, z*scalar);
  }
  static Color cross (const Color &c1, const Color &c2) {
    return Color(c1.g*c2.b - c1.b*c2.g, c1.b*c2.r - c1.r*c2.b, c1.r*c2.g - c1.g*c2.r);
  }

};
