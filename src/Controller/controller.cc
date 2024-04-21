#include "controller.h"

namespace s21 {

bool Controller::GetStringFilePath(QString &q_string) {
  std::string std_string = q_string.toStdString();
  return model_->ProccessingObjFile(std_string);
}

void Controller::SetCentre(s21::Data3DModel *data) { model_->SetCentre(data); }

} // namespace s21