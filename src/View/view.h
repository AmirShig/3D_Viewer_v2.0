#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QColor>
#include <QColorDialog>
#include <QCoreApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QPainter>
#include <QSettings>
#include <QTimer>
#include <QWidget>

#include "../Controller/controller.h"
#include "QtGifImage/gifimage/qgifimage.h"
#include "glwidget.h"
#include "qopenglwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {

class View : public QWidget {
  Q_OBJECT

 public:
  enum class SelectionStrategy { kMove, kRotate, kDistance };
  View(QWidget *parent = nullptr, s21::Controller *controller = nullptr);
  ~View();

  QString file_path_;
  QString gifName;
  QGifImage *gifFrame;
  int screenCounter = 0;
  QTimer *timer;

  int rotatedX = 0;
  int rotatedY = 0;
  int rotatedZ = 0;

  // QSettings
  //  void writeSettings();
  //  void readSettings();

 private slots:
  void OpenFilePushButtonClicked();
  void SetBckgColorClicked();
  void SetLinesColorClicked();
  void SetVertexesColorClicked();

  //  void on_linesType_activated(int index);
  //  void on_lineSizeEditer_valueChanged(int value);
  //  void on_vertexesType_activated(int index);
  //  void on_vertexSizeEditer_valueChanged(int value);
  //  void on_projectionType_activated(int index);

  // Affine_Transformations
  // Move
  void on_B_PLUS_MOVE_Z_clicked();
  void on_B_MINUS_MOVE_Z_clicked();
  void on_B_PLUS_MOVE_Y_clicked();
  void on_B_MINUS_MOVE_Y_clicked();
  void on_B_PLUS_MOVE_X_clicked();
  void on_B_MINUS_MOVE_X_clicked();
  //
  //  // Size
  //  void on_pushButton_4_clicked();
  //  void on_pushButton_5_clicked();
  //
  //  // Rotate
  //  void on_ROTATE_X_PLUS_clicked();
  //  void on_ROTATE_X_MINUS_clicked();
  //  void on_ROTATE_Y_PLUS_clicked();
  //  void on_ROTATE_Y_MINUS_clicked();
  //  void on_ROTATE_Z_PLUS_clicked();
  //  void on_ROTATE_Z_MINUS_clicked();

  // SetDefault
  void on_SetDefault_button_clicked();
  void CleanPushButtonClicked();

  // Print screen & Create gif
  //  void on_createScreenPshBtn_clicked();
  //  void on_createGifPshBtn_clicked();
  //    void createAnimation();

 private:
  Ui::View *ui;
  s21::Controller *controller_;
  GLWidget *gl_widget_;

  int rotationPostition_;
};
}  // namespace s21
#endif  // MAINWINDOW_H
