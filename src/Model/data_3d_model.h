#ifndef CPP4_3DVIEWER_V2_MODEL_DATA3DMODEL_H
#define CPP4_3DVIEWER_V2_MODEL_DATA3DMODEL_H

#include <iostream>
#include <vector>

namespace s21 {
///@brief Class for storage data
class Data3DModel {
public:
  struct Coordinate {
    Coordinate() : x(0), y(0), z(0) {}
    double x, y, z;
  };
  Data3DModel() {}
  ~Data3DModel() {}

  std::vector<Coordinate> &GetCoordinateVertex() { return coordinates_vertex_; }
  std::vector<int> &GetStringPolygon() { return string_polygon_; }
  void ClearData();

private:
  std::vector<Coordinate> coordinates_vertex_;
  std::vector<int> string_polygon_;
};

} // namespace s21

#endif // CPP4_3DVIEWER_V2_MODEL_DATA3DMODEL_H
