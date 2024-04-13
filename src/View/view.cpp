#include "view.h"

#include <iostream>

#include "ui_mainwindow.h"

View::View(QWidget *parent, s21::Controller *controller)
    : QOpenGLWidget(parent), ui(new Ui::View), controller_(controller) {
  ui->setupUi(this);
  setWindowTitle("3D Viewer");
  timer = new QTimer(0);
//  connect(timer, SIGNAL(timeout()), this, SLOT(createAnimation()));
}

View::~View() {
  //  writeSettings();
  //  free_mem(&ui->myGl->data_from_3d_model);
  delete timer;
  delete ui;
}

void View::on_openFilePushBtn_clicked() {
  file_path_ = QFileDialog::getOpenFileName(this, "Выбрать файл", "/Users",
                                            "All Files (*.obj)");
  ui->vertexCount->setText("");
  ui->polygonCount->setText("");
  if (controller_->GetStringFilePath(file_path_)) {
      ui->vertexCount->setText(QString::number(controller_->GetData().GetCoordinateVertex().size()));
      ui->polygonCount->setText(QString::number(controller_->GetData().GetStringPolygon().size()));
      QFileInfo check_file(file_path_);

      ui->fileNameLabel->setText(check_file.fileName());

//      for (const auto &i: controller_->GetData().GetStringPolygon()) {
//          std::cout << i << ' ';
//      }
//      std::cout << std::endl;
//      for (const auto &i: controller_->GetData().GetCoordinateVertex()) {
//          std::cout << i << ' ';
//      }
      ui->myGl->update();
  }
}

void View::on_setBckgColor_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
//  ui->myGl->backroundColor = color;
    backroundColor = color;
    ui->myGl->update();
}

void View::on_setLinesColor_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
//  ui->myGl->linesColor = color;
    linesColor = color;
  ui->myGl->update();
}

void View::on_setVertexesColor_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
//  ui->myGl->vertexesColor = color;
    vertexesColor = color;
  ui->myGl->update();
}

// Clear Screen
void View::on_cleanPushButton_clicked() {
  // Очищаем виджет Open GL
  // Зануляем все настройки
  file_path_ = "";
  on_SetDefault_button_clicked();

  ui->fileNameLabel->setText("");
  ui->polygonCount->setText("");
  ui->vertexCount->setText("");
  //  ui->myGl->clearOpenGlWidget();
  //  free_mem(&ui->myGl->all_data);
}

void View::on_SetDefault_button_clicked() {
//  ui->myGl->
  backroundColor = QColor(Qt::black);
//  ui->myGl->
  linesColor = QColor(Qt::white);
//  ui->myGl->
  vertexesColor = QColor(Qt::white);
//  ui->myGl->
  lineWidth = 1;
  ui->lineSizeEditer->setValue(1);
//  ui->myGl->
  vertexSize = 1;
  ui->vertexSizeEditer->setValue(0);
  ui->projectionType->setCurrentIndex(0);
  ui->vertexesType->setCurrentIndex(0);
  ui->linesType->setCurrentIndex(0);
//  ui->myGl->
  projection = View::CENTRAL;
//  ui->myGl->
  lineType = View::SOLID;
//  ui->myGl->
  vertexType = View::NONE;
//  ui->myGl->
  xRot = 0;
//  ui->myGl->
  yRot = 0;
//  ui->myGl->
  zRot = 0;

////   Ставим на изначальное положение объект
//    if (ui->myGl->all_data.polygons_value != NULL &&
//        ui->myGl->all_data.vertex_value != NULL) {
//      set_center(&ui->myGl->all_data, 0, 0, 0, 0);
//    }

  ui->ROTATE_X_VALUE->setValue(0);
  ui->ROTATE_Y_VALUE->setValue(0);
  ui->ROTATE_Z_VALUE->setValue(0);

  // Clean Move
  ui->doubleSpinBox_X_MOVE->setValue(0);
  ui->doubleSpinBox_Y_MOVE->setValue(0);
  ui->doubleSpinBox_MOVE_Z->setValue(0);

  ui->myGl->update();
}

//// BONUS PART 1
// void View::on_linesType_activated(int index) {
//   if (index == 0) {
//     ui->myGl->lineType = View::SOLID;
//   } else if (index == 1) {
//     ui->myGl->lineType = View::DASHED;
//   }
//   ui->myGl->update();
// }
//
// void View::on_lineSizeEditer_valueChanged(int value) {
//   ui->myGl->lineWidth = value;
//   ui->myGl->update();
// }
//
// void View::on_vertexesType_activated(int index) {
//   if (index == 0) {
//     ui->myGl->vertexType = View::NONE;
//   } else if (index == 1) {
//     ui->myGl->vertexType = View::CIRCLE;
//   } else if (index == 2) {
//     ui->myGl->vertexType = View::SQUARE;
//   }
//   ui->myGl->update();
// }
//
// void View::on_vertexSizeEditer_valueChanged(int value) {
//   ui->myGl->vertexSize = value;
//   ui->myGl->update();
// }
//
// void View::on_projectionType_activated(int index) {
//   if (index == 0) {
//     ui->myGl->projection = View::CENTRAL;
//   } else if (index == 1) {
//     ui->myGl->projection = View::PARALLEL;
//   }
//   ui->myGl->update();
// }

// void View::writeSettings() {
//   QString pathSettings = QCoreApplication::applicationDirPath();
//   QSettings settings(pathSettings + "/settings.ini", QSettings::IniFormat);
//   settings.beginGroup("settings");
//
//   settings.setValue("file_path_", file_path_);
//
//   settings.setValue("backgroundColor", ui->myGl->backroundColor);
//   settings.setValue("linesColor", ui->myGl->linesColor);
//   settings.setValue("vertexesColor", ui->myGl->vertexesColor);
//   settings.setValue("lineSizeEditer", ui->lineSizeEditer->value());
//   settings.setValue("lineWidth", ui->myGl->lineWidth);
//   settings.setValue("vertexSize", ui->myGl->vertexSize);
//   settings.setValue("vertexSizeEditer", ui->vertexSizeEditer->value());
//
//   settings.setValue("vertexesType", ui->vertexesType->currentIndex());
//   settings.setValue("linesType", ui->linesType->currentIndex());
//   settings.setValue("projectionType", ui->projectionType->currentIndex());
//
//   settings.setValue("lineType", ui->myGl->lineType);
//   settings.setValue("vertexType", ui->myGl->vertexType);
//   settings.setValue("projection", ui->myGl->projection);
//
//   settings.setValue("xRot", ui->myGl->xRot);
//   settings.setValue("yRot", ui->myGl->yRot);
//   settings.setValue("zRot", ui->myGl->zRot);
//
//   settings.endGroup();
// }

// void View::readSettings() {
//   QString pathSettings = QCoreApplication::applicationDirPath();
//   QSettings settings(pathSettings + "/settings.ini", QSettings::IniFormat);
//   settings.beginGroup("settings");
//
//   file_path_ = settings.value("file_path_", "").toString();
//
//   QFileInfo check_file(file_path_);
//
//   if (check_file.exists(file_path_)) {
//     free_mem(&ui->myGl->all_data);
//
//     QByteArray Len = file_path_.toLocal8Bit();
//     char *Str = Len.data();
//     ui->fileNameLabel->setText(check_file.fileName());
//     if (read_file(&ui->myGl->all_data, Str) == 0) {
//       ui->vertexCount->setText(
//           QString::number(ui->myGl->all_data.vertexes / 3));
//       ui->polygonCount->setText(
//           QString::number(ui->myGl->all_data.polygon / 4));
//       ui->myGl->onOpenFile();
//     } else {
//       free_mem(&ui->myGl->all_data);
//       ui->vertexCount->setText("");
//       ui->polygonCount->setText("");
//     }
//   }
//
//   ui->myGl->backroundColor =
//       QColor(settings.value("backgroundColor",
//       QColor(Qt::black)).toString());
//   ui->myGl->linesColor =
//       QColor(settings.value("linesColor", QColor(Qt::white)).toString());
//   ui->myGl->vertexesColor =
//       QColor(settings.value("vertexesColor", QColor(Qt::white)).toString());
//
//   ui->lineSizeEditer->setValue(settings.value("lineSizeEditer", 1).toInt());
//   ui->myGl->lineWidth = settings.value("lineWidth", 1).toInt();
//
//   ui->vertexSizeEditer->setValue(settings.value("vertexSizeEditer",
//   1).toInt()); ui->myGl->vertexSize = settings.value("vertexSize",
//   1).toInt();
//
//   ui->vertexesType->setCurrentIndex(settings.value("vertexesType",
//   0).toInt()); ui->linesType->setCurrentIndex(settings.value("linesType",
//   0).toInt()); ui->projectionType->setCurrentIndex(
//       settings.value("projectionType", 0).toInt());
//
//   ui->myGl->lineType = static_cast<View::linesType>(
//       settings.value("lineType", View::SOLID).toInt());
//   ui->myGl->vertexType = static_cast<View::vertexesType>(
//       settings.value("vertexType", View::NONE).toInt());
//   ui->myGl->projection = static_cast<View::projectionType>(
//       settings.value("projection", View::CENTRAL).toInt());
//
//   ui->myGl->xRot = settings.value("xRot", 0).toDouble();
//   ui->myGl->yRot = settings.value("yRot", 0).toDouble();
//   ui->myGl->zRot = settings.value("zRot", 0).toDouble();
//
//   settings.endGroup();
// }

// AFFINE_TRANSFORMATIONS

/*             MOVE                */

// Z Axis

// void View::on_B_PLUS_MOVE_Z_clicked() {
//   double value = ui->doubleSpinBox_MOVE_Z->value();
//
//   move_z(&ui->myGl->all_data, value);
//   ui->myGl->update();
// }
//
// void View::on_B_MINUS_MOVE_Z_clicked() {
//   double value = ui->doubleSpinBox_MOVE_Z->value();
//   value *= -1;
//   move_z(&ui->myGl->all_data, value);
//   ui->myGl->update();
// }
//
//// Y Axis
//
// void View::on_B_PLUS_MOVE_Y_clicked() {
//  double value = ui->doubleSpinBox_Y_MOVE->value();
//
//  move_y(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
// void View::on_B_MINUS_MOVE_Y_clicked() {
//  double value = ui->doubleSpinBox_Y_MOVE->value();
//  value *= -1;
//
//  move_y(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
//// X Axis
//
// void View::on_B_PLUS_MOVE_X_clicked() {
//  double value = ui->doubleSpinBox_X_MOVE->value();
//
//  move_x(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
// void View::on_B_MINUS_MOVE_X_clicked() {
//  double value = ui->doubleSpinBox_X_MOVE->value();
//  value *= -1;
//
//  move_x(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
///*                SIZE                */
//
// void View::on_pushButton_4_clicked() {
//  double value = 1.1;
//  size_xyz(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
// void View::on_pushButton_5_clicked() {
//  double value = 0.9;
//  size_xyz(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
///*                ROTATE               */
//
//// X Axis
//
// void View::on_ROTATE_X_PLUS_clicked() {
//  int value = ui->ROTATE_X_VALUE->value();
//  rotation_x(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
// void View::on_ROTATE_X_MINUS_clicked() {
//  int value = ui->ROTATE_X_VALUE->value() * -1;
//  rotation_x(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
//// Y Axis
//
// void View::on_ROTATE_Y_PLUS_clicked() {
//  int value = ui->ROTATE_Y_VALUE->value();
//  rotation_y(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
// void View::on_ROTATE_Y_MINUS_clicked() {
//  int value = ui->ROTATE_Y_VALUE->value() * -1;
//  rotation_y(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
//// Z Axis
//
// void View::on_ROTATE_Z_PLUS_clicked() {
//  int value = ui->ROTATE_Z_VALUE->value();
//  rotation_z(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}
//
// void View::on_ROTATE_Z_MINUS_clicked() {
//  int value = ui->ROTATE_Z_VALUE->value() * -1;
//  rotation_z(&ui->myGl->all_data, value);
//  ui->myGl->update();
//}

/*
 *  3th Bonus part
 *  Screenshot & Gif animation
 **/

// void View::on_createScreenPshBtn_clicked() {
//   QString fileName =
//       QFileDialog::getSaveFileName(this, "Сохранить скриншот", "/Users",
//                                    "Images (*.jpeg *.bmp);;All Files (*)");
//   if (!fileName.isEmpty()) {
//     QImage screen = ui->myGl->grabFramebuffer();
//     screen.save(fileName);
//     QMessageBox successMessage;
//     successMessage.setText("Printscreen saved successfully!");
//     successMessage.exec();
//   } else {
//     QMessageBox::warning(this, "", "Printscreen creating failed!");
//   }
// }
//
// void View::on_createGifPshBtn_clicked() {
//   gifName = QFileDialog::getSaveFileName(this, "Save gif", "/Users",
//                                          "Gif (*.gif);;All Files (*)");
//   if (!gifName.isEmpty() && !screenCounter) {
//     gifFrame = new QGifImage;
//     gifFrame->setDefaultDelay(10);
//     timer->setInterval(100);
//     timer->start();
//     ui->createGifPshBtn->setEnabled(false);
//   } else {
//     QMessageBox::warning(this, "", "Gif creating failed!");
//   }
// }

// void View::createAnimation() {
//   if (screenCounter < 50) {
//     QImage screen = ui->myGl->grabFramebuffer();
//     gifFrame->addFrame(screen);
//     screenCounter++;
//     ui->createGifPshBtn->setText(QString::number(screenCounter / 10, 10));
//   } else {
//     QMessageBox successMessage;
//     successMessage.setText("Gif saved successfully!");
//     successMessage.exec();
//     timer->stop();
//     screenCounter = 0;
//     gifFrame->save(gifName);
//     delete gifFrame;
//     ui->createGifPshBtn->setText("Create gif");
//     ui->createGifPshBtn->setEnabled(true);
//   }
// }

//View::View(QWidget *parent)
//        : QOpenGLWidget(parent){}

void View::onOpenFile() {
    std::cout << "Vertex count: " << controller_->GetData().GetVertexes()
              << std::endl;
    std::cout << "Polygon count: " << controller_->GetData().GetPolygons()
              << std::endl;
}

void View::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(backroundColor.redF(), backroundColor.greenF(),
                 backroundColor.blueF(), backroundColor.alphaF());
}

void View::paintGL() {
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

void View::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void View::setLinesType() {
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

void View::setProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = 901.0 / 741.0;
    if (projection == PARALLEL) {
        glOrtho(-2 * aspectRatio, 2 * aspectRatio, -2, 2, 0.1, 100);
    } else if (projection == CENTRAL) {
        //    gluPerspective(24, aspectRatio, 0.1, 100);
    }
    glMatrixMode(GL_MODELVIEW);
}

void View::drawVertexes() {
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
        glPointSize(vertexSize);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_DOUBLE, 0, controller_->GetData().GetCoordinateVertex().data());
        glDrawElements(GL_POINTS, controller_->GetData().GetStringPolygon().size(),
                       GL_UNSIGNED_INT, controller_->GetData().GetStringPolygon().data());
        glDisableClientState(GL_VERTEX_ARRAY);
    }
    if (vertexType == CIRCLE) {
        glDisable(GL_POINT_SMOOTH);
    } else if (vertexType == SQUARE) {
        glDisable(GL_POINT_SPRITE);
    }
}

void View::drawLines() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, controller_->GetData().GetCoordinateVertex().data());
    glDrawElements(GL_LINES, controller_->GetData().GetStringPolygon().size(),
                   GL_UNSIGNED_INT, controller_->GetData().GetStringPolygon().data());
    glDisableClientState(GL_VERTEX_ARRAY);
}

void View::clearOpenGlWidget() {
    makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    doneCurrent();
    update();
}

void View::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void View::mouseMoveEvent(QMouseEvent *mo) {
    const float sense = 0.3f;

    xRot += sense * (mo->pos().y() - mPos.y());
    yRot += sense * (mo->pos().x() - mPos.x());
    mPos = mo->pos();
    update();
}

//double *View::ConvertToDoubleString() {
//    size_t j = 0;
//    double *vertexes_string_;
//    for (auto &i : controller_->GetData().GetCoordinateVertex()) {
//        vertexes_string_[j++] = i;
//        std::cout << vertexes_string_[j] << std::endl;
//    }
//    return vertexes_string_;
//}
//
//int *View::ConvertToIntString() {
//    size_t j = 0;
//    int *polygons_string_;
//    for (auto &i : controller_->GetData().GetStringPolygon()) {
//        polygons_string_[j++] = i;
//        std::cout << polygons_string_[j] << std::endl;
//    }
//    return polygons_string_;
//}
