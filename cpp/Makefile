BUILD_DIR := ./build
SRC_DIR := ./src

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(shell echo $(SRC_FILES) | sed "s|$(SRC_DIR)/|$(BUILD_DIR)/|g" | sed "s|\.cpp|.o|g")
PROGRAM_FILE = prog

.PHONY: build clean test

clean:
	rm -rf $(BUILD_DIR) $(PROGRAM_FILE)
build: $(OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	gcc $(OBJ_FILES) -o $(PROGRAM_FILE) -lstdc++

OBJ_FILES:
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $@

test: $(OBJ_FILES)
	@echo $(OBJ_FILES)