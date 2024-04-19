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
  switch (select_strategy) {
  case Strategy::SelectionStrategy::kMove:
    affine_.SetStrategy(move_obj_);
    break;
  case Strategy::SelectionStrategy::kRotate:
    affine_.SetStrategy(rotate_obj_);
    break;
  case Strategy::SelectionStrategy::kDistance:
    affine_.SetStrategy(distance_obj_);
    break;
  }

  affine_.Transformations(data, point, type_coordinate);
}

/**
 * Назначает комманду
 * \param command перечисление комманд
 * \param event текущие событие
 * \param data данные 3d модели
 */
void Model::GiveCommand(Data3DModel *data, s21::Event *event, Event::Command command) {
    Event::VerifyExecution verify = event->Execute(data, command);

    if (verify == Event::VerifyExecution::kNotExecution) {
        return;
    }
}

} // namespace s21