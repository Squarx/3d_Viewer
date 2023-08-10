//
// Created by DimasX on 10.08.2023.
//

#ifndef INC_3D_VIEWER_SRC_BACKEND_FIGURE_VERTEX_H_
#define INC_3D_VIEWER_SRC_BACKEND_FIGURE_VERTEX_H_

class Vertex {

  struct Point {
    Point(double x1, double y1, double z1): x(x1), y(y1), z(z1){}
    double x;
    double y;
    double z;
  };
 public:
  Vertex(double x, double y, double z) : position_(x, y, z){}
  Point GetPosition() {return position_;}

 private:
  Point position_;
};

#endif //INC_3D_VIEWER_SRC_BACKEND_FIGURE_VERTEX_H_
