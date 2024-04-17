#include "view.h"

#include "ui_mainwindow.h"

namespace s21 {

View::View(QWidget *parent, s21::Controller *controller)
    : QWidget(parent), ui(new Ui::View), controller_(controller) {
  ui->setupUi(this);
  setWindowTitle("3D Viewer");
  timer = new QTimer(nullptr);
  controller_->GetData().ClearData();

  //Инициализация окна GLWidget
  gl_widget_ = new GLWidget(nullptr, controller);
  gl_widget_->setFixedSize(900, 720);
  auto *layout = new QVBoxLayout(ui->centralwidget);
  layout->addWidget(gl_widget_);

  //  connect(timer, SIGNAL(timeout()), this, SLOT(createAnimation()));
  // Open & clean
  connect(ui->OpenFilePushButtonClicked, SIGNAL(clicked()), this,
          SLOT(OpenFilePushButtonClicked()));
  connect(ui->CleanPushButtonClicked, SIGNAL(clicked()), this,
          SLOT(CleanPushButtonClicked()));
  // color buttons
  connect(ui->SetBckgColorClicked, SIGNAL(clicked()), this,
          SLOT(SetBckgColorClicked()));
  connect(ui->SetLinesColorClicked, SIGNAL(clicked()), this,
          SLOT(SetLinesColorClicked()));
  connect(ui->SetVertexesColorClicked, SIGNAL(clicked()), this,
          SLOT(SetVertexesColorClicked()));

  // Bonus part 1
  connect(ui->projectionType, SIGNAL(currentIndexChanged(int)), this,
          SLOT(ProjectionTypeChanged(int)));
  connect(ui->linesType, SIGNAL(currentIndexChanged(int)), this,
          SLOT(LinesTypeChanged(int)));
  connect(ui->VertexesType, SIGNAL(currentIndexChanged(int)), this,
          SLOT(VertexesTypeChanged(int)));

  connect(ui->lineSizeEditer, SIGNAL(valueChanged(int)), this,
          SLOT(LinesWidthValueChanged(int)));
  connect(ui->vertexSizeEditer, SIGNAL(valueChanged(int)), this,
          SLOT(VertexSizeValueChanged(int)));

  // Affine
  connect(ui->ButtonPlusMoveZ, SIGNAL(clicked()), this,
          SLOT(ButtonPlusMoveZ()));
  connect(ui->ButtonMinusMoveZ, SIGNAL(clicked()), this,
          SLOT(ButtonMinusMoveZ()));
  connect(ui->ButtonPlusMoveY, SIGNAL(clicked()), this,
          SLOT(ButtonPlusMoveY()));
  connect(ui->ButtonMinusMoveY, SIGNAL(clicked()), this,
          SLOT(ButtonMinusMoveY()));
  connect(ui->ButtonPlusMoveX, SIGNAL(clicked()), this,
          SLOT(ButtonPlusMoveX()));
  connect(ui->ButtonMinusMoveX, SIGNAL(clicked()), this,
          SLOT(ButtonMinusMoveX()));
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
  controller_->GetData().ClearData();
  if (controller_->GetStringFilePath(file_path_)) {
    ui->vertexCount->setText(
        QString::number(controller_->GetData().GetCoordinateVertex().size()));
    ui->polygonCount->setText(
        QString::number(controller_->GetData().GetStringPolygon().size()));
    QFileInfo check_file(file_path_);
    ui->fileNameLabel->setText(check_file.fileName());
    gl_widget_->update();
  }
}

void View::SetBckgColorClicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  //  gl_widget_->backround_color_ = color;
  gl_widget_->SetBackgroundColor(color);
  gl_widget_->update();
}

void View::SetLinesColorClicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  gl_widget_->SetLinesColor(color);
  gl_widget_->update();
}

void View::SetVertexesColorClicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  gl_widget_->SetVertexesColor(color);
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
  gl_widget_->SetDefault();
  ui->lineSizeEditer->setValue(1);
  ui->vertexSizeEditer->setValue(0);
  ui->projectionType->setCurrentIndex(0);
  ui->VertexesType->setCurrentIndex(0);
  ui->linesType->setCurrentIndex(0);

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

  gl_widget_->update();
}

//// BONUS PART 1

void View::ProjectionTypeChanged(int index) {
  if (index == 0) {
    gl_widget_->SetProjectionType(GLWidget::ProjectionType::kCentral);
  } else if (index == 1) {
    gl_widget_->SetProjectionType(GLWidget::ProjectionType::kParallel);
  }
}

void View::LinesTypeChanged(int index) {
  if (index == 0) {
    gl_widget_->SetLinesType(GLWidget::LinesType::kSolid);
  } else if (index == 1) {
    gl_widget_->SetLinesType(GLWidget::LinesType::kDashed);
  }
}

void View::VertexesTypeChanged(int index) {
  if (index == 0) {
    gl_widget_->SetVertexesType(GLWidget::VertexesType::kNone);
  } else if (index == 1) {
    gl_widget_->SetVertexesType(GLWidget::VertexesType::kCircle);
  } else if (index == 2) {
    gl_widget_->SetVertexesType(GLWidget::VertexesType::kSquare);
  }
}

void View::VertexSizeValueChanged(int value) {
  gl_widget_->SetVertexesSize(value);
  update();
}

void View::LinesWidthValueChanged(int value) {
  gl_widget_->SetLinesWidth(value);
  update();
}

// void View::writeSettings() {
//   QString pathSettings = QCoreApplication::applicationDirPath();
//   QSettings settings(pathSettings + "/settings.ini", QSettings::IniFormat);
//   settings.beginGroup("settings");
//
//   settings.setValue("file_path_", file_path_);
//   settings.setValue("backgroundColor", ui.);
//   settings.setValue("lines_color_", lines_color_);
//   settings.setValue("vertexes_color_", vertexes_color_);
//   settings.setValue("lineSizeEditer", ui->lineSizeEditer->value());
//   settings.setValue("lineWidth", lineWidth);
//   settings.setValue("vertexSize", vertexSize);
//   settings.setValue("vertexSizeEditer", ui->vertexSizeEditer->value());
//
//   settings.setValue("VertexesType", ui->VertexesType->currentIndex());
//   settings.setValue("linesType", ui->linesType->currentIndex());
//   settings.setValue("projectionType", ui->projectionType->currentIndex());
//
//   settings.setValue("lineType", lineType);
//   settings.setValue("vertexType", vertexType);
//   settings.setValue("projection", projection);
//
//   settings.setValue("x_rot_", x_rot_);
//   settings.setValue("y_rot_", y_rot_);
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
//   backround_color_ =
//       QColor(settings.value("backgroundColor",
//       QColor(Qt::black)).toString());
//   lines_color_ =
//       QColor(settings.value("lines_color_", QColor(Qt::white)).toString());
//   vertexes_color_ =
//       QColor(settings.value("vertexes_color_",
//       QColor(Qt::white)).toString());
//
//   ui->lineSizeEditer->setValue(settings.value("lineSizeEditer", 1).toInt());
//   lineWidth = settings.value("lineWidth", 1).toInt();
//
//   ui->vertexSizeEditer->setValue(settings.value("vertexSizeEditer",
//   1).toInt()); vertexSize = settings.value("vertexSize",
//   1).toInt();
//
//   ui->VertexesType->setCurrentIndex(settings.value("VertexesType",
//   0).toInt()); ui->linesType->setCurrentIndex(settings.value("linesType",
//   0).toInt()); ui->projectionType->setCurrentIndex(
//       settings.value("projectionType", 0).toInt());
//
//   lineType = static_cast<View::linesType>(
//       settings.value("lineType", View::SOLID).toInt());
//   vertexType = static_cast<View::VertexesType>(
//       settings.value("vertexType", View::NONE).toInt());
//   projection = static_cast<View::projectionType>(
//       settings.value("projection", View::CENTRAL).toInt());
//
//   x_rot_ = settings.value("x_rot_", 0).toDouble();
//   y_rot_ = settings.value("y_rot_", 0).toDouble();
//   zRot = settings.value("zRot", 0).toDouble();
//
//   settings.endGroup();
// }

// AFFINE_TRANSFORMATIONS
void View::ButtonPlusMoveZ() {
  double value = ui->doubleSpinBox_MOVE_Z->value();
  controller_->Affine(Strategy::SelectionStrategy::kMove,
                      Strategy::TypeCoordinate::kZ, &controller_->GetData(),
                      value);
  gl_widget_->update();
}

void View::ButtonMinusMoveZ() {
  double value = ui->doubleSpinBox_MOVE_Z->value();
  controller_->Affine(Strategy::SelectionStrategy::kMove,
                      Strategy::TypeCoordinate::kZ, &controller_->GetData(),
                      -value);
  gl_widget_->update();
}

void View::ButtonPlusMoveY() {
  double value = ui->doubleSpinBox_Y_MOVE->value();
  controller_->Affine(Strategy::SelectionStrategy::kMove,
                      Strategy::TypeCoordinate::kY, &controller_->GetData(),
                      value);
  gl_widget_->update();
}

void View::ButtonMinusMoveY() {
  double value = ui->doubleSpinBox_Y_MOVE->value();
  controller_->Affine(Strategy::SelectionStrategy::kMove,
                      Strategy::TypeCoordinate::kY, &controller_->GetData(),
                      -value);
  gl_widget_->update();
}

void View::ButtonPlusMoveX() {
  double value = ui->doubleSpinBox_X_MOVE->value();
  controller_->Affine(Strategy::SelectionStrategy::kMove,
                      Strategy::TypeCoordinate::kX, &controller_->GetData(),
                      value);
  gl_widget_->update();
}

void View::ButtonMinusMoveX() {
  double value = ui->doubleSpinBox_X_MOVE->value();
  controller_->Affine(Strategy::SelectionStrategy::kMove,
                      Strategy::TypeCoordinate::kX, &controller_->GetData(),
                      -value);
  gl_widget_->update();
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
