
#include "../include/data.h"
#include <cstdint>
#include <cstdlib>
#include <math.h>
#include <vector>

extern "C" {

void Data::create(int length) {
    data.assign(length, 0);
}

int Data::size() {
    return data.size();
}

uint32_t Data::get(int index) {
    return data[index];
}

void Data::set(int index, uint32_t value) {
    data[index] = value;
}

}