#ifndef INC_3DVIEWER_2_DATA3DMODEL_H
#define INC_3DVIEWER_2_DATA3DMODEL_H

namespace s21 {
/*!
 * \brief Class for storage data
 *\authors Dimitraki Vladimir
 */
class Data3DModel {
public:
  Data3DModel() : vertexes_(0), polygons_(0) {}
  ~Data3DModel() {}

  int &GetVertexes() { return vertexes_; }
  int &GetPolygons() { return polygons_; }
  std::vector<double> &GetCoordinateVertex() { return coordinates_vertex_; }
  std::vector<int> &GetStringPolygon() { return string_polygon_; }

private:
  int vertexes_, polygons_;
  std::vector<double> coordinates_vertex_;
  std::vector<int> string_polygon_;
};
} // namespace s21

#endif // INC_3DVIEWER_2_DATA3DMODEL_H
