#include <iostream>
#include "../include/texture_test.h"

int main() {

    std::cout << "test runner" << std::endl;
    std::cout << "test multiply" << std::endl;
    texture_test::drawTexture();
    texture_test::vectorTest();

    return 1;
}