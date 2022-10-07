#ifndef SRC_S21_QUEUE_H
#define SRC_S21_QUEUE_H

#include <initializer_list>

#include <list>

namespace s21 {
    template<typename T>
    class queue {
        public:
            using value_type = T;
            using reference = T&;
            using const_reference = const T&;
            using size_type = std::size_t ;

            queue() {}
            queue(std::initializer_list<value_type> const &items);
            queue(const queue &q);
            queue(queue &&q);
            ~queue() { queue_.clear(); }
            queue& operator=(queue &&q);

            const_reference front() const { return queue_.front();}
            const_reference back() const {return queue_.back();}

            bool empty() { return queue_.empty(); }
            size_type size() const { return queue_.size();}

            void push(const_reference value) { queue_.push_back(value); }
            void pop() { queue_.pop_front(); }
            void swap(queue& other) { queue_.swap(other.queue_); }

            bool operator!=(queue& other) const { return !(queue_ == other.queue_); }
        private:
            std::list<T> queue_;
    };
}

#endif //  SRC_S21_QUEUE_H
