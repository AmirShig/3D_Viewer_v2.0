#include "model.h"

namespace s21 {
bool Model::ProccessingObjFile(std::string &file_path) {
    parse_->ParseObjFile(file_path, &data_);
    return 1;
}
} // namespace s21