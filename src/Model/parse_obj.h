#include <fstream>
#include <sstream>

#include "data_3d_model.h"

namespace s21 {

class ParseObj {
 public:
  bool ParseObjFile(std::string &file_path, Data3DModel *data);
  void WriteVertexes(Data3DModel *data);
  void ParsePolygons(Data3DModel *data);
  void NegativePolygons(int *num, Data3DModel *data);
  void FirstPolygon(bool *is_first, int *lust_polygon, int *num,
                    Data3DModel *data);

 private:
  std::string string_data_from_file_;
  std::string file_name_;
  Data3DModel::Coordinate coordinate_;
};

}  // namespace s21