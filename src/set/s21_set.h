#ifndef S21_VECTOR_H
#define S21_VECTOR_H

// #include <cmath>
#include <iostream>
#include <utility>
#include <initializer_list>
#include <utility>
#include "../map/s21_map_iterator.h"


namespace s21 {
    template<typename Key>
    class set {
        public:
            using key_type = Key;
        //     using mapped_type = T;
            using value_type = std::pair<const key_type>;
            using reference = value_type&;
            using const_reference = const value_type&;
            using iterator = MapIterator<Key>;
            using const_iterator = MapConstIterator<Key>; 
            using size_type = std::size_t;

            set();
            set(std::initializer_list<value_type> const &items);
            set(const set &m);
            set(set &&m) : set() { *this = std::move(m); }
            ~set();
            set& operator=(set &&m);

            iterator begin() const { return MapIterator<Key, T>(head_->parent); }////////
            iterator end() const { return MapIterator<Key, T>(tail_); }//////////////////

            bool empty() const { return size_ == 0; }
            size_type size() const { return size_; }
            size_type max_size() const;

            void clear();
            std::pair<iterator, bool> insert(const value_type& value);
            void erase(iterator pos);
            void swap(map& other);
            void merge(map& other);

        private:
            Node<Key>* root_;
            Node<Key>* head_;
            Node<Key>* tail_;
            size_type size_;


    };



};  // namespace s21

#endif
