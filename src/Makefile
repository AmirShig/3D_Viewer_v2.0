.PHONY : all install clean rebuild run style tests

CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17
GTEST_FLAGS= -lgtest_main -pthread -lgtest

SRC_DIR := .
EXTENSIONS := cc cpp h
# Функция для обнаружения файлов с заданными расширениями в директории и ее поддиректориях
find_files = $(foreach ext,$(EXTENSIONS),$(wildcard $(1)/*.$(ext))) $(foreach d,$(wildcard $(1)/*),$(call find_files,$(d)))
SRC_FILES := $(call find_files,$(SRC_DIR))

# Фильтрация только файлов с расширением .cc
CC_FILES := $(filter-out ./gui/desktop/main.cc ./gui/desktop/SnakeView.cc, $(filter %.cc,$(SRC_FILES)))

TEST_SRC := tests/unit_tests.cc


all: install run

install: clean
	mkdir ../build
	cd ../build && cmake .. && make

rebuild:
	cd ../build && make && ./3dViewer

run:
	cd ../build && ./3dViewer

clean:
	clear
	rm -rf ../build test
	make style

style:
	@cp ../materials/linters/.clang-format .
	clang-format -n $(SRC_FILES)
	clang-format -i $(SRC_FILES)
	@rm -rf .clang-format

tests:
	$(CXX) $(CXXFLAGS) $(TEST_SRC) Model/model.cc Model/data_3d_model.cc Model/lexem.cc Model/parce_obj.cc $(GTEST_FLAGS) -o test
	./test