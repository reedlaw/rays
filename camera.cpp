class Camera {
public:
  Vector lookFrom;
  Vector lookAt;
  Vector up;
  float fovy;
  float fovx;
  int width;
  int height;

  Camera() {
  }
  Camera(Vector lf, Vector la, Vector u, float f, int w, int h) {
    lookFrom = lf;
    lookAt = la;
    up = u;
    width = w;
    height = h;
    int aspect_ratio = width/height;
    fovy = f;
    fovx = fovy * aspect_ratio;
  }
  void generateRay(Sample& sample, Ray* ray);
};

void Camera::generateRay(Sample& sample, Ray* ray) {
  Vector a = lookFrom - Vector(0.f, 0.f, 0.f);
  Vector b = up;
  Vector w = a.normalize();
  Vector u = Vector::cross(b,w).normalize();
  Vector v = Vector::cross(w,u);
  float alpha = tan(fovx/2)*(sample.x-(width/2)/width/2);
  float beta = tan(fovy/2)*((height/2)-sample.y/height/2);
  Vector direction = lookFrom + ((u*alpha)+(v*beta)-w).normalize();
  // printf("i %f, j %f\n", sample.y, sample.x);
  // printf("Direction: %f %f %f\n", direction.x, direction.y, direction.z);
  *ray = Ray(lookFrom, direction, 0.f, 1000000000.f);
}
