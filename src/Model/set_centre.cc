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

  MinMax min;
  MinMax max;

  //Надо проверить нашли ли мы минимальные и максимальные точки
  for (auto &vertex : data->GetCoordinateVertex()) {
    min.x = vertex.x;
    min.y = vertex.y;
    min.z = vertex.z;
    max.x = vertex.x;
    max.y = vertex.y;
    max.z = vertex.z;

  }

  return VerifyExecution::kExecution;
}

Event::VerifyExecution FindMax::Execute(s21::Data3DModel *data,
                                        Command command) {
  //Надо проверить нашли ли мы максимальные точки
}

Event::VerifyExecution FindCentre::Execute(s21::Data3DModel *data,
                                           Command command) {
  //Надо проверить нашли ли мы центр
}

} // namespace s21