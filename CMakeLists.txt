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
        src/Model/data_3d_model.h
        src/Model/parce_obj.cc
        src/View/main.cpp
        src/View/view.cpp
        src/View/view.h
        src/View/mainwindow.ui
        src/Model/model.h
        src/Model/model.cc
        src/Controller/controller.h
        src/Controller/controller.cc
)

target_link_libraries(3dViewer PRIVATE Qt6::Widgets Qt6::OpenGLWidgets)
