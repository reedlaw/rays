class Material {
public:
  Color diffuse;
  Color specular;
  float shininess;
  Color emission;
  Color reflection;

  Material() {};
  Material(const Material& rhs) {
    diffuse = rhs.diffuse;
    specular = rhs.specular;
    shininess = rhs.shininess;
    emission = rhs.emission;
    reflection = rhs.reflection;
  };
  Material& operator=(const Material& rhs) {};
};
