#ifndef INC_3DVIEWER_2_MODEL_H
#define INC_3DVIEWER_2_MODEL_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "data_3d_model.h"

namespace s21 {

/*!
 * \brief Родительский класс наблюдатель
 * имеет в себе виртуальный метод который
 * не имеет реализации
 */
class Observer {
public:
  virtual void Update() = 0;
};

/*!
 * \brief Класс наблюдаемый
 * \param AddObserver добавляет нового наблюдателя
 * \param NotifyUpdate обновляет данные каждого наблюдателя
 */
class Observable {
public:
  void AddObserver(Observer *new_observer) {
    observers_.push_back(new_observer);
  }

  void NotifyUpdate() {
    for (auto &i : observers_) {
      i->Update();
    }
  }

private:
  std::vector<Observer *> observers_;
};

/*!
 * \brief Класс разбивает строку на лексемы и отдает "чистую" строку.
 */
class Lexeme {
public:
  /*! Очищает входную строку от линих символов */
  void CleanLexem(std::string &str);
};

class ParseObj : public Observer {
public:
  void ParseObjFile(std::string &file_path, Data3DModel *data);
  void WriteVertexes(Data3DModel *data);
  void ParsePolygons(Data3DModel *data);
  void WritePolygons();
  void CheckValidPolygons();
  //
  void Update() override;

private:
  std::string string_data_from_file_;
  std::string file_name_;
  Lexeme lexeme_;
};

/*!
 * \brief
 */
class Model : public Observable {
public:
  //Отдать данные в Controller
  Data3DModel &GetData() { return data_; }
  bool ProccessingObjFile(std::string &file_path);

private:
  Data3DModel data_;
  ParseObj *parse_;
};

} // namespace s21

#endif // INC_3DVIEWER_2_MODEL_H
