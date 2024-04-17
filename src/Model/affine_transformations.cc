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
  size_t j = 0;
  auto i = data->GetCoordinateVertex().begin();
  if (coordinate_x_y_z == TypeCoordinate::kY) ++i, ++j;
  if (coordinate_x_y_z == TypeCoordinate::kZ) i += 2, j += 2;

  for (; i != data->GetCoordinateVertex().end() &&
         j < data->GetCoordinateVertex().size();
       i += 3, j += 3) {
    *i += point;
  }
}

//void RotateObj::Transformations(s21::Data3DModel *data, double point, s21::Strategy::TypeCoordinate coordinate_x_y_z) {
//
//} {
//
//};

}  // namespace s21