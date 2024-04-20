#include "set_centre.h"

namespace s21 {
Event *AbstructEvent::SetNextEvent(s21::Event *event) {
  next_event_ = event;
  return event;
}

Event::VerifyExecution AbstructEvent::Execute(s21::Data3DModel *data,

                                              Command command) {
  if (next_event_) {
    next_event_->Execute(data, command);
  }
}

Event::VerifyExecution FindMinMax::Execute(s21::Data3DModel *data,
                                           Command command) {
  //Надо проверить нашли ли мы минимальные и максимальные точки
  for (auto &vertex : data->GetCoordinateVertex()) {

    if (min_.x > vertex.x)
      min_.x = vertex.x;
    else
      max_.x = vertex.x;

    if (min_.y > vertex.y)
      min_.y = vertex.y;
    else
      max_.y = vertex.y;

    if (min_.z > vertex.z)
      min_.z = vertex.z;
    else
      max_.z = vertex.z;
  }

  centre_.x = min_.x + (max_.x - min_.x) / 2;
  centre_.y = min_.y + (max_.y - min_.y) / 2;
  centre_.z = min_.z + (max_.z - min_.z) / 2;

  return VerifyExecution::kExecution;
}

void FindMinMax::InitMinMax(Data3DModel::Coordinate &vertex) {
  min_.x = vertex.x;
  min_.y = vertex.y;
  min_.z = vertex.z;
  max_.x = vertex.x;
  max_.y = vertex.y;
  max_.z = vertex.z;
}

Event::VerifyExecution FindMax::Execute(s21::Data3DModel *data,
                                        Command command) {
  //Надо проверить нашли ли мы максимальные точки
  double x = max_.x - min_.x, y = max_.y - min_.y, z = max_.z - min_.z;
  if (x > y && y > z)
    scale_for_centre_.x = x;
  else if (y > x && x > z)
    scale_for_centre_.y = y;
  else
    scale_for_centre_.z = z;
}

Event::VerifyExecution FindCentre::Execute(s21::Data3DModel *data,
                                           Command command) {
  //Надо проверить нашли ли мы центр
}

} // namespace s21