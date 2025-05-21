#include <iostream>
#include "../include/texture_test.h"

int main() {

    std::cout << "test runner" << std::endl;
    texture_test::drawTexture();
    texture_test::vectorTest();
    texture_test::arrayFloat32Test();
    texture_test::arrayFloat32ModificationTest();

    return 0;
}