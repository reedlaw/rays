class Sphere {
public:
  Vector pos;
  float radius;

  Sphere() {
  }
  Sphere(Vector p, float r) {
    pos = p;
    radius = r;
  }
  bool intersect(Ray& ray);
};

bool Sphere::intersect(Ray& ray) {
  Vector L = ray.pos - pos;
  float a = ray.dir*ray.dir;
  float b = (ray.dir*L)*2;
  float c = L*L - (radius*radius);

  float discriminant = b*b - 4*a*c;
  if (discriminant<0) {
    return false;
  } else {
    return true;
  }
}
