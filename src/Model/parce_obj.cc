#include <sstream>

#include "model.h"

/*!
 * \brief read file
 *\authors Dimitraki Vladimir
 * opens the file and reads the coordinates of vertices and polygons
 * from it to write the data to the Data3DModel structure.
 */
namespace s21 {
bool ParseObj::ParseObjFile(std::string &file_path, s21::Data3DModel *data) {
  bool state_file = true;
  std::ifstream file;
  file.open(file_path);

  if (file.is_open()) {
    while (std::getline(file, string_data_from_file_)) {
      WriteVertexes(data);
      ParsePolygons(data);
      lexeme_.CheckLexem(data);
    }
    file.close();
  } else {
    state_file = false;
  }
  return state_file;
}

void ParseObj::WriteVertexes(Data3DModel *data) {
  Data3DModel::Coordinate coordinate;
  char symble = '\0';
  std::stringstream ss(string_data_from_file_);

  if (ss >> symble >> coordinate.x >> coordinate.y >> coordinate.z &&
      symble == 'v') {
    data->GetCoordinateVertex().push_back(coordinate);
  }
}

void ParseObj::ParsePolygons(Data3DModel *data) {
  bool is_first = true;

  int first_polygon = 0;

  int num = 0;
  size_t id = 0, i = 0;

  if (string_data_from_file_[i] == 'f' &&
      string_data_from_file_[i + 1] == ' ') {
    for (; i < string_data_from_file_.length(); ++i) {
      if (std::isdigit(string_data_from_file_[i]) ||
          string_data_from_file_[i] == '-') {
        num = std::stoi(&string_data_from_file_[i], &id);
        i += id;
        NegativePolygons(&num, data);
        FirstPolygon(&is_first, &first_polygon, &num, data);
        for (; i < string_data_from_file_.length() &&
               string_data_from_file_[i] != ' ';
             ++i) {
        }
      }
    }
    data->GetStringPolygon().push_back(first_polygon);
  }
}

void ParseObj::NegativePolygons(int *num, Data3DModel *data) {
  if (*num > 0)
    *num -= 1;
  else
    *num = data->GetCoordinateVertex().size() - abs(*num);
  data->GetStringPolygon().push_back(*num);
}

void ParseObj::FirstPolygon(bool *is_first, int *first_polygon, int *num,
                            Data3DModel *data) {
  if (*is_first) {
    *first_polygon = *num;
    *is_first = false;
  } else {
    data->GetStringPolygon().push_back(*num);
  }
}

}  // namespace s21
