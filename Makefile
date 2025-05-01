# Project Configuration
BUILD_DIR = dist
TS_SRC_DIR = src-ts
EMCC = emcc
TSC = tsc
NPM = npm

# Source and object files
SRC_EMC_EXPORT_FILE=blasWasm.cpp
SRC_DIR = blas
SRC := $(shell find ./$(SRC_DIR)/src -name '*.cpp')

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

all: clean build

build: $(BUILD_DIR)/module.js

$(BUILD_DIR)/module.js: $(SRC_DIR)/$(SRC_EMC_EXPORT_FILE)
	@mkdir -p $(BUILD_DIR)
	$(EMCC) $(SRC) $< -o $@ $(EMFLAGS)

clean:
	rm -rf $(BUILD_DIR)
