#include "view.h"

namespace s21 {

GLWidget::GLWidget(QWidget *parent, s21::Controller *c)
    : QOpenGLWidget(parent), controller_(c) {
  scaleMatrix.setToIdentity();
}

void GLWidget::SetData(s21::Controller *c) {
  controller_->GetData().GetStringPolygon() = c->GetData().GetStringPolygon();
  controller_->GetData().GetCoordinateVertex() =
      c->GetData().GetCoordinateVertex();
}

void GLWidget::initializeGL() {
  glClearColor(backroundColor.redF(), backroundColor.greenF(),
               backroundColor.blueF(), backroundColor.alphaF());
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::setScale(float scale) {
//  scaleMatrix.setToIdentity();
  scaleMatrix.scale(scale, scale, scale);
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
  glMultMatrixf(scaleMatrix.data());
  setProjection();
  drawVertexes();
  setLinesType();
  drawLines();
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
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

void GLWidget::wheelEvent(QWheelEvent *event) {
  const float scaleFactor = 0.9f;

  if (event->angleDelta().y() > 0) {
    setScale(scaleFactor);
  } else {
    setScale(1.0f / scaleFactor);
  }
  update();
}


}  // namespace s21
