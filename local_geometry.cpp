class LocalGeometry {
public:
  Vector position;
  Normal normal;

  inline LocalGeometry() {
  }
  inline LocalGeometry(Vector p, Normal n) {
    position = p;
    normal = n;
  }
};
