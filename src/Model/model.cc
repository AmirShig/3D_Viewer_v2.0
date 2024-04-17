#include "model.h"

namespace s21 {
bool Model::ProccessingObjFile(std::string &file_path) {
  return parse_.ParseObjFile(file_path, &data_);
}

/*!
 * \brief Принимает параметр SelectionStrategy и устанавливает стратегию
 * \param select_strategy перечисление, определяет стратегию
 * \param move_obj_ стратегия движения обьекта
 * \param affine_ класс афинных преобразований
 */
void Model::Affine(Strategy::SelectionStrategy select_strategy,
                   Strategy::TypeCoordinate type_coordinate, Data3DModel *data,
                   double point) {
  if (select_strategy == Strategy::SelectionStrategy::kMove) {
    affine_.SetStrategy(move_obj_);
  }

  affine_.Transformations(data, point, type_coordinate);
}
}  // namespace s21