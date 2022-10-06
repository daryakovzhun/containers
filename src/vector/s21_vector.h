#ifndef S21_vector_H
#define S21_vector_H

#include <iostream>
#include <initializer_list>
#include <utility>


namespace s21 {

template <class T>
class vector
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
        vector() : m_size(0U), m_capacity(0U), arr(nullptr) {}
        explicit vector(size_type n) : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {}
        vector(std::initializer_list<value_type> const &items);
        // copy constructor with simplified syntax
        vector(const vector &v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(new T[m_size])
        {
            for (size_t i = 0; i < m_size; ++i)
                arr[i] = v.arr[i];
        }
        // move constructor with simplified syntax
        vector(vector &&v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr)
        {
            v.arr = nullptr;
            v.m_size = 0;
        }

        ~vector() { if (arr) delete[] arr; }
        vector& operator=(vector &&v);


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
        reference operator[](size_type pos) { return arr[pos]; }
        const_reference front()             { return arr[0]; }
        const_reference back()              { return arr[m_size - 1]; }
        T* data()                           { return arr; }


        // append new element
        // void push_back(value_type v);  ///////////////////////
        // void clear();
        // void erase(iterator pos);
        void push_back(const_reference value);
        // void pop_back();
        // void swap(vector& other);
        // iterator insert(iterator pos, const_reference value);
};

};  // namespace s21

#endif
