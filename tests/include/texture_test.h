#ifndef _TEST_TEXTURE_TEST_H
#define _TEST_TEXTURE_TEST_H

#include <iostream>
#include "../../blas/include/texture.h"
#include "../../blas/include/vector.h"


namespace texture_test {

    bool drawTexture() {
        std::cout << texture::draw(5) << std::endl;
        return true;
    }

    bool vectorTest() {
        std::cout << int_sqrt(10) << std::endl;
        return true;
    }
}

#endif