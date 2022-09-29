#ifndef SRC_S21_MAP_ITERATOR_H
#define SRC_S21_MAP_ITERATOR_H

#include <utility>
#include <cstddef>

template<typename Key, typename T>
class Node {
    public:
        Node* parent;
        Node* left;
        Node* right;
        std::pair< Key, T> data; // const

        Node(const std::pair<const Key, T>& value = 0, Node* parent = NULL, Node* left = NULL, Node* right = NULL) {
            data.first = value.first;
            data.second = value.second;
            parent = parent;
            left = left;
            right = right;
        }
        Node(const Node& other) {
            *this = other;
        }

        Node& operator=(const Node& other) {
            if (*this != &other) {
                parent = other.parent;
                left = other.left;
                right = other.right;
                data = other.data;
            }
            return *this;
        }

        ~Node() {}

        Node* next() {
            Node* next = this;
            if (next->right) {
                next = next->right;
                while (next->left) {
                    next = next->left;
                }
            } else {
                next = next->parent;  //  ??            
            }
            return next;
        }

        Node* prev() {
            Node* prev = this;
            if (prev->left) {
                prev = prev->left;
                while (prev->right) {
                    prev = prev->right;
                }
            } else {
                prev = prev->parent;  //  ??
            }
            return prev;
        }

};

template< typename Key, typename T>
class MapIterator {   
    public:
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const key_type, mapped_type>;
        using reference = value_type&;

        Node<Key, T>* it;

        MapIterator(Node<Key, T>* root = NULL) : it(root) {}
        MapIterator(const MapIterator& other) {
            *this = other;
        }
        ~MapIterator() {}

        MapIterator& operator=(const MapIterator& other) {
            it = other.it;
            return *this;
        }

        reference operator*() {
            return it->data;
        }

        MapIterator& operator++() {
            it = it->next();
            return *this;
        }

        MapIterator& operator--() {
            it = it->prev();
            return *this;
        }

        bool operator==(const MapIterator& other) {
            return it == other.it;
        }

        bool operator!=(const MapIterator& other) {
            return it != other.it;
        }
};



#endif //  SRC_S21_MAP_ITERATOR_H
