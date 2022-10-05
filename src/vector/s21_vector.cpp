#include "s21_vector.h"

namespace s21 {


template <typename T>
void Vector<T>::reserve_more_capacity(size_t size)
{
    if (size > m_capacity)
    {
        value_type *buff = new value_type[size];
        for (size_t i = 0; i < m_size; ++i)
            buff[i] = std::move(arr[i]);
        delete[] arr;
        arr = buff;
        m_capacity = size;
    }
}

// initializer list constructor
template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> const &items)
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


template <typename T>
size_t Vector<T>::size()
{
    return m_size;
}





// externalizing template instances for correct linking, feel free to find more information
template class Vector<int>;




// element accessor_____________________________________________________________

template <typename T>
T& Vector<T>::at(size_type pos)
{
    if (pos >= this->m_size) throw std::out_of_range ("Out of range");
    return arr[pos];
}




// append new element___________________________________________________________

template <typename T>
void Vector<T>::push_back(const T & v)
{
    if (m_size == m_capacity)
    {
        reserve_more_capacity(m_size * 2);
    }
    arr[m_size++] = v;
}



}; //  namespace s21