#include "model.h"

namespace s21 {
bool Model::ProccessingObjFile(std::string &file_path) {
    parse_.ParseObjFile(file_path, data_);
    std::cout << data_->GetPolygons();
}
} // namespace s21