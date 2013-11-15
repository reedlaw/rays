#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <deque>
#include <stack>
using namespace std;

class Parser {
public:
  const char* fileName;
  Camera camera;
  World world;
  stack <Matrix> transformStack;
  int width;
  int height;
  int maxDepth;

  inline Parser(const char* file) {
    fileName = file;
    width = 100;
    height = 100;
    maxDepth = 5;
    transformStack.push(Matrix(1.f));
  }

  inline void parse() {
    readFile(fileName);
  }
  bool readValues(stringstream &s, const int numvals, float* values);
  void readFile(const char* filename);
};

bool Parser::readValues(stringstream &s, const int numVals, float* values) 
{
  for (int i = 0; i < numVals; i++) {
    s >> values[i];
    if (s.fail()) {
      cout << "Failed reading value " << i << " will skip\n"; 
      return false;
    }
  }
  return true;
}

void Parser::readFile(const char* filename) 
{
  string str, cmd; 
  ifstream in;
  in.open(filename); 
  if (in.is_open()) {
    getline (in, str); 
    while (in) {
      if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
        // Ruled out comment and blank lines 

        stringstream s(str);
        s >> cmd; 
        int i; 
        float values[10]; // Position and color for light, colors for others
        bool validinput; // Validity of input 

        if (cmd == "size") {
          validinput = readValues(s, 2, values);
          if (validinput) {
            width = values[0];
            height = values[1];
          }

        } else if (cmd == "camera") {
          validinput = readValues(s,10,values); // 10 values eye cen up fov
          if (validinput) {
            Vector eye = Vector(values[0], values[1], values[2]);
            Vector center = Vector(values[3], values[4], values[5]);
            Vector up = Vector(values[6], values[7], values[8]);
            float fov = values[9];
            camera = Camera(eye, center, up, fov, width, height);
          }
        } else if (cmd == "sphere") {
          validinput = readValues(s,4,values);
          if (validinput) {
            world.spheres.push_back(Sphere(Vector(values[0], values[1], values[2]), values[3]));
          }
        } else if (cmd == "directional") {
          validinput = readValues(s,6,values);
          if (validinput) {
            world.lights.push_back(Light(Vector(values[0], values[1], values[2]),
                                         Color(values[3], values[4], values[5])));
          }
        } else {
          cerr << "Unknown Command: " << cmd << " Skipping \n"; 
        }
      }
      getline (in, str); 
    }

  } else {
    cerr << "Unable to Open Input Data File " << filename << "\n"; 
    throw 2; 
  }
}
