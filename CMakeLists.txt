cmake_minimum_required(VERSION 3.23)

project(3dViewer_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

find_package(Qt6 COMPONENTS Widgets OpenGL REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)

add_executable(3dViewer
        src/Model/data_3d_model.h
        src/Model/data_3d_model.cc
        src/Model/parce_obj.cc
        src/View/main.cpp
        src/View/view.cpp
        src/View/view.h
        src/View/mainwindow.ui
        src/Model/model.h
        src/Model/model.cc
        src/Model/lexem.cc
        src/Controller/controller.h
        src/Controller/controller.cc
        src/View/glwidget.cc
        src/View/glwidget.h
        src/Model/affine_transformations.cc
        src/Model/affine_transformations.h
        src/View/QtGifImage/gifimage/qgifimage.h
        src/View/QtGifImage/gifimage/qgifimage.cpp
        src/View/QtGifImage/gifimage/qgifglobal.h
        src/View/QtGifImage/gifimage/qgifimage_p.h
        src/View/QtGifImage/3rdParty/giflib/gif_lib.h
        src/View/QtGifImage/3rdParty/giflib/gif_hash.h
        src/View/QtGifImage/3rdParty/giflib/dgif_lib.c
        src/View/QtGifImage/3rdParty/giflib/egif_lib.c
        src/View/QtGifImage/3rdParty/giflib/gif_err.c
        src/View/QtGifImage/3rdParty/giflib/gif_font.c
        src/View/QtGifImage/3rdParty/giflib/gif_hash.c
        src/View/QtGifImage/3rdParty/giflib/gifalloc.c
        src/View/QtGifImage/3rdParty/giflib/quantize.c
)

target_link_libraries(3dViewer PRIVATE Qt6::Widgets Qt6::OpenGLWidgets OpenGL::GLU)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        unit_test
        src/tests/unit_tests.cc
        src/Model/model.cc
        src/Model/data_3d_model.cc
        src/Model/lexem.cc
        src/Model/parce_obj.cc
        src/Model/affine_transformations.cc
        src/Model/affine_transformations.h
)

target_link_libraries(
        unit_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_test)