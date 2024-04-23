#include "model.h"

namespace s21 {
bool Model::ProccessingObjFile(std::string &file_path) {
  return parse_.ParseObjFile(file_path, &data_);
}

///@brief Принимает параметр SelectionStrategy и устанавливает стратегию
///@param select_strategy перечисление, определяет стратегию
///@param move_obj_ стратегия движения обьекта
///@param affine_ класс афинных преобразований
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

void Model::GiveCommand(Data3DModel *data, Event *event,
                        Event::Command command) {
  Event::VerifyExecution verify = event->Execute(data, command);

  if (verify == Event::VerifyExecution::kNotExecution)
    return;
}

void Model::SetCentre(Data3DModel *data) {
  find_min_max_->SetNextEvent(find_max_)->SetNextEvent(find_centre_);

  find_min_max_->centre_ = Event::MinMax();
  find_min_max_->min_ = Event::MinMax();
  find_min_max_->max_ = Event::MinMax();
  find_min_max_->scale_for_centre_ = 0;
  GiveCommand(data, find_min_max_, Event::Command::kFindMinMax);
  find_max_->Update(find_min_max_);
  GiveCommand(data, find_max_, Event::Command::kFindMax);
  find_centre_->Update(find_max_);
  GiveCommand(data, find_centre_, Event::Command::kFindCentre);
}

} // namespace s21