#ifndef INC_3DVIEWER_2_MODEL_H
#define INC_3DVIEWER_2_MODEL_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "data_3d_model.h"

namespace s21 {

class Model {
public:
  Model() = default;
  ~Model() = default;

  Render3DModel &GetObject3d() { return object_3d_; }
  virtual void UpdateData(Data3DModel *data) = 0;

private:
  Render3DModel object_3d_;
};

} // namespace s21

#endif // INC_3DVIEWER_2_MODEL_H
