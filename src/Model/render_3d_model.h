#ifndef INC_3DVIEWER_2_READFILE_H
#define INC_3DVIEWER_2_READFILE_H

#include "model.h"

namespace s21 {
/*!
 * \brief Class for render model
 *\authors Dimitraki Vladimir
 */
class Render3DModel : public Model {
public:
  Render3DModel() : string_data_from_file_({}), file_name_({}) {}
  ~Render3DModel() {}

  void ReadFileAndParse(std::string &file_path, Data3DModel *data);
  void WriteVertexes(Data3DModel *data);
  void WritePolygons(Data3DModel *data);
  void ParsePolygon(Data3DModel *data);

  void UpdateData(Data3DModel *data) override;

  // Accessors

private:
  std::string string_data_from_file_;
  std::string file_name_;
};

} // namespace s21
#endif // INC_3DVIEWER_2_READFILE_H
