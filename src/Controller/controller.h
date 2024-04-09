#ifndef INC_3DVIEWER_2_CONTROLLER_H
#define INC_3DVIEWER_2_CONTROLLER_H

#include "../Model/model.h"
#include <QString>

namespace s21 {

class Controller {
public:
  Controller() = default;
  Controller(Model *m) : model_(m) {}

  bool GetStringFilePath(QString &q_string);
  std::string ConvertToStdString(QString &q_string);

private:
  Model *model_;
};
} // namespace s21

#endif // INC_3DVIEWER_2_CONTROLLER_H
