#include "model.h"

/*!
 * \brief read file
 *\authors Dimitraki Vladimir
 * opens the file and reads the coordinates of vertices and polygons
 * from it to write the data to the Data3DModel structure.
 */
namespace s21 {
void ParseObj::ParseObjFile(std::string &file_path, s21::Data3DModel *data) {
  std::ifstream file;

  file.open(file_path);
  if (file.is_open()) {
    while (std::getline(file, string_data_from_file_)) {
      WriteVertexes(data);
      WritePolygons(data);
    }
    file.close();
  }
  int p = 0;
  for (auto &i : data->GetCoordinateVertex()) {
    if (p == 3) {
      p = 0;
      std::cout << std::endl;
    }
    std::cout << i << " ";
    ++p;
  }
}

void ParseObj::WriteVertexes(Data3DModel *data) {
  std::string string_data;
  double x = 0, y = 0, z = 0;
  char s = ' ';

  std::stringstream convert_string(string_data_from_file_);
  if (convert_string >> s >> x >> y >> z && s == 'v') {
    data->GetVertexes()++;
    data->GetCoordinateVertex().push_back(x);
    data->GetCoordinateVertex().push_back(y);
    data->GetCoordinateVertex().push_back(z);
  }
}

void ParseObj::WritePolygons(Data3DModel *data) {
  size_t i = 0;
  if (string_data_from_file_[i] == 'f' &&
      string_data_from_file_[i + 1] == ' ') {
    for (; i < string_data_from_file_.size(); ++i) {
      if (std::isdigit(string_data_from_file_[i]) &&
          string_data_from_file_[i + 1] == '/') {
        data->GetPolygons()++;
        data->GetStringPolygon().push_back(string_data_from_file_[i]);
        std::cout << string_data_from_file_[i] << std::endl;
        while (string_data_from_file_.size() > i &&
               string_data_from_file_[i] != ' ') {
          ++i;
        }
      }
    }
  }
}

} // namespace s21

// f 1/1/1 5/2/1 7/3/1 3/4/1
// f 4/5/2 3/4/2 7/6/2 8/7/2
// f 8/8/3 7/9/3 5/10/3 6/11/3
// f 6/12/4 2/13/4 4/5/4 8/14/4
// f 2/13/5 1/1/5 3/4/5 4/5/5
// f 6/11/6 5/10/6 1/1/6 2/13/6