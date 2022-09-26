#ifndef SRC_S21_QUEUE_H
#define SRC_S21_QUEUE_H

#include <initializer_list>

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
        operator=(S21Queue &&q);

        const_reference front();
        const_reference back();

        bool empty();
        size_type size();

        void push(const_reference value);
        void pop();
        void swap(S21Queue& other);

    private:
        value_type *queue_;
        int head_;
        int tail_;
        
};

#endif //  SRC_S21_QUEUE_H
