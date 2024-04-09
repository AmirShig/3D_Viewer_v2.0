#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model m;
  s21::Controller c(&m);
  MainWindow w(nullptr, &c);
  w.show();
  //  w.readSettings();
  return a.exec();
}
