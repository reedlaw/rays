class Matrix {
public:
  float mat[4][4];

  inline Matrix(float val) {
    for (int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
        mat[i][j]=val;
      }
    }
  }
};
