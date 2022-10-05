#ifndef SRC_S21_QUEUE_H
#define SRC_S21_QUEUE_H

#include <initializer_list>

#include <string.h>
#include <list>

namespace s21 {
    template<typename T>
    class queue {
        public:
            using value_type = T;
            using reference = T&;
            using const_reference = const T&;
            using size_type = size_t ;

            queue();
            queue(std::initializer_list<value_type> const &items);
            queue(const queue &q);
            queue(queue &&q);
            ~queue();
            queue& operator=(queue &&q);

            const_reference front() const { return queue_.front();}
            const_reference back() const {return queue_.back();}

            bool empty();
            size_type size() const { return queue_.size();}

            void push(const_reference value);
            void pop();
            void swap(queue& other);

            bool operator!=(queue& other) const;
        private:
            std::list<T> queue_;
    };
}

#endif //  SRC_S21_QUEUE_H
