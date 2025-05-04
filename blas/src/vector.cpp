#include <cstdint>
#include <cstdlib>
#include <math.h>
#include "../include/vector.h"

extern "C" {

size_t create_array(int length) {
    return (size_t)static_cast<size_t*>(malloc(length * sizeof(size_t)));
}

void free_array(size_t ptr) {
    auto data = reinterpret_cast<uint32_t*>(ptr);
    free(data);
}

void modify_array(size_t ptr, int index, size_t value) {
    auto data = reinterpret_cast<uint32_t*>(ptr);
    data[index] = value;
}

int int_sqrt(int x) { return sqrt(x); }

int int_sum(int a, int b) { return a + b; }

void multiply(float factor, size_t ptr, size_t length) {
    auto data = reinterpret_cast<uint32_t*>(ptr);
    for (size_t i = 0; i < length; ++i) {
        data[i] *= factor;
    }
}

void drawTexToTex(size_t targetPtr, int targetWidth, size_t sourcePtr, int sourceWidth, int sourceHeight, int dx, int dy) {
    auto target = reinterpret_cast<uint32_t*>(targetPtr);
    auto source = reinterpret_cast<uint32_t*>(sourcePtr);
    const int sourceSize = sourceWidth * sourceHeight;
    int col = 0;
    int row = 0;

    for (int i = 0; i < sourceSize; i++) {
        target[(dx + col) + (dy + row) * targetWidth] = source[col + row * sourceWidth];

        if (col + 1 == sourceWidth) {
            col = 0;
            row++;
        }
        else {
            col++;
        }
    }
}
   
}