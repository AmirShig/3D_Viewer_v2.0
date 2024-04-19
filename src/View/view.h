#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define GL_SILENCE_DEPRECATION

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
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>
#include <QMainWindow>

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

class View : public QMainWindow {
  Q_OBJECT

 public:
  enum class SelectionStrategy { kMove, kRotate, kDistance };
  View(QWidget *parent = nullptr, s21::Controller *controller = nullptr);
  ~View();

  int rotatedX = 0;
  int rotatedY = 0;
  int rotatedZ = 0;

  //   QSettings
  void writeSettings();
  void readSettings();

 private slots:
  void OpenFilePushButtonClicked();
  void SetBckgColorClicked();
  void SetLinesColorClicked();
  void SetVertexesColorClicked();

  void ProjectionTypeChanged(int index);
  void LinesTypeChanged(int index);
  void VertexesTypeChanged(int index);

  void VertexSizeValueChanged(int value);
  void LinesWidthValueChanged(int value);

  // Affine_Transformations
  void ButtonPlusMoveZ();
  void ButtonMinusMoveZ();
  void ButtonPlusMoveY();
  void ButtonMinusMoveY();
  void ButtonPlusMoveX();
  void ButtonMinusMoveX();

  void ButtonPlusSize();
  void ButtonMinusSize();

  void ButtonRotatePlusX();
  void ButtonRotateMinusX();
  void ButtonRotatePlusY();
  void ButtonRotateMinusY();
  void ButtonRotatePlusZ();
  void ButtonRotateMinusZ();

  // SetDefault
  void on_SetDefault_button_clicked();
  void CleanPushButtonClicked();

  // Print screen & Create gif

  void CreateAnimation();
  void CreateScreenClicked();
  void CreateGifClicked();

 private:
  Ui::View *ui;
  s21::Controller *controller_;
  GLWidget *gl_widget_;

  QString file_path_;
  QString gif_name_;
  QGifImage *gif_frame_;
  int screen_counter_ = 0;
  QTimer *gif_timer_;

  int rotationPostition_;
};
}  // namespace s21
#endif  // MAINWINDOW_H
