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

  virtual void Update(Event *e) = 0;

  /**
   * Передает обязанности следующему по цепочке
   * \param data данные 3d модели
   */
  virtual Event *SetNextEvent(Event *event) = 0;

  /**
   * Принимает комманду на исполнение
   * \return VerifyExecutionу успешное выполнение
   */
  virtual VerifyExecution Execute(Data3DModel *data, Command command) = 0;
  void GiveCommand(Data3DModel *data, Event *event, Event::Command command);

  MinMax centre_;
  double scale_for_centre_;
  MinMax min_;
  MinMax max_;
};

class AbstructEvent : public Event {
public:
  AbstructEvent() : next_event_(nullptr) {}
  void Update(Event *e) override;
  void Clean();
  Event *SetNextEvent(Event *event) override;
  VerifyExecution Execute(Data3DModel *data, Command command) override;

private:
  Event *next_event_;
};

class FindMinMax : public AbstructEvent {
public:
  void Update(Event *e) override;

  VerifyExecution Execute(Data3DModel *data, Command command) override;
  void InitMinMax(Data3DModel::Coordinate &vertex);
};

class FindMax : public AbstructEvent {
public:
  void Update(Event *e) override;

  VerifyExecution Execute(Data3DModel *data, Command command) override;
};

class FindCentre : public AbstructEvent {
public:
  void Update(Event *e) override;

  VerifyExecution Execute(Data3DModel *data, Command command) override;
};

} // namespace s21