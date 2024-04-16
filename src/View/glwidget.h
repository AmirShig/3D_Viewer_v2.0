//
// Created by Raisin Ibben on 16/04/2024.
//

#ifndef INC_3DVIEWER_2_SRC_VIEW_GLWIDGET_H_

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
#include "qopenglwindow.h"

namespace s21 {

class GLWidget : public QOpenGLWidget {
 public:
  enum linesType { SOLID, DASHED };
  enum vertexesType { NONE, CIRCLE, SQUARE };
  enum projectionType { CENTRAL, PARALLEL };

  GLWidget(QWidget *parent = nullptr, s21::Controller *c = nullptr);

  void SetController(s21::Controller *c) { controller_ = c; }

  float xRot, yRot, zRot;
  QPoint mPos;

  int widgetWidth = width();
  int widgetHeight = height();

  QColor backroundColor;
  QColor vertexesColor;
  QColor linesColor;

  int lineWidth;
  int vertexSize;

  linesType lineType;
  vertexesType vertexType;
  projectionType projection;

  void onOpenFile();
  void clearOpenGlWidget();
  void setProjection();
  void drawVertexes();
  void setLinesType();
  void drawLines();

  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;

  //Принимаем контроллер для изменения данных в методе SetData()
  void SetData(s21::Controller *c);

 private:
  s21::Controller *controller_;
};

}  // namespace s21

#define INC_3DVIEWER_2_SRC_VIEW_GLWIDGET_H_

#endif  // INC_3DVIEWER_2_SRC_VIEW_GLWIDGET_H_
