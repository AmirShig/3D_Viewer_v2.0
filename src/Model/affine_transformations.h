#include "data_3d_model.h"

namespace s21 {

/*!
 * \brief Абстрактный класс стратегия
 * \param coordinate перечисление для типа координат
 */
class Strategy {
public:
  enum coordinate { Y, Z };
  virtual void Transformations(Data3DModel *data, double point,
                               coordinate coordinate_x_y_z) = 0;
};

class MoveObj : public Strategy {
  void Transformations(s21::Data3DModel *data, double point,
                       coordinate coordinate_x_y_z) override;
};

class RotateObj : public Strategy {
  void Transformations(s21::Data3DModel *data, double point,
                       coordinate coordinate_x_y_z) override;
};

class DistanceObj : public Strategy {
  void Transformations(s21::Data3DModel *data, double point,
                       coordinate coordinate_x_y_z) override;
};

class AffineTransformations {
public:
  AffineTransformations(Strategy *concrete_strategy)
      : strategy_(concrete_strategy) {}

  void SetAffinneTransformations(Strategy *concrete_strategy);
  void Transformations(Data3DModel *data, double point, Strategy::coordinate coordinate_x_y_z);

private:
  Strategy *strategy_;
};

} // namespace s21