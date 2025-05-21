#include "../include/array-float32.h"
#include <cstdint>
#include <cstdlib>
#include <math.h>

extern "C" {

void arrayFloat32Modify(size_t ptr, int index, float value) {
    auto array = reinterpret_cast<float*>(ptr);
    array[index] = value;
}

void arrayFloat32ModifySegment(size_t ptr, int start, size_t prtSegment, int segmentSize) {
    auto array = reinterpret_cast<float*>(ptr);
    auto arraySegment = reinterpret_cast<float*>(prtSegment);

    for (int i = 0; i < segmentSize; i++) {
        array[start + i] = arraySegment[i];
    }
}
  
}