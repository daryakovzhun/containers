#include "s21_queue.h"

#include <queue>

using namespace std;

template<typename T>
void S21Queue<T>::AllocateMemory(S21Queue<T> &q, size_t size) {
    if (size <= 0 ) size = 10;
    q.queue_ = new T[size]();
}

template<typename T>
S21Queue<T>::S21Queue() {
    AllocateMemory(*this, 10);
    head_  = size_ = 0;
    tail_ = 0;
}

template<typename T>
S21Queue<T>::S21Queue(std::initializer_list<value_type> const &items) {
    size_ = items.size();
    // queue_ = new value_type[size_];
    AllocateMemory(*this, size_);
    head_ = items.begin();
    tail_ = items.end();
}

template<typename T>
S21Queue<T>::S21Queue(const S21Queue &q) : head_(q.head_), tail_(q.tail_), size_(q.size_) {
    AllocateMemory(*this, q.size());
    // queue_ = new value_type[q.size()];
    memcpy(queue_, q.queue_, size_ * sizeof(value_type));
}

template<typename T>
S21Queue<T>::S21Queue(S21Queue &&q) : head_(q.head_), tail_(q.tail_), size_(q.size_) {
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


template<typename T>
bool S21Queue<T>::empty() {
    return size_ == 0;
}

template<typename T>
void S21Queue<T>::push(const_reference value) {
    S21Queue<T> buffer(*this);
    this->~S21Queue();
    AllocateMemory(*this, buffer.size_ + 1);
    for (int i = 0; i < buffer.size_; i++) {
        queue_[i] = buffer.queue_[i];
    }
    size_++;
    if (size_ > 1) tail_++; 
    queue_[tail_] = value;
}

template<typename T>
void S21Queue<T>::pop() {
    S21Queue<T> buffer(*this);
    this->~S21Queue();
    AllocateMemory(*this, buffer.size_ - 1);

    for (int i = 0; i < buffer.size_ - 1; i++) {
        queue_[i] = buffer.queue_[i + 1];
    }
        // memcpy(queue_, buffer.queue_ + 1, buffer.size_ - 1 * sizeof(value_type));

    if (size_ > 0)  size_--;
    if (tail_ > 0) tail_--;
}

template<typename T>
void S21Queue<T>::swap(S21Queue& other) {

}


int main () {
    std::queue<int> check;
    S21Queue<int> q;

    for (int i = 0; i < 10; i++) {
        
        check.push(i);
        std::cout << "front " << check.front() << " ";
        q.push(i);
        std::cout << "front my " << check.front() << "\n";

        if (i % 3 == 0) {
            check.pop();
            q.pop();
        }

        std::cout << "back = " << check.back() << "\n";
        std::cout << "back my = " << q.back() << "\n\n";
    }

  return 0;
}
