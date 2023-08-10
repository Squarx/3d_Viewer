//
// Created by DimasX on 10.08.2023.
//

#ifndef INC_3D_VIEWER_SRC_BACKEND_FIGURE_EDGE_H_
#define INC_3D_VIEWER_SRC_BACKEND_FIGURE_EDGE_H_
#include "vertex.h"

class Edge {
 public:
  Edge(unsigned int begin, unsigned int end): begin_index_(begin), end_index_(end) {}
  unsigned int GetBegin() {return begin_index_;}
  unsigned int GetEnd() {return end_index_;}
 private:
  unsigned int begin_index_;
  unsigned int end_index_;
};

#endif //INC_3D_VIEWER_SRC_BACKEND_FIGURE_EDGE_H_
