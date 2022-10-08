#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <cmath>
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
        vector(const vector &v) : m_size(v.m_size), m_capacity(v.m_size), arr(new T[m_size])
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

        ~vector()                           { if (arr) delete[] arr; }
        // vector& operator=(vector &&v);

        // some method examples
        iterator begin()                    { return arr;            }
        iterator end()                      { return (arr + m_size); }

        // size getter
        bool empty()                        { return m_size ? 0 : 1; }
        size_type size()                    { return m_size;         }
        size_type capacity()                { return m_capacity;     }
        size_type max_size()                { return (powl(2, sizeof(int*) * 8 - 1) / sizeof(T)) - 1; }
        void shrink_to_fit();
        void reserve(size_type size);


        // element accessor
        reference at(size_type pos);
        reference operator[](size_type pos) { return arr[pos];        }
        const_reference front()             { return arr[0];          }
        const_reference back()              { return arr[m_size - 1]; }
        T* data()                           { return arr;             }


        // append new element
        void clear();
        void erase(iterator pos);
        void push_back(const_reference value);
        void pop_back()                     { (this->m_size)--;       }
        void swap(vector& other);
        iterator insert(iterator pos, const_reference value);
};


template <typename T>
void vector<T>::reserve_more_capacity(size_t size)
{
    if (size > m_capacity)
    {
        value_type *buff = new value_type[size];
        for (size_t i = 0; i < m_size; ++i)
            buff[i] = std::move(arr[i]);
        if (arr) delete[] arr;
        arr = buff;
        m_capacity = size;
    }
}

// initializer list constructor
template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
{
    arr = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        arr[i] = *it;
        i++;
    }
    m_size = items.size();
    m_capacity = items.size();
};



// size getter__________________________________________________________________

template <typename T>
void vector<T>::shrink_to_fit()
{
    vector<T> tmp(*this);
    if (this->arr) delete this->arr;
    this->arr = tmp.arr;
    tmp.arr = nullptr;
    this->m_capacity = tmp.m_capacity;
}

template <typename T>
void vector<T>::reserve(size_type size)
{
    reserve_more_capacity(size);
}




// element accessor_____________________________________________________________

template <typename T>
T& vector<T>::at(size_type pos)
{
    if (pos >= this->m_size) throw std::out_of_range ("Out of range");
    return arr[pos];
}


// append new element___________________________________________________________

template <typename T>
void vector<T>::clear()
{
    for (size_t i = 0; i < m_size; ++i) arr[i] = 0;
    this->m_size = 0;
}

template <typename T>
void vector<T>::erase(iterator pos)
{
    std::move(pos + 1, this->end(), pos);
    (this->m_size) --;
}

template <typename T>
void vector<T>::push_back(const T & v)
{
    if (m_size == m_capacity)
    {
        reserve_more_capacity(m_size ? m_size * 2 : 1);
    }
    arr[m_size++] = v;
}

template <typename T>
void vector<T>::swap(vector& other)
{
    std::swap(this->arr, other.arr);
    std::swap(this->m_size, other.m_size);
    std::swap(this->m_capacity, other.m_capacity);
}

template <typename T>
T* vector<T>::insert(iterator pos, const_reference value)
{
    if (m_size == m_capacity)
    {
        int tmp = pos - arr;
        reserve_more_capacity(m_size ? m_size * 2 : 1);
        pos = tmp + arr;
    }

    std::move(pos, this->end(), pos + 1);
    *pos = value;
    (this->m_size)++;
    return pos;
}


};  // namespace s21

#endif
