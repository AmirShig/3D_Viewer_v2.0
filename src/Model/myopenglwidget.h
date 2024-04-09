#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#define GL_SILENCE_DEPRECATION
#include "../Model/render_3d_model.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QWidget>
#include <QtOpenGLWidgets/qopenglwidget.h>
#include "qopenglwindow.h"

class MyOpenGLWidget : public QOpenGLWidget {
  Q_OBJECT
public:
  MyOpenGLWidget(QWidget *parent = nullptr);

  enum linesType { SOLID, DASHED };
  enum vertexesType { NONE, CIRCLE, SQUARE };
  enum projectionType { CENTRAL, PARALLEL };

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

  /*!
   * \brief *ConvertToDoubleString(); *ConvertToIntString();
   *\authors Dimitraki Vladimir
   * конвертированные строки (из вектора в простой массив) для glVertexPointer()
   */
  double *ConvertToDoubleString();
  int *ConvertToIntString();
    /*!
      * \brief UpdateObj обноваляет данные в обекте 3д модели для отрисовки
      * \authors Dimitraki Vladimir
      * \param UpdateObj
      */
    void UpdateObj(s21::Render3DModel::Data3DModel &obj);

protected:
    /*!
   * \brief Data3DModel
   *\authors Dimitraki Vladimir
   * объект структуры данных obj
   */
  s21::Render3DModel::Data3DModel obj_;
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
};

#endif // MYOPENGLWIDGET_H
