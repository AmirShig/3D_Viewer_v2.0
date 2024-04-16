/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QLabel *fileNameLabel;
    QLabel *vertexCount;
    QLabel *polygonCount;
    QLabel *label_19;
    QLabel *label_12;
    QPushButton *OpenFilePushButtonClicked;
    QLabel *label;
    QPushButton *CleanPushButtonClicked;
    QPushButton *createScreenPshBtn;
    QPushButton *createGifPshBtn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *projectionType;
    QLabel *label_14;
    QPushButton *SetBckgColorClicked;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_8;
    QSlider *lineSizeEditer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QComboBox *linesType;
    QLabel *label_4;
    QPushButton *SetLinesColorClicked;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *label_9;
    QSlider *vertexSizeEditer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QComboBox *vertexesType;
    QLabel *label_6;
    QPushButton *SetVertexesColorClicked;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *B_PLUS_MOVE_Z;
    QPushButton *B_MINUS_MOVE_Z;
    QDoubleSpinBox *doubleSpinBox_MOVE_Z;
    QPushButton *B_PLUS_MOVE_Y;
    QDoubleSpinBox *doubleSpinBox_Y_MOVE;
    QPushButton *B_MINUS_MOVE_Y;
    QPushButton *B_PLUS_MOVE_X;
    QDoubleSpinBox *doubleSpinBox_X_MOVE;
    QPushButton *B_MINUS_MOVE_X;
    QWidget *tab_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *tab_3;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *ROTATE_X_MINUS;
    QPushButton *ROTATE_X_PLUS;
    QPushButton *ROTATE_Y_MINUS;
    QPushButton *ROTATE_Y_PLUS;
    QPushButton *ROTATE_Z_MINUS;
    QPushButton *ROTATE_Z_PLUS;
    QSpinBox *ROTATE_X_VALUE;
    QSpinBox *ROTATE_Y_VALUE;
    QSpinBox *ROTATE_Z_VALUE;
    QPushButton *SetDefault_button;
    QWidget *gridWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(1359, 759);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(View->sizePolicy().hasHeightForWidth());
        View->setSizePolicy(sizePolicy);
        View->setMinimumSize(QSize(1359, 759));
        View->setMaximumSize(QSize(1359, 759));
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1362, 761));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(930, 60, 421, 121));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout_2->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setHorizontalSpacing(30);
        formLayout_2->setVerticalSpacing(6);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName("label_10");
        label_10->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(18);
        font.setKerning(false);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10->setMargin(5);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        fileNameLabel = new QLabel(formLayoutWidget);
        fileNameLabel->setObjectName("fileNameLabel");
        fileNameLabel->setEnabled(true);
        sizePolicy1.setHeightForWidth(fileNameLabel->sizePolicy().hasHeightForWidth());
        fileNameLabel->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(20);
        font1.setKerning(false);
        fileNameLabel->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, fileNameLabel);

        vertexCount = new QLabel(formLayoutWidget);
        vertexCount->setObjectName("vertexCount");
        vertexCount->setEnabled(true);
        sizePolicy1.setHeightForWidth(vertexCount->sizePolicy().hasHeightForWidth());
        vertexCount->setSizePolicy(sizePolicy1);
        vertexCount->setFont(font1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, vertexCount);

        polygonCount = new QLabel(formLayoutWidget);
        polygonCount->setObjectName("polygonCount");
        polygonCount->setEnabled(true);
        sizePolicy1.setHeightForWidth(polygonCount->sizePolicy().hasHeightForWidth());
        polygonCount->setSizePolicy(sizePolicy1);
        polygonCount->setFont(font1);
        polygonCount->setIndent(-1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, polygonCount);

        label_19 = new QLabel(formLayoutWidget);
        label_19->setObjectName("label_19");
        label_19->setEnabled(true);
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_19->setMargin(5);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_19);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName("label_12");
        label_12->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setFont(font);
        label_12->setToolTipDuration(0);
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_12->setMargin(5);
        label_12->setIndent(0);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_12);

        OpenFilePushButtonClicked = new QPushButton(centralwidget);
        OpenFilePushButtonClicked->setObjectName("OpenFilePushButtonClicked");
        OpenFilePushButtonClicked->setGeometry(QRect(930, 180, 421, 41));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(false);
        OpenFilePushButtonClicked->setFont(font2);
        OpenFilePushButtonClicked->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(930, 20, 421, 41));
        QFont font3;
        font3.setPointSize(32);
        font3.setBold(true);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        CleanPushButtonClicked = new QPushButton(centralwidget);
        CleanPushButtonClicked->setObjectName("CleanPushButtonClicked");
        CleanPushButtonClicked->setGeometry(QRect(1150, 710, 201, 41));
        CleanPushButtonClicked->setFont(font2);
        CleanPushButtonClicked->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        createScreenPshBtn = new QPushButton(centralwidget);
        createScreenPshBtn->setObjectName("createScreenPshBtn");
        createScreenPshBtn->setGeometry(QRect(930, 230, 201, 41));
        createScreenPshBtn->setFont(font2);
        createScreenPshBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        createGifPshBtn = new QPushButton(centralwidget);
        createGifPshBtn->setObjectName("createGifPshBtn");
        createGifPshBtn->setGeometry(QRect(1150, 230, 201, 41));
        createGifPshBtn->setFont(font2);
        createGifPshBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(931, 280, 421, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font4;
        font4.setPointSize(15);
        label_2->setFont(font4);

        horizontalLayout_5->addWidget(label_2);

        projectionType = new QComboBox(verticalLayoutWidget);
        projectionType->addItem(QString());
        projectionType->addItem(QString());
        projectionType->setObjectName("projectionType");
        sizePolicy1.setHeightForWidth(projectionType->sizePolicy().hasHeightForWidth());
        projectionType->setSizePolicy(sizePolicy1);
        projectionType->setFont(font4);

        horizontalLayout_5->addWidget(projectionType);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName("label_14");
        label_14->setFont(font4);

        horizontalLayout_5->addWidget(label_14);

        SetBckgColorClicked = new QPushButton(verticalLayoutWidget);
        SetBckgColorClicked->setObjectName("SetBckgColorClicked");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(SetBckgColorClicked->sizePolicy().hasHeightForWidth());
        SetBckgColorClicked->setSizePolicy(sizePolicy3);
        SetBckgColorClicked->setFont(font4);
        SetBckgColorClicked->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));

        horizontalLayout_5->addWidget(SetBckgColorClicked);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, -1, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        QFont font5;
        font5.setPointSize(20);
        label_3->setFont(font5);

        horizontalLayout->addWidget(label_3);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setFont(font4);

        horizontalLayout->addWidget(label_8);

        lineSizeEditer = new QSlider(verticalLayoutWidget);
        lineSizeEditer->setObjectName("lineSizeEditer");
        lineSizeEditer->setMinimum(1);
        lineSizeEditer->setMaximum(15);
        lineSizeEditer->setSingleStep(1);
        lineSizeEditer->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(lineSizeEditer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 3);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font4);

        horizontalLayout_2->addWidget(label_7);

        linesType = new QComboBox(verticalLayoutWidget);
        linesType->addItem(QString());
        linesType->addItem(QString());
        linesType->setObjectName("linesType");
        sizePolicy1.setHeightForWidth(linesType->sizePolicy().hasHeightForWidth());
        linesType->setSizePolicy(sizePolicy1);
        linesType->setFont(font4);

        horizontalLayout_2->addWidget(linesType);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font4);

        horizontalLayout_2->addWidget(label_4);

        SetLinesColorClicked = new QPushButton(verticalLayoutWidget);
        SetLinesColorClicked->setObjectName("SetLinesColorClicked");
        sizePolicy3.setHeightForWidth(SetLinesColorClicked->sizePolicy().hasHeightForWidth());
        SetLinesColorClicked->setSizePolicy(sizePolicy3);
        SetLinesColorClicked->setFont(font4);
        SetLinesColorClicked->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));

        horizontalLayout_2->addWidget(SetLinesColorClicked);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font5);

        horizontalLayout_3->addWidget(label_5);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setFont(font4);

        horizontalLayout_3->addWidget(label_9);

        vertexSizeEditer = new QSlider(verticalLayoutWidget);
        vertexSizeEditer->setObjectName("vertexSizeEditer");
        vertexSizeEditer->setMinimum(1);
        vertexSizeEditer->setMaximum(15);
        vertexSizeEditer->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(vertexSizeEditer);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(2, 3);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName("label_13");
        label_13->setFont(font4);

        horizontalLayout_4->addWidget(label_13);

        vertexesType = new QComboBox(verticalLayoutWidget);
        vertexesType->addItem(QString());
        vertexesType->addItem(QString());
        vertexesType->addItem(QString());
        vertexesType->setObjectName("vertexesType");
        sizePolicy1.setHeightForWidth(vertexesType->sizePolicy().hasHeightForWidth());
        vertexesType->setSizePolicy(sizePolicy1);
        vertexesType->setFont(font4);

        horizontalLayout_4->addWidget(vertexesType);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setFont(font4);

        horizontalLayout_4->addWidget(label_6);

        SetVertexesColorClicked = new QPushButton(verticalLayoutWidget);
        SetVertexesColorClicked->setObjectName("SetVertexesColorClicked");
        sizePolicy3.setHeightForWidth(SetVertexesColorClicked->sizePolicy().hasHeightForWidth());
        SetVertexesColorClicked->setSizePolicy(sizePolicy3);
        SetVertexesColorClicked->setFont(font4);
        SetVertexesColorClicked->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));

        horizontalLayout_4->addWidget(SetVertexesColorClicked);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(930, 490, 421, 211));
        tab_1 = new QWidget();
        tab_1->setObjectName("tab_1");
        label_21 = new QLabel(tab_1);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 70, 51, 41));
        QFont font6;
        font6.setPointSize(24);
        label_21->setFont(font6);
        label_22 = new QLabel(tab_1);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(30, 130, 51, 41));
        label_22->setFont(font6);
        label_23 = new QLabel(tab_1);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(30, 10, 51, 41));
        label_23->setFont(font6);
        B_PLUS_MOVE_Z = new QPushButton(tab_1);
        B_PLUS_MOVE_Z->setObjectName("B_PLUS_MOVE_Z");
        B_PLUS_MOVE_Z->setGeometry(QRect(70, 140, 100, 32));
        B_PLUS_MOVE_Z->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        B_MINUS_MOVE_Z = new QPushButton(tab_1);
        B_MINUS_MOVE_Z->setObjectName("B_MINUS_MOVE_Z");
        B_MINUS_MOVE_Z->setGeometry(QRect(280, 140, 100, 32));
        B_MINUS_MOVE_Z->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        doubleSpinBox_MOVE_Z = new QDoubleSpinBox(tab_1);
        doubleSpinBox_MOVE_Z->setObjectName("doubleSpinBox_MOVE_Z");
        doubleSpinBox_MOVE_Z->setGeometry(QRect(190, 141, 62, 31));
        doubleSpinBox_MOVE_Z->setMaximum(10.000000000000000);
        doubleSpinBox_MOVE_Z->setSingleStep(0.100000000000000);
        B_PLUS_MOVE_Y = new QPushButton(tab_1);
        B_PLUS_MOVE_Y->setObjectName("B_PLUS_MOVE_Y");
        B_PLUS_MOVE_Y->setGeometry(QRect(70, 80, 100, 32));
        B_PLUS_MOVE_Y->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        doubleSpinBox_Y_MOVE = new QDoubleSpinBox(tab_1);
        doubleSpinBox_Y_MOVE->setObjectName("doubleSpinBox_Y_MOVE");
        doubleSpinBox_Y_MOVE->setGeometry(QRect(190, 81, 62, 31));
        doubleSpinBox_Y_MOVE->setMaximum(10.000000000000000);
        doubleSpinBox_Y_MOVE->setSingleStep(0.100000000000000);
        B_MINUS_MOVE_Y = new QPushButton(tab_1);
        B_MINUS_MOVE_Y->setObjectName("B_MINUS_MOVE_Y");
        B_MINUS_MOVE_Y->setGeometry(QRect(280, 80, 100, 32));
        B_MINUS_MOVE_Y->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        B_PLUS_MOVE_X = new QPushButton(tab_1);
        B_PLUS_MOVE_X->setObjectName("B_PLUS_MOVE_X");
        B_PLUS_MOVE_X->setGeometry(QRect(70, 20, 100, 32));
        B_PLUS_MOVE_X->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        doubleSpinBox_X_MOVE = new QDoubleSpinBox(tab_1);
        doubleSpinBox_X_MOVE->setObjectName("doubleSpinBox_X_MOVE");
        doubleSpinBox_X_MOVE->setGeometry(QRect(190, 21, 62, 31));
        doubleSpinBox_X_MOVE->setMinimum(0.000000000000000);
        doubleSpinBox_X_MOVE->setMaximum(10.000000000000000);
        doubleSpinBox_X_MOVE->setSingleStep(0.100000000000000);
        B_MINUS_MOVE_X = new QPushButton(tab_1);
        B_MINUS_MOVE_X->setObjectName("B_MINUS_MOVE_X");
        B_MINUS_MOVE_X->setGeometry(QRect(280, 20, 100, 32));
        B_MINUS_MOVE_X->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 90, 161, 41));
        QFont font7;
        font7.setPointSize(20);
        font7.setBold(false);
        font7.setItalic(false);
        font7.setUnderline(false);
        font7.setStrikeOut(false);
        pushButton_4->setFont(font7);
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(220, 90, 151, 41));
        pushButton_5->setFont(font5);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_15 = new QLabel(tab_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 10, 51, 41));
        label_15->setFont(font6);
        label_16 = new QLabel(tab_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 70, 51, 41));
        label_16->setFont(font6);
        label_17 = new QLabel(tab_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 130, 51, 41));
        label_17->setFont(font6);
        ROTATE_X_MINUS = new QPushButton(tab_3);
        ROTATE_X_MINUS->setObjectName("ROTATE_X_MINUS");
        ROTATE_X_MINUS->setGeometry(QRect(280, 10, 100, 41));
        ROTATE_X_MINUS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        ROTATE_X_PLUS = new QPushButton(tab_3);
        ROTATE_X_PLUS->setObjectName("ROTATE_X_PLUS");
        ROTATE_X_PLUS->setGeometry(QRect(70, 10, 100, 41));
        ROTATE_X_PLUS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        ROTATE_Y_MINUS = new QPushButton(tab_3);
        ROTATE_Y_MINUS->setObjectName("ROTATE_Y_MINUS");
        ROTATE_Y_MINUS->setGeometry(QRect(280, 70, 100, 41));
        ROTATE_Y_MINUS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        ROTATE_Y_PLUS = new QPushButton(tab_3);
        ROTATE_Y_PLUS->setObjectName("ROTATE_Y_PLUS");
        ROTATE_Y_PLUS->setGeometry(QRect(70, 70, 100, 41));
        ROTATE_Y_PLUS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        ROTATE_Z_MINUS = new QPushButton(tab_3);
        ROTATE_Z_MINUS->setObjectName("ROTATE_Z_MINUS");
        ROTATE_Z_MINUS->setGeometry(QRect(280, 130, 100, 41));
        ROTATE_Z_MINUS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        ROTATE_Z_PLUS = new QPushButton(tab_3);
        ROTATE_Z_PLUS->setObjectName("ROTATE_Z_PLUS");
        ROTATE_Z_PLUS->setGeometry(QRect(70, 130, 100, 41));
        ROTATE_Z_PLUS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: orange; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        ROTATE_X_VALUE = new QSpinBox(tab_3);
        ROTATE_X_VALUE->setObjectName("ROTATE_X_VALUE");
        ROTATE_X_VALUE->setGeometry(QRect(190, 10, 61, 41));
        ROTATE_X_VALUE->setMaximum(360);
        ROTATE_Y_VALUE = new QSpinBox(tab_3);
        ROTATE_Y_VALUE->setObjectName("ROTATE_Y_VALUE");
        ROTATE_Y_VALUE->setGeometry(QRect(190, 71, 61, 41));
        ROTATE_Y_VALUE->setMaximum(360);
        ROTATE_Z_VALUE = new QSpinBox(tab_3);
        ROTATE_Z_VALUE->setObjectName("ROTATE_Z_VALUE");
        ROTATE_Z_VALUE->setGeometry(QRect(190, 130, 61, 41));
        ROTATE_Z_VALUE->setMaximum(360);
        tabWidget->addTab(tab_3, QString());
        SetDefault_button = new QPushButton(centralwidget);
        SetDefault_button->setObjectName("SetDefault_button");
        SetDefault_button->setGeometry(QRect(930, 710, 201, 41));
        SetDefault_button->setFont(font2);
        SetDefault_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(75, 75, 75);\n"
"	\n"
"	border-color: solid black;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setGeometry(QRect(130, 90, 481, 511));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName("gridLayout");

        retranslateUi(View);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QWidget *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "View", nullptr));
        label_10->setText(QCoreApplication::translate("View", "File name", nullptr));
        fileNameLabel->setText(QString());
        vertexCount->setText(QString());
        polygonCount->setText(QString());
        label_19->setText(QCoreApplication::translate("View", "Vertexes ", nullptr));
        label_12->setText(QCoreApplication::translate("View", "Edges", nullptr));
        OpenFilePushButtonClicked->setText(QCoreApplication::translate("View", "Open file", nullptr));
        label->setText(QCoreApplication::translate("View", "Information", nullptr));
        CleanPushButtonClicked->setText(QCoreApplication::translate("View", "All Clean", nullptr));
        createScreenPshBtn->setText(QCoreApplication::translate("View", "Print screen", nullptr));
        createGifPshBtn->setText(QCoreApplication::translate("View", "Create gif", nullptr));
        label_2->setText(QCoreApplication::translate("View", "Projection", nullptr));
        projectionType->setItemText(0, QCoreApplication::translate("View", "Central", nullptr));
        projectionType->setItemText(1, QCoreApplication::translate("View", "Parallel", nullptr));

        label_14->setText(QCoreApplication::translate("View", "Background", nullptr));
        SetBckgColorClicked->setText(QCoreApplication::translate("View", "Set color", nullptr));
        label_3->setText(QCoreApplication::translate("View", "Lines", nullptr));
        label_8->setText(QCoreApplication::translate("View", "Size", nullptr));
        label_7->setText(QCoreApplication::translate("View", "Type", nullptr));
        linesType->setItemText(0, QCoreApplication::translate("View", "Solid", nullptr));
        linesType->setItemText(1, QCoreApplication::translate("View", "Dashed", nullptr));

        label_4->setText(QCoreApplication::translate("View", "Color", nullptr));
        SetLinesColorClicked->setText(QCoreApplication::translate("View", "Set color", nullptr));
        label_5->setText(QCoreApplication::translate("View", "Vertexes", nullptr));
        label_9->setText(QCoreApplication::translate("View", "Size", nullptr));
        label_13->setText(QCoreApplication::translate("View", "Type", nullptr));
        vertexesType->setItemText(0, QCoreApplication::translate("View", "None", nullptr));
        vertexesType->setItemText(1, QCoreApplication::translate("View", "Circle", nullptr));
        vertexesType->setItemText(2, QCoreApplication::translate("View", "Square", nullptr));

        label_6->setText(QCoreApplication::translate("View", "Color", nullptr));
        SetVertexesColorClicked->setText(QCoreApplication::translate("View", "Set color", nullptr));
        label_21->setText(QCoreApplication::translate("View", "Y", nullptr));
        label_22->setText(QCoreApplication::translate("View", "Z", nullptr));
        label_23->setText(QCoreApplication::translate("View", "X", nullptr));
        B_PLUS_MOVE_Z->setText(QCoreApplication::translate("View", "+", nullptr));
        B_MINUS_MOVE_Z->setText(QCoreApplication::translate("View", "-", nullptr));
        B_PLUS_MOVE_Y->setText(QCoreApplication::translate("View", "+", nullptr));
        B_MINUS_MOVE_Y->setText(QCoreApplication::translate("View", "-", nullptr));
        B_PLUS_MOVE_X->setText(QCoreApplication::translate("View", "+", nullptr));
        B_MINUS_MOVE_X->setText(QCoreApplication::translate("View", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("View", "Move", nullptr));
        pushButton_4->setText(QCoreApplication::translate("View", "+", nullptr));
        pushButton_5->setText(QCoreApplication::translate("View", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("View", "Size", nullptr));
        label_15->setText(QCoreApplication::translate("View", "X", nullptr));
        label_16->setText(QCoreApplication::translate("View", "Y", nullptr));
        label_17->setText(QCoreApplication::translate("View", "Z", nullptr));
        ROTATE_X_MINUS->setText(QCoreApplication::translate("View", "-", nullptr));
        ROTATE_X_PLUS->setText(QCoreApplication::translate("View", "+", nullptr));
        ROTATE_Y_MINUS->setText(QCoreApplication::translate("View", "-", nullptr));
        ROTATE_Y_PLUS->setText(QCoreApplication::translate("View", "+", nullptr));
        ROTATE_Z_MINUS->setText(QCoreApplication::translate("View", "-", nullptr));
        ROTATE_Z_PLUS->setText(QCoreApplication::translate("View", "+", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("View", "Rotate", nullptr));
        SetDefault_button->setText(QCoreApplication::translate("View", "Set default", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
