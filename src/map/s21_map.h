#ifndef SRC_S21_MAP_H
#define SRC_S21_MAP_H

#include <initializer_list>
#include <utility>
#include "s21_map_iterator.h"

// using namespace std;

namespace s21 {
    template<typename Key, typename T>
    class map {
        public:
            using key_type = Key;
            using mapped_type = T;
            using value_type = std::pair<const key_type, mapped_type>;
            using reference = value_type&;
            using const_reference = const value_type&;
            using iterator = MapIterator<Key, T>;
            using const_iterator = MapConstIterator<Key, T>; 
            using size_type = std::size_t;

            map();
            map(std::initializer_list<value_type> const &items);
            map(const map &m);
            map(map &&m);
            ~map();
            map& operator=(map &&m);
            map& operator=(const map &m);  //  for me

            mapped_type& at(const Key& key) const;
            mapped_type& operator[](const Key& key);

            iterator begin() const;
            iterator end() const;

            bool empty() const;
            size_type size() const;
            size_type max_size() const;

            void clear();
            std::pair<iterator, bool> insert(const value_type& value);
            std::pair<iterator, bool> insert(const Key& key, const T& obj);
            std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
            void erase(iterator pos);
            void swap(map& other);
            void merge(map& other);

            bool contains(const Key& key) const;

        private:
            Node<Key, T>* root_;
            Node<Key, T>* head_;
            Node<Key, T>* tail_;
            size_type size_;

            void connect_node (Node<Key, T>* parent, Node<Key, T>** childptr, Node<Key, T>* child) {
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
                Node<Key, T>* it = root_;
                while (it && it != head_ && it != tail_) {
                    if (key < it->data.first) {
                        it = it->left;
                    } else if (key > it->data.first) {
                        it = it->right;
                    } else {
                        return std::pair<iterator, bool>(it, true);
                    }
                }
                return std::pair<iterator, bool>(end(), false);
            }

            void rebuild_node(iterator pos, Node<Key, T>* child) {
                if (pos.it->parent->left == pos.it) {
                    pos.it->parent->left = child;
                } else {
                    pos.it->parent->right = child;
                }
            }
    };
}

#endif //  SRC_S21_MAP_H
