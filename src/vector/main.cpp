#include "s21_vector.h"
#include <vector>
#include <gtest/gtest.h>

// using namespace s21;

int main() {
    s21::vector<int> a = {1,8,5};
    s21::vector<int> b(std::move(a));
    b.at(0) = 22;
    b.push_back(33);
    s21::vector<int> c = {1,3,2};
    c.push_back(3);
    s21::vector<int> d(c);
    std::cout << c.capacity() << std::endl;
    std::cout << d.capacity() << std::endl;


    // std::cout << c.empty() << std::endl;

    // for (size_t i = 0; i < b.size(); i++) std::cout << b.at(i) << std::endl;
}
