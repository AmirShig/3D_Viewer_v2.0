#ifndef INC_3DVIEWER_2_CONTROLLER_H
#define INC_3DVIEWER_2_CONTROLLER_H

#include <QString>

#include "../Model/model.h"

namespace s21 {

class Controller {
public:
  Controller() {
    //      Strategy *move_obj = new MoveObj();
    //      Strategy *rotation_obj = new RotateObj();
    //      Strategy *distance_obj = new DistanceObj();
  }
  Controller(Model *m) : model_(m) {}

  void Affine(Strategy::SelectionStrategy select_strategy,
              Strategy::TypeCoordinate type, Data3DModel *data, double point) {
    model_->Affine(select_strategy, type, data, point);
  }

  bool GetStringFilePath(QString &q_string);
  std::string ConvertToStdString(QString &q_string);
  Data3DModel &GetData() { return model_->GetData(); }

  void SetCentre(Data3DModel *data);

private:
  Model *model_;
};
} // namespace s21

#endif // INC_3DVIEWER_2_CONTROLLER_H
