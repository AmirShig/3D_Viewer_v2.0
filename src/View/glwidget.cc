#include "view.h"

GLWidget::GLWidget(QWidget *parent, s21::Controller *c)
    : QOpenGLWidget(parent), controller_(c) {}

void GLWidget::SetData(s21::Controller *c) {
  controller_->GetData().GetStringPolygon() = c->GetData().GetStringPolygon();
  controller_->GetData().GetCoordinateVertex() =
      c->GetData().GetCoordinateVertex();
}

void GLWidget::onOpenFile() {
  std::cout << "Vertex count: " << controller_->GetData().GetVertexes()
            << std::endl;
  std::cout << "Polygon count: " << controller_->GetData().GetPolygons()
            << std::endl;
}

void GLWidget::initializeGL() {
  glClearColor(backroundColor.redF(), backroundColor.greenF(),
               backroundColor.blueF(), backroundColor.alphaF());
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(backroundColor.redF(), backroundColor.greenF(),
               backroundColor.blueF(), backroundColor.alphaF());
  glTranslated(0, 0, -10);
  glRotatef(xRot, 1, 0, 0);
  glRotatef(yRot, 0, 1, 0);
  setProjection();
  drawVertexes();
  setLinesType();
  drawLines();
}

void GLWidget::resizeGL(int w, int h) {
  //  glGLWidgetport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void GLWidget::setLinesType() {
  if (lineType == DASHED) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }

  if (!linesColor.isValid()) {
    linesColor = QColor(Qt::white);
  } else {
    glColor3f(linesColor.redF(), linesColor.greenF(), linesColor.blueF());
  }
  glLineWidth(lineWidth);
}

void GLWidget::setProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float aspectRatio = 901.0 / 741.0;
  if (projection == PARALLEL) {
    glOrtho(-2 * aspectRatio, 2 * aspectRatio, -2, 2, 0.1, 100);
  } else if (projection == CENTRAL) {
    gluPerspective(24, aspectRatio, 0.1, 100);
  }
  glMatrixMode(GL_MODELVIEW);
}

void GLWidget::drawVertexes() {
  if (vertexType == CIRCLE) {
    glEnable(GL_POINT_SMOOTH);
  } else if (vertexType == SQUARE) {
    glEnable(GL_POINT_SPRITE);
  }

  if (vertexType != NONE) {
    if (!vertexesColor.isValid()) {
      vertexesColor = QColor(Qt::white);
    } else {
      glColor3f(vertexesColor.redF(), vertexesColor.greenF(),
                vertexesColor.blueF());
    }
    glPointSize(controller_->GetData().GetCoordinateVertex().size() / 3);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0,
                    controller_->GetData().GetCoordinateVertex().data());
    glDrawElements(GL_POINTS, controller_->GetData().GetStringPolygon().size(),
                   GL_UNSIGNED_INT,
                   controller_->GetData().GetStringPolygon().data());
    glDisableClientState(GL_VERTEX_ARRAY);
  }
  if (vertexType == CIRCLE) {
    glDisable(GL_POINT_SMOOTH);
  } else if (vertexType == SQUARE) {
    glDisable(GL_POINT_SPRITE);
  }
}

void GLWidget::drawLines() {
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0,
                  controller_->GetData().GetCoordinateVertex().data());
  glDrawElements(GL_LINES, controller_->GetData().GetStringPolygon().size(),
                 GL_UNSIGNED_INT,
                 controller_->GetData().GetStringPolygon().data());
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::clearOpenGlWidget() {
  makeCurrent();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  doneCurrent();
  update();
}

void GLWidget::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mo) {
  const float sense = 0.3f;

  xRot += sense * (mo->pos().y() - mPos.y());
  yRot += sense * (mo->pos().x() - mPos.x());
  mPos = mo->pos();
  update();
}

// double *GLWidget::ConvertToDoubleString() {
//     size_t j = 0;
//     double *vertexes_string_;
//     for (auto &i : controller_->GetData().GetCoordinateVertex()) {
//         vertexes_string_[j++] = i;
//         std::cout << vertexes_string_[j] << std::endl;
//     }
//     return vertexes_string_;
// }
//
// int *GLWidget::ConvertToIntString() {
//     size_t j = 0;
//     int *polygons_string_;
//     for (auto &i : controller_->GetData().GetStringPolygon()) {
//         polygons_string_[j++] = i;
//         std::cout << polygons_string_[j] << std::endl;
//     }
//     return polygons_string_;
// }
