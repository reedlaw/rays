class Ray {
public:
  Vector position;
  Vector direction;
  float t_min, t, t_max; // t_min < t < t_max

  inline Ray() {
  }
  inline Ray(Vector& p, Vector& d, float t_min1, float t_max1) {
    position = p;
    direction = d;
    t_min = t_min1;
    t_max = t_max1;
  }
  Vector getPoint();
};

Vector Ray::getPoint() {
  Vector point = position + (direction*t);
  return point;
}
