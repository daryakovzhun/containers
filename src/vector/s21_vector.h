#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <iostream>
#include <initializer_list>
#include <utility>


namespace s21 {

template <class T>
class Vector
{
    private:
        size_t m_size;
        size_t m_capacity;
        T *arr;

    public:
        using value_type        = T;
        using reference         = T &;
        using const_reference   = const T &;
        using iterator          = T *;
        using const_iterator    = const T *;
        using size_type         = size_t;

    private:
        void reserve_more_capacity(size_type size);

    public:
        Vector() : m_size(0U), m_capacity(0U), arr(nullptr) {}
        explicit Vector(size_type n) : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {}
        Vector(std::initializer_list<value_type> const &items);
        // copy constructor with simplified syntax
        Vector(const Vector &v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(new T[m_size])
        {
            for (size_t i = 0; i < m_size; ++i)
                arr[i] = v.arr[i];
        }
        // move constructor with simplified syntax
        Vector(Vector &&v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr)
        {
            v.arr = nullptr;
            v.m_size = 0;
        }

        ~Vector() { if (arr) delete[] arr; }
        Vector& operator=(Vector &&v);


        // some method examples
        // iterator begin();
        // iterator end();


        // size getter
        // bool empty();
        size_type size();
        // size_type max_size();
        // size_type capacity();
        // void shrink_to_fit();
        // void reserve(size_type size);


        // element accessor
        reference at(size_type pos);
        // reference operator[](size_type pos);
        // const_reference front();
        // const_reference back();
        // T* data();


        // append new element
        // void push_back(value_type v);  ///////////////////////
        // void clear();
        // void erase(iterator pos);
        void push_back(const_reference value);
        // void pop_back();
        // void swap(Vector& other);
        // iterator insert(iterator pos, const_reference value);
};

};  // namespace s21

#endif
