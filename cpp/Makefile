CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

BUILD_DIR    := ./build
SRC_DIR      := ./src
PROGRAM_FILE := $(BUILD_DIR)/prog

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

.PHONY: all clean test

all: $(PROGRAM_FILE)

$(PROGRAM_FILE): $(OBJ_FILES)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

test:
	@echo "Исходные файлы: $(SRC_FILES)"
	@echo "Объектные файлы: $(OBJ_FILES)"
