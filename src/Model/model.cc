#include "model.h"

namespace s21 {
bool Model::ProccessingObjFile(std::string &file_path) {
  return parse_->ParseObjFile(file_path, &data_);
}
}  // namespace s21