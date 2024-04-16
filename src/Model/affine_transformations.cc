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
void AffineTransformations::Transformations(s21::Data3DModel *data, double point) {
  strategy_->Transformations(data, point);
}

void MoveObj::Transformations(s21::Data3DModel *data, double point) {

}

} // namespace s21