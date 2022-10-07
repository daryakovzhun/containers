#ifndef SRC_S21_ARRAY_H
#define SRC_S21_ARRAY_H

#include <initializer_list>

namespace s21 {
    template<typename T, std::size_t N = 0>
    class array {
        public:
            using value_type = T;
            using reference = T&;
            using const_reference = const T&;
            using iterator = T*;
            using const_iterator = const T*;
            using size_type = std::size_t;

            array() { fill(T()); }
            array(std::initializer_list<value_type> const &items);
            array(const array &a);
            // array(array &&a);
            ~array() {}
            // array& operator=(array &&a);

            reference at(size_type pos);
            reference operator[](size_type pos) { return array_[pos]; }
            const_reference front() { return *array_; }
            const_reference back() { return *(array_ + N - 1); }
            iterator data() { return array_; }

            iterator begin() { return array_; }
            iterator end() { return array_ + N; }

            bool empty() { return N == 0; }
            size_type size() { return N; }
            size_type max_size() { return N; }

            void swap(array& other);
            void fill(const_reference value);

        private:
            value_type array_[N];
    };
}

#endif //  SRC_S21_ARRAY_H