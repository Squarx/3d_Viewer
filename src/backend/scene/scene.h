//
// Created by DimasX on 10.08.2023.
//

#ifndef INC_3D_VIEWER_SRC_BACKEND_SCIENE_SCENE_H_
#define INC_3D_VIEWER_SRC_BACKEND_SCIENE_SCENE_H_
#include <iostream>
#include <vector>
#include "../figure/figure.h"

class Scene {
 public:
  std::vector<Figure> GetFigures() {return figures_;}

  void PrintScene() {
    for (auto i  = 0; i < figures_.size();++i) {
      std::cout << " Figure: " << i << std::endl;

      auto vertices = figures_[i].GetVertices();
      std::cout << " Vertices : " << vertices.size() << std::endl;
      for (auto j  = 0; j < vertices.size();++j) {
        std::cout << vertices[j].GetPosition().x << " " <<  vertices[j].GetPosition().y << " " << vertices[j].GetPosition().z << std::endl;
      }


      auto edges = figures_[i].GetEdges();
      std::cout << " Facets : " << edges.size() << std::endl;
      for (auto z  = 0; z < edges.size();++z) {
        if (z % 3 == 0) std::cout << std::endl;
        std::cout << edges[z].GetBegin() << " " <<  edges[z].GetEnd() << " | ";
      }
    }
  }

  void AddFigure(Figure f) {figures_.push_back(f);}

 private:
std::vector<Figure> figures_;
};


#endif //INC_3D_VIEWER_SRC_BACKEND_SCIENE_SCENE_H_
