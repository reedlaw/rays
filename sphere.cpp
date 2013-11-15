class Sphere {
public:
  Vector pos;
  float radius;
  Vector intersectionPoint;

  Sphere() {
  }
  Sphere(Vector p, float r) {
    pos = p;
    radius = r;
  }
  bool intersect(Ray& ray);
  static float getIntersectionPoint(float a, float b, float c) {
    float r1 = (-b+sqrt(b*b-4*a*c))/(2*a);
    float r2 = (-b-sqrt(b*b-4*a*c))/(2*a);
    if ((r2 < 0 || r1 < r2) && r1 >= 0) {
      return r1;
    } else {
      return r2;
    }
  }

  static bool isDiscriminantPositive(float a, float b, float c) {
    float discriminant = b*b - 4*a*c;
    if (discriminant<0) {
      return false;
    } else {
      return true;
    }
  }
};

bool Sphere::intersect(Ray& ray) {
  Vector L = ray.pos - pos;
  float a = ray.dir*ray.dir;
  float b = (ray.dir*L)*2;
  float c = L*L - (radius*radius);
  if (isDiscriminantPositive(a,b,c)) {
    float t = getIntersectionPoint(a,b,c);
    intersectionPoint = ray.getPoint();
    return true;
  } else {
    return false;
  }
}
