BUILD_DIR := ./build
SRC_DIR := ./src

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(shell echo $(SRC_FILES) | sed "s|$(BUILD_DIR)/|$(SRC_DIR)/|g" | sed "s|\.cpp|.o|g")
PROGRAM_FILE = prog

.PHONY: build clean test

clean:
	rm -r $(BUILD_DIR) 
# build: main.o read.o
# 	gcc main.o read.o -o prog -lstdc++


main.o: main.cpp
	gcc -c main.cpp -o main.o
read.o: read.cpp
	gcc -c read.cpp -o read.o

test: $(OBJ_FILES)
	@echo $(OBJ_FILES)