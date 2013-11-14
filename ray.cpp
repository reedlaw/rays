class Ray {
public:
  Vector pos;
  Vector dir;
  float t_min, t, t_max; // t_min < t < t_max

  inline Ray() {
  }
  inline Ray(Vector& pos1, Vector& dir1, float t_min1, float t_max1) {
    pos = pos1;
    dir = dir1;
    t_min = t_min1;
    t_max = t_max1;
  }
  // ray(t) = pos + t*dir
};
