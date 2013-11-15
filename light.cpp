class Light {
public:
  Vector dir;
  Ray lightRay;
  Ray shadowRay;
  Color color;

  Light(Vector p, Color c) {
    dir = p;
    color = c;
  }
  void generateLightRay(Vector localPoint);
};

void Light::generateLightRay(Vector localPoint) {
  shadowRay = Ray(localPoint, dir, T_MIN, T_MAX);
  shadowRay.t = 0.0001f;
  Vector offset = shadowRay.getPoint();
  lightRay = Ray(dir, offset, T_MIN, T_MAX);
}
