# Project Configuration
BUILD_DIR = dist
TS_SRC_DIR = src-ts
EMCC = emcc
TSC = tsc
NPM = npm

# Source and object files
SRC_DIR = blas
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_DIR = build/obj
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Emscripten Compilation Flags
EMFLAGS = \
	-s WASM=1 \
	-s EXPORT_NAME='Module' \
	-s ENVIRONMENT="web" \
	-s MODULARIZE=1 \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s EXPORTED_FUNCTIONS='["_malloc", "_free", "_create_array", "_free_array", "_modify_array"]' \
	-s EXPORTED_RUNTIME_METHODS='["HEAP8", "HEAPU8", "HEAP16", "HEAPU16", "HEAP32", "HEAPU32", "HEAPF32", "HEAPF64", "UTF8ToString", "stringToUTF8", "lengthBytesUTF8", "ccall", "cwrap", "setValue", "getValue", "stackAlloc", "stackSave", "stackRestore"]' \
	-lembind \
	--emit-tsd module.d.ts \
	-o dist/module.js \
	-O3

# Targets
.PHONY: all build clean

#all: clean build

build: $(BUILD_DIR)/module.js

# Default target
all: $(TARGET) 

$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/module.js: $(SRC_DIR)/main.cpp
	@mkdir -p $(BUILD_DIR)
	$(EMCC) $< -o $@ $(EMFLAGS)

clean:
	rm -rf $(BUILD_DIR)
