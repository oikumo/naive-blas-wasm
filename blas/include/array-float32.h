#ifndef _BLAS_ARRAYFLOAT32_H_
#define _BLAS_ARRAYFLOAT32_H_

#include <cstdint>
#include <cstdlib>

extern "C" {

void arrayFloat32Modify(size_t ptr, int index, float value);
void arrayFloat32ModifySegment(size_t ptr, int start, size_t prt_segment, int segmentSize);


}

#endif
  