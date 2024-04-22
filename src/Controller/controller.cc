#include "controller.h"

namespace s21 {

bool Controller::ParseFile(std::string file_path) {
  return model_->ProccessingObjFile(file_path);
}

void Controller::SetCentre(s21::Data3DModel *data) { model_->SetCentre(data); }

} // namespace s21