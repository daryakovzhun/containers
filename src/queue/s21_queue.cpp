// #include "s21_queue.h"

#include <iostream>
// #include <fstream>
// #include <cstring>
// #include <vector>

// #include <string>
// #include <queue>

using namespace std;

// template<typename T>
// void S21Queue<T>::AllocateMemory(S21Queue<T> &q, size_t size) {
//     q.queue_ = new T[size];
// }

// template<typename T>
// S21Queue<T>::S21Queue() {
//     // queue_ = new value_type[1];  /// ??
//     head_ = tail_ = size_ = 0;
// }

// template<typename T>
// S21Queue<T>::S21Queue(std::initializer_list<value_type> const &items) {
//     size_ = items.size();
//     // queue_ = new value_type[size_];
//     AllocateMemory(*this, size_);
//     head_ = items.begin();
//     tail_ = items.end();
// }

// template<typename T>
// S21Queue<T>::S21Queue(const S21Queue &q) : head_(q.head_), tail_(q.tail_), size_(q.size_) {
//     AllocateMemory(*this, q.size());
//     // queue_ = new value_type[q.size()];
//     memcpy(queue_, q.queue_, size_ * sizeof(value_type));
// }

// template<typename T>
// S21Queue<T>::S21Queue(S21Queue &&q) : head_(q.head_), tail_(q.tail_), size_(q.size_) {
//     queue_ = q.queue_;
//     q.queue_ = nullptr;
// }

// template<typename T>
// S21Queue<T>::~S21Queue() {
//     if (queue_) {
//         delete[] queue_;
//     }
// }

// // template<typename T>
// // S21Queue<T>::operator=(S21Queue &&q);


// template<typename T>
// bool S21Queue<T>::empty() {
//     return size_ == 0;
// }

// template<typename T>
// void S21Queue<T>::push(const_reference value) {
//     S21Queue<T> buffer(*this);
//     this->~S21Queue();
//     AllocateMemory(*this, buffer.size_ + 1);
//     memcpy(queue_, buffer.queue_, buffer.size_ * sizeof(value_type));
//     size_++;
//     tail_++;
//     queue_[tail_] = value;
// }

// template<typename T>
// void S21Queue<T>::pop() {
//     S21Queue<T> buffer(*this);
//     this->~S21Queue();
//     AllocateMemory(*this, buffer.size_ - 1);
//     memcpy(queue_, buffer.queue_ + 1, buffer.size_ - 1 * sizeof(value_type));
//     size_--;
//     tail_--;
// }

// template<typename T>
// void S21Queue<T>::swap(S21Queue& other) {

// }


int main () {
    // std::queue<int> check;
    // S21Queue<int> q;

    // for (int i = 0; i < 100; i++) {
    //     check.push(i);
    //     q.push(i);

    //     // if (i % 3 == 0) {
    //     //     check.pop();
    //     //     q.pop();
    //     // }
    // }

    // std::cout << check.front() << "\n";
    // std::cout << q.front() << "\n";

    cout << "hell" << "\n";

  return 0;
}
