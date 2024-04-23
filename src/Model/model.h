#ifndef INC_3DVIEWER_2_MODEL_H
#define INC_3DVIEWER_2_MODEL_H

#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "affine_transformations.h"
#include "data_3d_model.h"
#include "parse_obj.h"
#include "set_centre.h"

namespace s21 {

/*!
 * \brief Главный класс который реализован по паттерну "Фасад"
 */
class Model {
 public:
  Model() {
    move_obj_ = new MoveObj();
    rotate_obj_ = new RotateObj();
    distance_obj_ = new DistanceObj();

    find_min_max_ = new FindMinMax();
    find_max_ = new FindMax();
    find_centre_ = new FindCentre();
  }

  ~Model() {
    delete move_obj_;
    delete rotate_obj_;
    delete distance_obj_;

    delete find_min_max_;
    delete find_max_;
    delete find_centre_;
  }
  //Отдать данные в Controller
  Data3DModel &GetData() { return data_; }
  bool ProccessingObjFile(std::string &file_path);
  void Affine(Strategy::SelectionStrategy select_strategy,
              Strategy::TypeCoordinate type, Data3DModel *data, double point);

  void SetCentre(Data3DModel *data);
  void GiveCommand(Data3DModel *data, Event *event, Event::Command command);

 private:
  Data3DModel data_{};
  ParseObj parse_{};
  AffineTransformations affine_{};
  Strategy *move_obj_;
  Strategy *rotate_obj_;
  Strategy *distance_obj_;
  FindMinMax *find_min_max_;
  FindMax *find_max_;
  FindCentre *find_centre_;
};

}  // namespace s21

#endif  // INC_3DVIEWER_2_MODEL_H
