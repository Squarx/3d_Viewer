//
// Created by DimasX on 10.08.2023.
//

#ifndef INC_3D_VIEWER_SRC_BACKEND_PARSER_FILEREADER_H_
#define INC_3D_VIEWER_SRC_BACKEND_PARSER_FILEREADER_H_
#include <iomanip>
#include <fstream>
#include <memory>
#include "basefilereader.h"

class FileReader : public BaseFileReader {
 public:
  FileReader() = default;
  FileReader(const std::string &file_path) : file_path_(file_path) {}
  void SetPath(const std::string &file_path) {
    file_path_ = file_path;
  }

  Scene ReadScene() override {
    std::string line{};
    std::ifstream in(file_path_);
    Scene scene{};

    if (in.is_open()) {
      while (std::getline(in, line)) {
        if (!ProcessVertex(line) && !ProcessFacets(line)) {
          continue;
        }
      }

      in.close();
    } else {
      throw std::runtime_error("Unable to open file: " + std::string(file_path_));
    }
    scene.AddFigure(figure);
    return scene;
  }

 private:
  std::string file_path_;
  Figure figure{};
  void PrintFacets();
  void PrintVertex();
  bool ProcessVertex(const std::string &line);
  bool ProcessFacets(const std::string &line);
};




#endif //INC_3D_VIEWER_SRC_BACKEND_PARSER_FILEREADER_H_
