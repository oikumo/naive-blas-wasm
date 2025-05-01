# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -Iinclude

BUILD_DIR = build
TARGET = tests_runner
SRC_MAIN_FILE=testRunner.cpp

SRC_DIR =./src
SRC_BLAS_DIR =../blas/src
SRC_TEST = $(shell find $(SRC_DIR) -name '*.cpp')
SRC_BLAS = $(shell find $(SRC_BLAS_DIR) -name '*.cpp')

OBJ_DIR = $(BUILD_DIR)/obj
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: clean build

build: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(SRC_MAIN_FILE)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(SRC_TEST) $(SRC_BLAS) $< -o $@ $(CXXFLAGS)


clean:
	rm -rf $(BUILD_DIR)

test:
	./$(BUILD_DIR)/$(TARGET)

.PHONY: all clean