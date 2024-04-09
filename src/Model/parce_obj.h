#ifndef INC_3DVIEWER_2_READFILE_H
#define INC_3DVIEWER_2_READFILE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "data_3d_model.h"

namespace s21 {
/*!
 * \brief Class for render model
 *\authors Dimitraki Vladimir
 */
class ParseObj {
public:
  ParseObj() {}
  ~ParseObj() {}

  void ParseObjFile(std::string &file_path, Data3DModel *data);
  void WriteVertexes(Data3DModel *data);
  void WritePolygons(Data3DModel *data);
  void ParsePolygon(Data3DModel *data);

private:
  std::string string_data_from_file_;
  std::string file_name_;
};

} // namespace s21
#endif // INC_3DVIEWER_2_READFILE_H
