#include "data_3d_model.h"
#include <istream>
#include <set>

namespace s21 {

/*!
 * \brief Главный интерфейс реализован по паттерну "Chain of responsibility"
 */
class Event {
public:
  enum class VerifyExecution { kExecution, kNotExecution };
  enum class Command { kFindMinMax, kFindMax, kFindCentre };
  struct MinMax {
    double x, y, z;
  };
  /**
   * Передает обязанности следующему по цепочке
   * \param data данные 3d модели
   */
  virtual Event *SetNextEvent(Event *event) = 0;

  /**
   * Принимает комманду на исполнение
   */
  virtual VerifyExecution Execute(Data3DModel *data, Command command) = 0;
};

class AbstructEvent : public Event {
public:
  AbstructEvent() : next_event_(nullptr) {}

  Event *SetNextEvent(Event *event) override;
  VerifyExecution Execute(Data3DModel *data, Command command) override;

private:
  Event *next_event_;
};

class FindMinMax : public AbstructEvent {
public:
  VerifyExecution Execute(Data3DModel *data, Command command) override;
};

class FindMax : public AbstructEvent {
public:
  VerifyExecution Execute(Data3DModel *data, Command command) override;
};

class FindCentre : public AbstructEvent {
public:
  VerifyExecution Execute(Data3DModel *data, Command command) override;
};

} // namespace s21