class Color : public Vector {
public:
  int r, g, b;

  Color() {
  }
  Color(float r1, float g1, float b1) : Vector(r1, g1, b1) {
    r=(int)(x * 255.0);
    g=(int)(y * 255.0);
    b=(int)(z * 255.0);
  }
};
