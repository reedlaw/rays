class Sphere : public Primitive {
public:
  Vector position;
  float radius;
  Material material;

  Sphere() {};
  Sphere(Vector p, float r, Material m) {
    position = p;
    radius = r;
    material = m;
  };
  inline Material getMaterial() {
    return material;
  };
  bool intersect(Ray& ray, LocalGeometry& local);
  bool isIntersected(Ray& ray);

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
      return r1;
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

bool Sphere::intersect(Ray& ray, LocalGeometry& local) {
  Vector L = ray.position - position;
  float a = ray.direction*ray.direction;
  float b = (ray.direction*L)*2;
  float c = L*L - (radius*radius);
  if (isDiscriminantPositive(a,b,c)) {
    ray.t = getIntersectionPoint(a,b,c);
    local.position = ray.getPoint();
    Vector normal = (local.position - position).normalize();
    local.normal = static_cast<Normal>(normal);
    return true;
  } else {
    return false;
  }
}

bool Sphere::isIntersected(Ray& ray) {
  Vector L = ray.position - position;
  float a = ray.direction*ray.direction;
  float b = (ray.direction*L)*2;
  float c = L*L - (radius*radius);
  float r1 = (-b+sqrt(b*b-4*a*c))/(2*a);
  float r2 = (-b-sqrt(b*b-4*a*c))/(2*a);
  if (r1 > 0 || r2 > 0) {
    return true;
  } else {
    return false;
  }
}
