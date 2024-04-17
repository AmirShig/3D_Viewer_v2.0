#ifndef INC_3DVIEWER_2_MODEL_H
#define INC_3DVIEWER_2_MODEL_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "affine_transformations.h"
#include "data_3d_model.h"

namespace s21 {

/*!
 * \brief Класс разбивает строку на лексемы и отдает "чистую" строку.
 */
class Lexeme {
 public:
  /*! Очищает входную строку от линих символов */
  void CheckLexem(std::string &str, Data3DModel *data);

 private:
};

class ParseObj {
 public:
  //  ParseObj() {
  //    string_data_from_file_.reserve(1024);
  //    file_name_.reserve(1024);
  //  }
  bool ParseObjFile(std::string &file_path, Data3DModel *data);
  void WriteVertexes(Data3DModel *data);
  bool ParsePolygons(Data3DModel *data);
  void NegativePolygons(int *num, Data3DModel *data);
  void FirstPolygon(bool *is_first, int *lust_polygon, int *num,
                    Data3DModel *data);

 private:
  std::string string_data_from_file_;
  std::string file_name_;
  Lexeme lexeme_;
};

/*!
 * \brief Главный класс который реализован по паттерну "Фасад"
 */
class Model {
 public:
  //Отдать данные в Controller
  Data3DModel &GetData() { return data_; }
  bool ProccessingObjFile(std::string &file_path);
  AffineTransformations &Affine() { return *affine_; }

 private:
  Data3DModel data_;
  ParseObj parse_;
  AffineTransformations *affine_;
};

}  // namespace s21

#endif  // INC_3DVIEWER_2_MODEL_H
