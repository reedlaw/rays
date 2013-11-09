#include "vector.cpp"

class Normal : public Vector {
public:
  Normal(float x1, float y1, float z1) : Vector(x1, y1, z1) {
    x=std::min(std::max(x1, 0.0f), 1.0f);
    y=std::min(std::max(y1, 0.0f), 1.0f);
    z=std::min(std::max(z1, 0.0f), 1.0f);
  }
};
