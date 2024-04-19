#include "model.h"

/*!
 * \brief абстрактный класс
 * \param FindMinMax виртуальный метод для поиска максимальных и минимальных
 * координат
 */
namespace s21 {

class Find {
public:
  enum class TypeCentreCoordinate { kX, kY, kZ };

  virtual void FindMinMax(Data3DModel *data, point) = 0;
};

class FindX : public Find {
public:
  void FindMinMax() override;
};

class FindY : public Find {
public:
  void FindMinMax() override;
};

class FindZ : public Find {
public:
  void FindMinMax() override;
};

class Centre {
public:
  Centre() {}

  Centre(Find *strategy) : strategy_(strategy) {}

  void SetStrategy();
  void FindMinMax();

private:
  Find *strategy_;
};
} // namespace s21