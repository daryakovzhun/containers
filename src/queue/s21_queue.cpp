#include "s21_queue.h"

template<typename T>
S21Queue<T>::S21Queue() { }

template<typename T>
S21Queue<T>::S21Queue(std::initializer_list<T> const &items) {
    for (auto obj : items) {
        queue_.push_back(obj);
    }
}

template<typename T>
S21Queue<T>::S21Queue(const S21Queue &q) {
    queue_ = q.queue_;
}

template<typename T>
S21Queue<T>::S21Queue(S21Queue &&q) {
    std::list<T>buffer = std::move(q.queue_);
    queue_ = buffer;
}

template<typename T>
S21Queue<T>::~S21Queue() {
    queue_.clear();
}

template<typename T>
S21Queue<T>& S21Queue<T>::operator=(S21Queue &&q) {
    if (*this != q) {
        queue_.clear();
        queue_ = q.queue_;
    }
    return *this;
}

template<typename T>
bool S21Queue<T>::empty() {
    return queue_.empty();
}

template<typename T>
void S21Queue<T>::push(const_reference value) {
    queue_.push_back(value);
}

template<typename T>
void S21Queue<T>::pop() {
    queue_.pop_front();
}

template<typename T>
void S21Queue<T>::swap(S21Queue& other) {
    queue_.swap(other.queue_);
}

template<typename T>
bool S21Queue<T>::operator!=(S21Queue& other) const {
    return !(queue_ == other.queue_);
}

