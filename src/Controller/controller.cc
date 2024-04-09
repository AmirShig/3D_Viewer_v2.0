#include "controller.h"

namespace s21 {

bool Controller::GetFile(QString &q_string) {
    std::string std_string = q_string.toStdString();
    return model_->ProccessingObjFile(std_string);
}

} // namespace s21