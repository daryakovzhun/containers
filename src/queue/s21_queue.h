#ifndef SRC_S21_QUEUE_H
#define SRC_S21_QUEUE_H

#include <initializer_list>
#include <string.h>
// #include <stdexcept>

template<typename T>
class S21Queue {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t ;

        S21Queue();
        S21Queue(std::initializer_list<value_type> const &items);
        S21Queue(const S21Queue &q);
        S21Queue(S21Queue &&q);
        ~S21Queue();
        void operator=(S21Queue &&q);

        const_reference front() const { return queue_[head_];}
        const_reference back() const {return queue_[tail_];}

        bool empty();
        size_type size() const { return size_;}

        void push(const_reference value);
        void pop();
        void swap(S21Queue& other);

        void AllocateMemory(S21Queue<T> &q, size_t size);

    private:
        value_type *queue_;
        int head_;
        int tail_;
        size_type size_;
};

#endif //  SRC_S21_QUEUE_H
