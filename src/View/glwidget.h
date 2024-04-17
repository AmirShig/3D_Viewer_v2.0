//
// Created by Raisin Ibben on 16/04/2024.
//

#ifndef INC_3DVIEWER_2_SRC_VIEW_GLWIDGET_H_

#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QColor>
#include <QColorDialog>
#include <QCoreApplication>
#include <QFileDialog>
#include <QMatrix4x4>
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
  enum class LinesType { kSolid, kDashed };
  enum class VertexesType { kNone, kCircle, kSquare };
  enum class ProjectionType { kCentral, kParallel };

  explicit GLWidget(QWidget *parent = nullptr, s21::Controller *c = nullptr);

  void SetController(s21::Controller *c) { controller_ = c; }
  void SetDefault();

  void SetLinesType(LinesType type) {
    lines_type_ = type;
    update();
  }

  void SetVertexesType(VertexesType type) {
    vertexes_type_ = type;
    update();
  }

  void SetProjectionType(ProjectionType type) {
    projection_type_ = type;
    update();
  }

  void SetBackgroundColor(QColor color) {
    backround_color_ = color;
    update();
  }
  void SetVertexesColor(QColor color) {
    vertexes_color_ = color;
    update();
  }
  void SetLinesColor(QColor color) {
    lines_color_ = color;
    update();
  }
  void SetVertexesSize(int size) {
    vertex_size_ = size;
    update();
  }
  void SetLinesWidth(int width) {
    line_width_ = width;
    update();
  }

  QColor GetBackgroundColor() { return backround_color_; }
  QColor GetVertexesColor() { return vertexes_color_; }
  QColor GetLinesColor() { return lines_color_; }
  [[nodiscard]] int GetLineWidth() const { return line_width_; }
  [[nodiscard]] int GetVertexSize() const { return vertex_size_; }
  LinesType GetLinesType() { return lines_type_; }
  VertexesType GetVertexesType() { return vertexes_type_; }
  ProjectionType GetProjectionType() { return projection_type_; }

  void clearOpenGlWidget();

  //Принимаем контроллер для изменения данных в методе SetData()
  void SetData(s21::Controller *c);

 private:
  s21::Controller *controller_;
  float x_rot_, y_rot_, zRot;
  QPoint m_pos_;
  QMatrix4x4 scale_matrix_;

  int widgetWidth = width();
  int widgetHeight = height();

  QColor backround_color_;
  QColor vertexes_color_;
  QColor lines_color_;
  int line_width_;
  int vertex_size_;

  LinesType lines_type_;
  VertexesType vertexes_type_;
  ProjectionType projection_type_;

  void setProjection();
  void drawVertexes();
  void setLinesType();
  void drawLines();

  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

  void wheelEvent(QWheelEvent *event) override;
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;

  void setScale(float scale);
};

}  // namespace s21

#define INC_3DVIEWER_2_SRC_VIEW_GLWIDGET_H_

#endif  // INC_3DVIEWER_2_SRC_VIEW_GLWIDGET_H_
