#include "affine_transformations.h"

namespace s21 {

/*!
 * \brief Устанавливает конкретную стратегию
 * \param concrete_strategy указатель на конктретную стратегию
 */
void AffineTransformations::SetStrategy(Strategy *concrete_strategy) {
  strategy_ = concrete_strategy;
}

/*!
 * \brief Изменяет объект в пространстве
 * \param data данные объекта
 * \param point входящая координата
 */
void AffineTransformations::Transformations(
    s21::Data3DModel *data, double point,
    Strategy::TypeCoordinate coordinate_x_y_z) {
  strategy_->Transformations(data, point, coordinate_x_y_z);
}

void MoveObj::Transformations(s21::Data3DModel *data, double point,
                              TypeCoordinate coordinate_x_y_z) {
  for (auto &i : data->GetCoordinateVertex()) {
    if (coordinate_x_y_z == TypeCoordinate::kX) i.X += point;
    if (coordinate_x_y_z == TypeCoordinate::kY) i.Y += point;
    if (coordinate_x_y_z == TypeCoordinate::kZ) i.Z += point;
  }
}

void RotateObj::Transformations(Data3DModel *data, double point,
                                Strategy::TypeCoordinate coordinate_x_y_z) {
  switch (coordinate_x_y_z) {
    case Strategy::TypeCoordinate::kX:
      Rotate(data, point, &RotateObj::RotateX);
      break;
    case Strategy::TypeCoordinate::kY:
      Rotate(data, point, &RotateObj::RotateY);
      break;
    case Strategy::TypeCoordinate::kZ:
      Rotate(data, point, &RotateObj::RotateZ);
      break;
  }
}

void RotateObj::Rotate(Data3DModel *data, double point,
                       void (RotateObj::*SomeMethod)(Data3DModel::Coordinate &,
                                                     double)) {
  for (auto &i : data->GetCoordinateVertex()) {
    (this->*SomeMethod)(i, point);
  }
}

void RotateObj::RotateX(Data3DModel::Coordinate &i, double point) {
  i.Y = i.Y * cos(point) + i.Z * sin(point);
  i.Z = -i.Y * sin(point) + i.Z * cos(point);
}
void RotateObj::RotateY(Data3DModel::Coordinate &i, double point) {
  i.X = i.X * cos(point) + i.Z * sin(point);
  i.Z = -i.X * sin(point) + i.Z * cos(point);
}

void RotateObj::RotateZ(Data3DModel::Coordinate &i, double point) {
  i.X = i.X * cos(point) + i.Y * sin(point);
  i.Y = -i.X * sin(point) + i.Y * cos(point);
}

}  // namespace s21