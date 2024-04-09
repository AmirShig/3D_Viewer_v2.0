#ifndef INC_3DVIEWER_2_CONTROLLER_H
#define INC_3DVIEWER_2_CONTROLLER_H

#include "../Model/model.h"

namespace s21 {

class Controller {
public:
  Controller() = default;
  Controller(Model *m) : model_(m) {}

  Render3DModel &Get3dModel() { return model_->GetObject3d(); }
    Render3DModel &GetData() {return }
  void UpdateData(s21::Render3DModel::Data3DModel &obj) { data_.UpdateObj(obj); }

private:
  Model *model_;
  MyOpenGLWidget data_;

};
} // namespace s21

#endif // INC_3DVIEWER_2_CONTROLLER_H
