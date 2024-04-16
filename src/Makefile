.PHONY : all install clean rebuild run

SRC_DIR := .
EXTENSIONS := cc cpp h
# Функция для обнаружения файлов с заданными расширениями в директории и ее поддиректориях
find_files = $(foreach ext,$(EXTENSIONS),$(wildcard $(1)/*.$(ext))) $(foreach d,$(wildcard $(1)/*),$(call find_files,$(d)))
SRC_FILES := $(call find_files,$(SRC_DIR))

# Фильтрация только файлов с расширением .cc
CC_FILES := $(filter-out ./gui/desktop/main.cc ./gui/desktop/SnakeView.cc, $(filter %.cc,$(SRC_FILES)))

#SRC_FILES= view/glwidget.cc \
#			view/glwidget.h \
#			view/main.cc \
#			view/view.h \
#			view/view.cpp

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
	rm -rf ../build
	make style

style:
	@cp ../materials/linters/.clang-format .
	clang-format -n $(SRC_FILES)
	clang-format -i $(SRC_FILES)
	@rm -rf .clang-format

.PHONY : style