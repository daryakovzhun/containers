#include "s21_queue.h"

namespace s21 {
    template<typename T>
    queue<T>::queue() { }

    template<typename T>
    queue<T>::queue(std::initializer_list<T> const &items) {
        for (auto obj : items) {
            queue_.push_back(obj);
        }
    }

    template<typename T>
    queue<T>::queue(const queue &q) {
        queue_ = q.queue_;
    }

    template<typename T>
    queue<T>::queue(queue &&q) {
        std::list<T>buffer = std::move(q.queue_);
        queue_ = buffer;
    }

    template<typename T>
    queue<T>::~queue() {
        queue_.clear();
    }

    template<typename T>
    queue<T>& queue<T>::operator=(queue &&q) {
        if (*this != q) {
            queue_.clear();
            queue_ = q.queue_;
        }
        return *this;
    }

    template<typename T>
    bool queue<T>::empty() {
        return queue_.empty();
    }

    template<typename T>
    void queue<T>::push(const_reference value) {
        queue_.push_back(value);
    }

    template<typename T>
    void queue<T>::pop() {
        queue_.pop_front();
    }

    template<typename T>
    void queue<T>::swap(queue& other) {
        queue_.swap(other.queue_);
    }

    template<typename T>
    bool queue<T>::operator!=(queue& other) const {
        return !(queue_ == other.queue_);
    }
}
