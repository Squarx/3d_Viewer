//
// Created by DimasX on 10.08.2023.
//

#ifndef INC_3D_VIEWER_SRC_BACKEND_PARSER_BASEFILEREADER_H_
#define INC_3D_VIEWER_SRC_BACKEND_PARSER_BASEFILEREADER_H_
#include "../scene/scene.h"

class BaseFileReader {
 public:
  virtual Scene ReadScene() = 0;
};

#endif //INC_3D_VIEWER_SRC_BACKEND_PARSER_BASEFILEREADER_H_
