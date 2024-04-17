#include "view.h"

#include <iostream>

#include "ui_mainwindow.h"

namespace s21 {

View::View(QWidget *parent, s21::Controller *controller)
    : ui(new Ui::View), controller_(controller) {
  ui->setupUi(this);
  setWindowTitle("3D Viewer");
  timer = new QTimer(0);

  //Инициализация окна GLWidget
  gl_widget_ = new GLWidget(nullptr, controller);
  gl_widget_->setFixedSize(900, 720);
  QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
  layout->addWidget(gl_widget_);

  //  connect(timer, SIGNAL(timeout()), this, SLOT(createAnimation()));

  connect(ui->OpenFilePushButtonClicked, SIGNAL(clicked()), this,
          SLOT(OpenFilePushButtonClicked()));
  connect(ui->CleanPushButtonClicked, SIGNAL(clicked()), this,
          SLOT(CleanPushButtonClicked()));
}

View::~View() {
  //  writeSettings();
  //  free_mem(&data_from_3d_model);
  delete timer;
  delete ui;
}

void View::OpenFilePushButtonClicked() {
  file_path_ = QFileDialog::getOpenFileName(this, "Выбрать файл", "/Users",
                                            "All Files (*.obj)");
  ui->vertexCount->setText("");
  ui->polygonCount->setText("");
  if (controller_->GetStringFilePath(file_path_)) {
    ui->vertexCount->setText(
        QString::number(controller_->GetData().GetCoordinateVertex().size()));
    ui->polygonCount->setText(
        QString::number(controller_->GetData().GetStringPolygon().size()));
    QFileInfo check_file(file_path_);
    ui->fileNameLabel->setText(check_file.fileName());
    update();
  }
}

void View::SetBckgColorClicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  gl_widget_->backroundColor = color;
  gl_widget_->update();
}

void View::SetLinesColorClicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  gl_widget_->linesColor = color;
  gl_widget_->update();
}

void View::SetVertexesColorClicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  gl_widget_->vertexesColor = color;
  gl_widget_->update();
}

// Clear Screen
void View::CleanPushButtonClicked() {
  file_path_ = "";
  on_SetDefault_button_clicked();
  ui->fileNameLabel->setText("");
  ui->polygonCount->setText("");
  ui->vertexCount->setText("");
  gl_widget_->clearOpenGlWidget();
  controller_->GetData().ClearData();
}

void View::on_SetDefault_button_clicked() {
  gl_widget_->backroundColor = QColor(Qt::black);
  gl_widget_->linesColor = QColor(Qt::white);
  gl_widget_->vertexesColor = QColor(Qt::white);
  gl_widget_->lineWidth = 1;
  ui->lineSizeEditer->setValue(1);
  gl_widget_->vertexSize = 1;
  ui->vertexSizeEditer->setValue(0);
  ui->projectionType->setCurrentIndex(0);
  ui->vertexesType->setCurrentIndex(0);
  ui->linesType->setCurrentIndex(0);
  gl_widget_->projection = GLWidget::CENTRAL;
  gl_widget_->lineType = GLWidget::SOLID;
  gl_widget_->vertexType = GLWidget::NONE;
  gl_widget_->xRot = 0;
  gl_widget_->yRot = 0;
  gl_widget_->zRot = 0;

  //   Ставим на изначальное положение объект
  //    if (all_data.polygons_value != NULL &&
  //        all_data.vertex_value != NULL) {
  //      set_center(&all_data, 0, 0, 0, 0);
  //    }

  ui->ROTATE_X_VALUE->setValue(0);
  ui->ROTATE_Y_VALUE->setValue(0);
  ui->ROTATE_Z_VALUE->setValue(0);

  // Clean Move
  ui->doubleSpinBox_X_MOVE->setValue(0);
  ui->doubleSpinBox_Y_MOVE->setValue(0);
  ui->doubleSpinBox_MOVE_Z->setValue(0);

  update();
}

//// BONUS PART 1
// void View::on_linesType_activated(int index) {
//   if (index == 0) {
//     lineType = View::SOLID;
//   } else if (index == 1) {
//     lineType = View::DASHED;
//   }
//   update();
// }
//
// void View::on_lineSizeEditer_valueChanged(int value) {
//   lineWidth = value;
//   update();
// }
//
// void View::on_vertexesType_activated(int index) {
//   if (index == 0) {
//     vertexType = View::NONE;
//   } else if (index == 1) {
//     vertexType = View::CIRCLE;
//   } else if (index == 2) {
//     vertexType = View::SQUARE;
//   }
//   update();
// }
//
// void View::on_vertexSizeEditer_valueChanged(int value) {
//   vertexSize = value;
//   update();
// }
//
// void View::on_projectionType_activated(int index) {
//   if (index == 0) {
//     projection = View::CENTRAL;
//   } else if (index == 1) {
//     projection = View::PARALLEL;
//   }
//   update();
// }

// void View::writeSettings() {
//   QString pathSettings = QCoreApplication::applicationDirPath();
//   QSettings settings(pathSettings + "/settings.ini", QSettings::IniFormat);
//   settings.beginGroup("settings");
//
//   settings.setValue("file_path_", file_path_);
//   settings.setValue("backgroundColor", ui.);
//   settings.setValue("linesColor", linesColor);
//   settings.setValue("vertexesColor", vertexesColor);
//   settings.setValue("lineSizeEditer", ui->lineSizeEditer->value());
//   settings.setValue("lineWidth", lineWidth);
//   settings.setValue("vertexSize", vertexSize);
//   settings.setValue("vertexSizeEditer", ui->vertexSizeEditer->value());
//
//   settings.setValue("vertexesType", ui->vertexesType->currentIndex());
//   settings.setValue("linesType", ui->linesType->currentIndex());
//   settings.setValue("projectionType", ui->projectionType->currentIndex());
//
//   settings.setValue("lineType", lineType);
//   settings.setValue("vertexType", vertexType);
//   settings.setValue("projection", projection);
//
//   settings.setValue("xRot", xRot);
//   settings.setValue("yRot", yRot);
//   settings.setValue("zRot", zRot);
//
//   settings.endGroup();
// }
//
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
//     free_mem(&all_data);
//
//     QByteArray Len = file_path_.toLocal8Bit();
//     char *Str = Len.data();
//     ui->fileNameLabel->setText(check_file.fileName());
//     if (read_file(&all_data, Str) == 0) {
//       ui->vertexCount->setText(
//           QString::number(all_data.vertexes / 3));
//       ui->polygonCount->setText(
//           QString::number(all_data.polygon / 4));
//       onOpenFile();
//     } else {
//       free_mem(&all_data);
//       ui->vertexCount->setText("");
//       ui->polygonCount->setText("");
//     }
//   }
//
//   backroundColor =
//       QColor(settings.value("backgroundColor",
//       QColor(Qt::black)).toString());
//   linesColor =
//       QColor(settings.value("linesColor", QColor(Qt::white)).toString());
//   vertexesColor =
//       QColor(settings.value("vertexesColor", QColor(Qt::white)).toString());
//
//   ui->lineSizeEditer->setValue(settings.value("lineSizeEditer", 1).toInt());
//   lineWidth = settings.value("lineWidth", 1).toInt();
//
//   ui->vertexSizeEditer->setValue(settings.value("vertexSizeEditer",
//   1).toInt()); vertexSize = settings.value("vertexSize",
//   1).toInt();
//
//   ui->vertexesType->setCurrentIndex(settings.value("vertexesType",
//   0).toInt()); ui->linesType->setCurrentIndex(settings.value("linesType",
//   0).toInt()); ui->projectionType->setCurrentIndex(
//       settings.value("projectionType", 0).toInt());
//
//   lineType = static_cast<View::linesType>(
//       settings.value("lineType", View::SOLID).toInt());
//   vertexType = static_cast<View::vertexesType>(
//       settings.value("vertexType", View::NONE).toInt());
//   projection = static_cast<View::projectionType>(
//       settings.value("projection", View::CENTRAL).toInt());
//
//   xRot = settings.value("xRot", 0).toDouble();
//   yRot = settings.value("yRot", 0).toDouble();
//   zRot = settings.value("zRot", 0).toDouble();
//
//   settings.endGroup();
// }

// AFFINE_TRANSFORMATIONS

/*             MOVE                */

// Z Axis

void View::on_B_PLUS_MOVE_Z_clicked() {
  double value = ui->doubleSpinBox_MOVE_Z->value();
  controller_->Affine(Strategy::SelectionStrategy::kMove,
                      Strategy::TypeCoordinate::kZ, &controller_->GetData(),
                      value);
  gl_widget_->update();
}

void View::on_B_MINUS_MOVE_Z_clicked() {
  double value = ui->doubleSpinBox_MOVE_Z->value();
  update();
}

// Y Axis

void View::on_B_PLUS_MOVE_Y_clicked() {
  double value = ui->doubleSpinBox_Y_MOVE->value();

  update();
}

void View::on_B_MINUS_MOVE_Y_clicked() {
  double value = ui->doubleSpinBox_Y_MOVE->value();

  update();
}

//// X Axis

void View::on_B_PLUS_MOVE_X_clicked() {
  double value = ui->doubleSpinBox_X_MOVE->value();

  update();
}

void View::on_B_MINUS_MOVE_X_clicked() {
  double value = ui->doubleSpinBox_X_MOVE->value();
  value *= -1;

  update();
}

///*                SIZE                */
//
// void View::on_pushButton_4_clicked() {
//  double value = 1.1;
//  size_xyz(&all_data, value);
//  update();
//}
//
// void View::on_pushButton_5_clicked() {
//  double value = 0.9;
//  size_xyz(&all_data, value);
//  update();
//}
//
///*                ROTATE               */
//
//// X Axis
//
// void View::on_ROTATE_X_PLUS_clicked() {
//  int value = ui->ROTATE_X_VALUE->value();
//  rotation_x(&all_data, value);
//  update();
//}
//
// void View::on_ROTATE_X_MINUS_clicked() {
//  int value = ui->ROTATE_X_VALUE->value() * -1;
//  rotation_x(&all_data, value);
//  update();
//}
//
//// Y Axis
//
// void View::on_ROTATE_Y_PLUS_clicked() {
//  int value = ui->ROTATE_Y_VALUE->value();
//  rotation_y(&all_data, value);
//  update();
//}
//
// void View::on_ROTATE_Y_MINUS_clicked() {
//  int value = ui->ROTATE_Y_VALUE->value() * -1;
//  rotation_y(&all_data, value);
//  update();
//}
//
//// Z Axis
//
// void View::on_ROTATE_Z_PLUS_clicked() {
//  int value = ui->ROTATE_Z_VALUE->value();
//  rotation_z(&all_data, value);
//  update();
//}
//
// void View::on_ROTATE_Z_MINUS_clicked() {
//  int value = ui->ROTATE_Z_VALUE->value() * -1;
//  rotation_z(&all_data, value);
//  update();
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
//     QImage screen = grabFramebuffer();
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
//     QImage screen = grabFramebuffer();
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

}  // namespace s21
