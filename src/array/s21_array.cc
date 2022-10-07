#include "s21_array.h"

#include <cstddef>

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

namespace s21 {
    template<typename T, std::size_t N>
    array<T, N>::array() {
        //  ???
        for (int i = 0; i < N; i++) {
            array_[i] = T();
        }
    }

    template<typename T, std::size_t N>
    array<T, N>::array(std::initializer_list<value_type> const &items) {
        int i = 0;
        for (auto obj : items) {
            array_[i] = obj;
            i++;
            if (i == N) { break; }
        }
    }

    template<typename T, std::size_t N>
    array<T, N>::array(const array<T, N> &a) {

    }

    template<typename T, std::size_t N>
    array<T, N>::array(array<T, N> &&a) {

    }

    template<typename T, std::size_t N>
    array<T, N>::~array() {}

    template<typename T, std::size_t N>
    array<T, N>& array<T, N>::operator=(array<T, N> &&a) {
    }

    template<typename T, std::size_t N>
    T& array<T, N>::at(size_type pos) {

    }

    template<typename T, std::size_t N>
    T& array<T, N>::operator[](size_type pos) {
        return array_[pos];
    }

    template<typename T, std::size_t N>
    const T& array<T, N>::front() {
        return array_[0];
    }

    template<typename T, std::size_t N>
    const T& array<T, N>::back() {
        return array_[N -1];
    }

    // template<typename T, std::size_t N>
    // iterator array<T, N>::data() {

    // }

    // template<typename T, std::size_t N>
    // iterator array<T, N>::begin() {

    // }

    // template<typename T, std::size_t N>
    // iterator array<T, N>::end() {

    // }

    template<typename T, std::size_t N>
    bool array<T, N>::empty() {

    }

    // template<typename T, std::size_t N>
    // std::size_t array<T, N>::size() {

    // }

    // template<typename T, std::size_t N>
    // std::size_t array<T, N>::max_size() {

    // }


    template<typename T, std::size_t N>
    void array<T, N>::swap(array& other) {

    }

    template<typename T, std::size_t N>
    void array<T, N>::fill(const_reference value) {

    }
}

int main () {
    // std::array<int, 1> a = {33};
    // std::cout << a.front() << " " << a.back();

    s21::array<int, 1> a = {33, 22};
    std::cout << a.front() << " " << a.back();

    // s21::array<int, 2> b;
    // std::cout << b[0] << " " << b[1];

}