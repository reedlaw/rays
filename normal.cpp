class Normal : public Vector {
public:
  Normal() : Vector() {
  }
  Normal(const Vector &vec) {
    x=vec.x;
    y=vec.y;
    z=vec.z;
  }
  Normal(float x1, float y1, float z1) : Vector(x1, y1, z1) {
  }

  inline Normal operator+ (const Normal &rhs) const {
    Vector ret = Vector::operator+(rhs).normalize();
    return Normal(ret.x, ret.y, ret.z);
  }

  inline Normal operator- (const Normal &rhs) const {
    Vector ret = Vector::operator-(rhs).normalize();
    return Normal(ret.x, ret.y, ret.z);
  }

};
