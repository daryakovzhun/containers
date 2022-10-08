#include "s21_vector.h"
#include <vector>
#include <gtest/gtest.h>

// using namespace s21;

int main() {
    s21::vector<int> a = {1,2,3};
    a.push_back(2);
    a.insert(a.end() - 1, 69);


    std::vector<int> b = {4,5,6};
    b.push_back(2);
    b.insert(b.end() - 1, 69);



    std::cout << "CAPACITY " << a.capacity() << std::endl;
    std::cout << "CAPACITY " << b.capacity() << std::endl;

    std::cout << "SIZE     " <<a.size() << std::endl;
    std::cout << "SIZE     " <<b.size() << std::endl;




    for (size_t i = 0; i < a.size(); i++) std::cout << a.at(i) << " ";
    std::cout << std::endl;

    for (size_t i = 0; i < b.size(); i++) std::cout << b.at(i) << " ";
    std::cout << std::endl;

}
