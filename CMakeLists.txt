cmake_minimum_required(VERSION 3.23)

project(3dViewer_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets OpenGL REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)


add_executable(3dViewer
        Model/data_3d_model.h
        Model/render_3d_model.cc
        Model/render_3d_model.h
        Model/myopenglwidget.cpp
        Model/myopenglwidget.h
        View/main.cpp
        View/mainwindow.cpp
        View/mainwindow.h
        View/mainwindow.ui
        Model/model.h
        Controller/controller.h
)

target_link_libraries(3dViewer PRIVATE Qt6::Widgets Qt6::OpenGLWidgets)
