#ifndef INC_3DVIEWER_2_DATA3DMODEL_H
#define INC_3DVIEWER_2_DATA3DMODEL_H

#include <iostream>
#include <vector>

namespace s21 {
/*!
 * \brief Class for storage data
 *\authors Dimitraki Vladimir
 */
class Data3DModel {
 public:
  Data3DModel() {}
  ~Data3DModel() {}

  std::vector<double> &GetCoordinateVertex() { return coordinates_vertex_; }
  std::vector<int> &GetStringPolygon() { return string_polygon_; }
  void ClearData();

 private:
  std::vector<double> coordinates_vertex_;
  std::vector<int> string_polygon_;
};
}  // namespace s21

#endif  // INC_3DVIEWER_2_DATA3DMODEL_H
