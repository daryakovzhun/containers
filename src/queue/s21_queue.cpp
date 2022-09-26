#include "s21_queue.h"

template<typename T>
S21Queue<T>::S21Queue() {
    queue_ = new value_type[100];
    head_ = tail_ = 0;
}

template<typename T>
S21Queue<T>::S21Queue(std::initializer_list<value_type> const &items) {
    queue_ = new value_type [items.size()];
    head_ = items.begin();
    tail_ = items.end();
}

template<typename T>
S21Queue<T>::S21Queue(const S21Queue &q) : head_(q.head_), tail_(q.tail_) {
    queue_ = new value_type[q.size()];
}

template<typename T>
S21Queue<T>::S21Queue(S21Queue &&q) : head_(q.head_), tail_(q.tail_){
    queue_ = q.queue_;
    q.queue_ = nullptr;
}

template<typename T>
S21Queue<T>::~S21Queue() {
    if (queue_) {
        delete[] queue_;
    }
}

// template<typename T>
// S21Queue<T>::operator=(S21Queue &&q);

// template<typename T>
// const_reference S21Queue<T>::front();

// template<typename T>
// const_reference S21Queue<T>::back();

template<typename T>
bool S21Queue<T>::empty() {
    return head_ == tail_;
}

// template<typename T>
// size_type S21Queue<T>::size();

template<typename T>
void S21Queue<T>::push(const_reference value);

template<typename T>
void S21Queue<T>::pop();

template<typename T>
void S21Queue<T>::swap(S21Queue& other);
