#include "affine_transformations.h"

namespace s21 {

/*!
 * \brief Устанавливает конкретную стратегию
 * \param concrete_strategy указатель на конктретную стратегию
 */
void AffineTransformations::SetAffinneTransformations(
    Strategy *concrete_strategy) {
  strategy_ = concrete_strategy;
}

/*!
 * \brief Изменяет объект в пространстве
 * \param data данные объекта
 * \param point входящая координата
 */
void AffineTransformations::Transformations(
    s21::Data3DModel *data, double point,
    Strategy::coordinate coordinate_x_y_z) {
  strategy_->Transformations(data, point, coordinate_x_y_z);
}

void MoveObj::Transformations(s21::Data3DModel *data, double point,
                              coordinate coordinate_x_y_z) {
  auto i = data->GetCoordinateVertex().begin();
  if (coordinate_x_y_z == coordinate::Y) ++i;
  if (coordinate_x_y_z == coordinate::Z) i += 2;

  for (; i != data->GetCoordinateVertex().end(); ++i) {
    *i += point;
  }
}

void RotateObj::Transformations(s21::Data3DModel *data, double point,
                                Strategy::coordinate coordinate_x_y_z) {
  // Заглушка
  auto i = data->GetCoordinateVertex().begin();
  if (coordinate_x_y_z == coordinate::Y) {
    ++i;
    --i;
  }
  if (coordinate_x_y_z == coordinate::Z) {
    i += 2;
    i -= 2;
  }

  for (; i != data->GetCoordinateVertex().end(); ++i) {
    *i += point;
    *i -= point;
  }
}

void DistanceObj::Transformations(s21::Data3DModel *data, double point,
                                  Strategy::coordinate coordinate_x_y_z) {
  // Заглушка
  auto i = data->GetCoordinateVertex().begin();
  if (coordinate_x_y_z == coordinate::Y) {
    ++i;
    --i;
  }
  if (coordinate_x_y_z == coordinate::Z) {
    i += 2;
    i -= 2;
  }

  for (; i != data->GetCoordinateVertex().end(); ++i) {
    *i += point;
    *i -= point;
  }
}
}  // namespace s21