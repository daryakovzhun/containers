#include "s21_queue.h"

namespace s21 {
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
        queue_ = std::move(q.queue_);
    }

    template<typename T>
    queue<T>& queue<T>::operator=(queue &&q) {
        if (*this != q) {
            queue_.clear();
            queue_ = q.queue_;
            // q.queue_ = NULL;
        }
        return *this;
    }
}
