#include "s21_vector.h"
#include <vector>
#include <gtest/gtest.h>

// using namespace s21;

int main() {
    // s21::vector<int> b = {4,5,6};
    // s21::vector<int> c = {4,5,7,8};

    std::vector<int> b = {4,5,6};
    b.push_back(1);
    std::vector<int> c = {41,51,71,81};

    // b = std::move(b);
    b.shrink_to_fit();

    std::cout << "CAPACITY " << b.capacity() << std::endl;
    std::cout << "CAPACITY " << c.capacity() << std::endl;

    std::cout << "SIZE     " <<b.size() << std::endl;
    std::cout << "SIZE     " <<c.size() << std::endl;




    for (size_t i = 0; i < b.size(); i++) std::cout << b.at(i) << " ";
    std::cout << std::endl;

    for (size_t i = 0; i < c.size(); i++) std::cout << c.at(i) << " ";
    std::cout << std::endl;

}
