#ifndef SRC_S21_MAP_H
#define SRC_S21_MAP_H

#include <initializer_list>
#include <utility>
#include "s21_map_iterator.h"

#include <string>
#include <iostream>
using namespace std;

template<typename Key, typename T> 
class S21Map {
    public:
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const key_type, mapped_type>;
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = MapIterator<Key, T>;
        // using const_iterator = MapConstIterator<Key, T>; 
        using size_type = size_t;

        S21Map();
        S21Map(std::initializer_list<value_type> const &items);
        S21Map(const S21Map &m);
        S21Map(S21Map &&m);
        ~S21Map();
        // operator=(S21Map &&m);

        mapped_type& at(const Key& key);
        mapped_type& operator[](const Key& key);

        iterator begin();
        iterator end();

        bool empty();
        // size_type size();
        // size_type max_size();

        // void clear();
        std::pair<iterator, bool> insert(const value_type& value);
        // std::pair<iterator, bool> insert(const Key& key, const T& obj);
        // std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);;
        // void erase(iterator pos);
        // void swap(S21Map& other);
        // void merge(S21Map& other);

        // bool contains(const Key& key);

    private:
        Node<Key, T>* root_;
        Node<Key, T>* head_;
        Node<Key, T>* tail_;
        size_type size_;

        void connect_node (Node<Key, T>* parent, Node<Key, T>** childptr, Node<Key, T>* child) {
            if (child) {child->parent = parent;}
            // if (!((child == head_ || child == tail_) && (parent == head_ || parent == tail_)) && childptr) {
            //     *childptr = child;
            // }

            if ((child == head_ || child == tail_) && (parent == head_ || parent == tail_)) {
                return;
            }

            if (childptr) {
                *childptr = child;
            }
        }

        // std::pair<iterator, bool> find_by_key(const key_type& key) {
        iterator find_by_key(const key_type& key) {
            if (empty()) {
                return end();
            }
            Node<Key, T>* it = root_;
            iterator result = NULL;
            // Node<Key, T>* parent = NULL;
            while (it && it != head_ && it != tail_) {
                // parent = it;

                cout << "key = " << it->data.first << " data = ";
                if (key < it->data.first) {
                    it = it->left;
                } else if (key > it->data.first) {
                    it = it->right;
                } else {
                    return result = it;
                }
            }
            return end();
        }
};

#endif //  SRC_S21_MAP_H
