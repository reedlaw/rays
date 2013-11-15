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

  inline static bool twoRealPositiveRoots(float r1, float r2, float& t) {
    if (r1 > 0 && r2 > 0) {
      if (r1 < r2) {
        t = r1;
      } else {
        t = r2;
      }
      return true;
    } else {
      return false;
    }
  }

  static float getIntersectionPoint(float a, float b, float c) {
    float r1 = (-b+sqrt(b*b-4*a*c))/(2*a);
    float r2 = (-b-sqrt(b*b-4*a*c))/(2*a);
    float t;
    if (twoRealPositiveRoots(r1, r2, t)) {
      return t;
    } else if (r1 == r2) {
      return r1;
    } else if (r1 > 0) {
      return r1;
    } else if (r2 > 0) {
      return r2;
    } else {
      return 0.f;
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
    printf("a %f\n", a);
    printf("b %f\n", b);
    printf("c %f\n", c);
  if (isDiscriminantPositive(a,b,c)) {
    ray.t = getIntersectionPoint(a,b,c);
    printf("ray.t %f\n", ray.t);
    intersectionPoint = ray.getPoint();
    return true;
  } else {
    return false;
  }
}
