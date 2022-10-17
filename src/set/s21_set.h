#ifndef S21_SET_H
#define S21_SET_H

#include <cmath>
#include <iostream>
#include <utility>
#include "./s21_set_iterator.h"


namespace s21 {
    template<typename Key>
    class set {
        public:
            using key_type = Key;
            using value_type = const key_type;
            using reference = value_type&;
            using const_reference = const value_type&;
            using iterator = SetIterator<Key>;
            using const_iterator = SetConstIterator<Key>; 
            using size_type = std::size_t;

            set();
            set(std::initializer_list<value_type> const &items);
            set(const set &m);
            set(set &&m) : set() { *this = std::move(m); }
            ~set();
            set& operator=(set &&m);
            set& operator=(const set &m);

            iterator begin() const { return SetIterator<Key>(head_->parent); }
            iterator end() const { return SetIterator<Key>(tail_); }

            bool empty() const { return size_ == 0; }
            size_type size() const { return size_; }
            size_type max_size() const;

            void clear();
            std::pair<iterator, bool> insert(const value_type& value);
            void erase(iterator pos);
            void swap(set& other);
            void merge(set& other);

            iterator find(const Key& key) const { return find_by_key(key).first;  }
            bool contains(const Key& key) const { return find_by_key(key).second; }

        private:
            NodeSet<Key>* root_;
            NodeSet<Key>* head_;
            NodeSet<Key>* tail_;
            size_type size_;

            void connect_node (NodeSet<Key>* parent, NodeSet<Key>** childptr, NodeSet<Key>* child) {
                if (child) {
                    child->parent = parent;
                }

                // if (childptr) {
                    *childptr = child;
                // }
            }

            std::pair<iterator, bool> find_by_key(const key_type& key) const {
                if (empty()) {
                    return std::pair<iterator, bool>(end(), false);
                }
                NodeSet<Key>* it = root_;
                while (it && it != head_ && it != tail_) {
                    if (key < it->data) {
                        it = it->left;
                    } else if (key > it->data) {
                        it = it->right;
                    } else {
                        return std::pair<iterator, bool>(it, true);
                    }
                }
                return std::pair<iterator, bool>(end(), false);
            }

            void rebuild_node(iterator pos, NodeSet<Key>* child) {
                if (pos.it->parent->left == pos.it) {
                    pos.it->parent->left = child;
                } else {
                    pos.it->parent->right = child;
                }
            }


    };



};  // namespace s21

#endif
