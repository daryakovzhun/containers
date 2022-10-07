#include "s21_vector.h"
#include <vector>
#include <gtest/gtest.h>

// using namespace s21;

int main() {
    s21::vector<int> a = {1,8,5};
    // s21::vector<int> a;
    a.push_back(3);

    std::vector<int> b = {4,3,2};
    // std::vector<int> b;
    b.push_back(3);

    // std::cout << a.capacity() << std::endl;
    std::cout << a.capacity() << std::endl;
    std::cout << b.capacity() << std::endl;


    // std::cout << c.empty() << std::endl;

    // for (size_t i = 0; i < b.size(); i++) std::cout << b.at(i) << std::endl;
}
