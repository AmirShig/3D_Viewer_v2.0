#include "model.h"

namespace s21 {

/*!
 * \brief Абстрактный класс стратегия
 */
class Strategy {
public:
  virtual void Transformations(Data3DModel *data, double point) = 0;
};

class MoveObj : public Strategy {
  void Transformations(s21::Data3DModel *data, double point) override;
};

class RotateObj : public Strategy {
  void Transformations(s21::Data3DModel *data, double point) override;
};

class Distance : public Strategy {
  void Transformations(s21::Data3DModel *data, double point) override;
};

class AffineTransformations {
public:
  AffineTransformations(Strategy *concrete_strategy)
      : strategy_(concrete_strategy) {}

  void SetAffinneTransformations(Strategy *concrete_strategy);
  void Transformations(Data3DModel *data, double point);

private:
  Strategy *strategy_;
};

} // namespace s21