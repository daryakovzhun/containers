#include "s21_array.h"

#include <cstddef>
#include <limits>


#include <iostream>
#include <algorithm>
#include <array>

namespace s21 {
    template<typename T, std::size_t N>
    array<T, N>::array(std::initializer_list<value_type> const &items) {
        int i = 0;
        for (auto obj : items) {
            array_[i] = obj;
            i++;
            if (i == N) { break; }
        }
        if (i < N) {
            while (i != N) {
                array_[i] = T();
                i++;
            }
        }
    }

    template<typename T, std::size_t N>
    array<T, N>::array(const array<T, N> &a) {
        for (int i = 0; i < N; i++) {
            array_[i] = a.array_[i];
        }
    }

    template<typename T, std::size_t N>
    array<T, N>::array(array<T, N> &&a) {

    }


    template<typename T, std::size_t N>
    array<T, N>& array<T, N>::operator=(array<T, N> &&a) {
    }

    template<typename T, std::size_t N>
    T& array<T, N>::at(size_type pos) {
        if (pos >= N) {
            throw std::out_of_range("pos >= N");
        }
        return array_[pos];
    }

    template<typename T, std::size_t N>
    void array<T, N>::swap(array& other) {
        array<T, N> buffer(other);
        for (int i = 0; i < N; i++) {
            other.array_[i] = array_[i];
            array_[i] = buffer.array_[i];
        }
    }

    template<typename T, std::size_t N>
    void array<T, N>::fill(const_reference value) {
        for (int i = 0; i < N; i++) {
            array_[i] = value;
        }
    }
}

int main () {
    // std::array<int, 20> a = {1, 2};
    // std::cout << "a = " << *(a.begin() + 1) << " " << a[10];

 
    s21::array<int, 10> b = {1, 2, 3, 4, 5};
    s21::array<int, 10> a;
    b.swap(a);
    for (int i = 0; i < 10; i++) {
        std::cout << " b = " << b[i] << " a = " << a[i] << "\n";
    }
    // a.fill(5);
    // std::cout << "\n";
    // for (int i = 0; i < 10; i++) {
    //     std::cout << " b = " << b[i] << " a = " << a[i] << "\n";
    // }

    // std::cout << "\nb = " <<  b.max_size();

    // std::cout << a.at(1) << " " << a.at(4);

    // s21::array<int, 2> b;
    // std::cout << b[0] << " " << b[1];

}