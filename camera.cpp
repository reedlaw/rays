class Camera {
public:
  Vector lookFrom;
  Vector lookAt;
  Vector up;
  float fov;

  Camera() {
  }
  Camera(Vector lookFrom1, Vector lookAt1, Vector up1, float fov1) {
    lookFrom = lookFrom1;
    lookAt = lookAt1;
    up = up1;
    fov = fov1;
  }
  void generateRay(Sample& sample, Ray* ray);
};

void Camera::generateRay(Sample& sample, Ray* ray) {
  Point raster(sample.x, sample.y, 0);
  *ray = Ray(Point(0.f,0.f,0.f), lookFrom.normalize(), 0.f, 1000000000.f);
}
