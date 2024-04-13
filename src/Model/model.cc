#include "model.h"

namespace s21 {
bool Model::ProccessingObjFile(std::string &file_path) {
    parse_->ParseObjFile(file_path, &data_);
    return 0;
}
} // namespace s21