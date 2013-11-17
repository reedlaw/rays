class Light {
public:
  Vector position;
  Color color;

  Light(Vector p, Color c) {
    position = p;
    color = c;
  }
  Ray generateShadowRay(Vector localPoint);
};

Ray Light::generateShadowRay(Vector localPoint) {
  Ray localRay = Ray(localPoint, position, T_MIN, T_MAX);
  localRay.t = 0.0001f;
  Vector offsetPoint = localRay.getPoint();
  return Ray(offsetPoint, position, T_MIN, T_MAX);
}
