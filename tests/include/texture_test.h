#ifndef _TEST_TEXTURE_TEST_H
#define _TEST_TEXTURE_TEST_H

#include <iostream>
#include "../../blas/include/texture.h"
#include "../../blas/include/vector.h"
#include "../../blas/include/array-float32.h"


namespace texture_test {

    bool drawTexture() {
        std::cout << texture::draw(5) << std::endl;
        return true;
    }

    bool vectorTest() {
        std::cout << int_sqrt(10) << std::endl;
        return true;
    }

    bool arrayFloat32Test() {
        const int arraySize = 10;
        float* array = new float[arraySize];
        
        for (int i = 0; i < arraySize; i++) {
            std::cout << array[i] << ", "; 
        }

        std::cout << "\n";

        arrayFloat32Modify((size_t)array, 0, 55);

        for (int i = 0; i < arraySize; i++) {
            std::cout << array[i] << ", ";
        }

        std::cout << "\n";

        return true;
    }


    bool arrayFloat32ModificationTest() {
        const int arraySize = 10;
        float* array = new float[arraySize];
        const int arraySegmentSize = 3;
        float* arraySegment = new float[arraySegmentSize];


        std::cout << "array\n";

        for (int i = 0; i < arraySize; i++) {
            std::cout << array[i] << ", "; 
        }

        std::cout << "\narray segment\n";
        
        for (int i = 0; i < arraySegmentSize; i++) {
            arraySegment[i] = 3; 
        }

        for (int i = 0; i < arraySegmentSize; i++) {
            std::cout << arraySegment[i] << ", "; 
        }

        std::cout << "\n";

        arrayFloat32ModifySegment((size_t)array, 2, (size_t)arraySegment, arraySegmentSize);

        std::cout << "array modified\n";

        for (int i = 0; i < arraySize; i++) {
            std::cout << array[i] << ", "; 
        }

        std::cout << "\n";

        return true;
    }



}

#endif