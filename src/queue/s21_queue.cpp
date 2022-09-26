#include "s21_queue.h"

template<typename T>
S21Queue<T>::S21Queue();

template<typename T>
S21Queue<T>::S21Queue(std::initializer_list<value_type> const &items);

template<typename T>
S21Queue<T>::S21Queue(const S21Queue &q);

template<typename T>
S21Queue<T>::S21Queue(S21Queue &&q);

template<typename T>
S21Queue<T>::~S21Queue();

// template<typename T>
// S21Queue<T>::operator=(S21Queue &&q);

template<typename T>
const_reference S21Queue<T>::front();

template<typename T>
const_reference S21Queue<T>::back();

template<typename T>
bool S21Queue<T>::empty();

template<typename T>
size_type S21Queue<T>::size();

template<typename T>
void S21Queue<T>::push(const_reference value);

template<typename T>
void S21Queue<T>::pop();

template<typename T>
void S21Queue<T>::swap(S21Queue& other);
