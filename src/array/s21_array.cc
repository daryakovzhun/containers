#include "s21_array.h"

#include <cstddef>
#include <limits>

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
    array<T, N>& array<T, N>::operator=(array<T, N> &&a) {
        std::move(std::begin(a.array_), std::end(a.array_), &array_[0]);
        return *this;
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
