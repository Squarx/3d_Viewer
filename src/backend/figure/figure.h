//
// Created by DimasX on 10.08.2023.
//

#ifndef INC_3D_VIEWER_SRC_BACKEND_FIGURE_FIGURE_H_
#define INC_3D_VIEWER_SRC_BACKEND_FIGURE_FIGURE_H_

#include <vector>
#include "edge.h"

class Figure{
 public:
  void AddVertex(Vertex vertex) {
    vertices_.push_back(vertex);
  }
  void AddEdge(Edge edge) {
    edges_.push_back(edge);
  }
  std::vector<Vertex> GetVertices() {
    return vertices_;
  }
  std::vector<Edge> GetEdges() {
    return edges_;
  }


 private:
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
};
#endif //INC_3D_VIEWER_SRC_BACKEND_FIGURE_FIGURE_H_
