#include "controller.h"

namespace s21 {

bool Controller::ParseFile(std::string file_path) {
  return model_->ProccessingObjFile(file_path);
}

}  // namespace s21