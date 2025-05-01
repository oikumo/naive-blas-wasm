#ifndef _BLAS_VECTOR_H_
#define _BLAS_VECTOR_H_

#include <cstdint>
#include <cstdlib>
#include <math.h>

extern "C" {

size_t create_array(int length);

void free_array(size_t ptr);

void modify_array(size_t ptr, int index, size_t value);

int int_sqrt(int x);

int int_sum(int a, int b);

void multiply(float factor, size_t ptr, size_t length);

}

#endif