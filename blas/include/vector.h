#ifndef _BLAS_VECTOR_H_
#define _BLAS_VECTOR_H_

#include <cstdint>
#include <cstdlib>
#include <math.h>

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

}

#endif