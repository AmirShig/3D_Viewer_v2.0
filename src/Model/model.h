#ifndef INC_3DVIEWER_2_MODEL_H
#define INC_3DVIEWER_2_MODEL_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "data_3d_model.h"
#include "parce_obj.h"

namespace s21 {

class Model {
public:
  Model() {}
  ~Model() {}

  Data3DModel &GetData() { return data_; }
  bool ProccessingObjFile(std::string &file_path);

private:
  Data3DModel data_;
  ParseObj parse_;
};

} // namespace s21

#endif // INC_3DVIEWER_2_MODEL_H
