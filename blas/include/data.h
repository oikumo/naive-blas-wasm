#ifndef _BLAS_DATA_H_
#define _BLAS_DATA_H_ 

#include <cstdint>
#include <cstdlib>
#include <math.h>
#include <vector>

extern "C" {

class Data {

public:
    std::vector<uint32_t> data;
    void create(int length);
    int size();
    uint32_t get(int index);
    void set(int index, uint32_t value);

};

}

#endif
  