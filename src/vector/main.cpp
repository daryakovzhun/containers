#include "s21_vector.h"
#include <gtest/gtest.h>

using namespace s21;

int main() {
    Vector<int> a = {1,8,5};
    Vector<int> b(std::move(a));
    b.at(0) = 22;
    b.push_back(33);


    for (size_t i = 0; i < b.size(); i++) std::cout << b.at(i) << std::endl;
}
