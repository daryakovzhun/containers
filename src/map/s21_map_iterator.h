#ifndef SRC_S21_MAP_ITERATOR_H
#define SRC_S21_MAP_ITERATOR_H

#include <utility>
#include <cstddef>

#include <iostream>

template<typename Key, typename T>
class Node {
    public:
        Node* parent;
        Node* left;
        Node* right;
        std::pair<Key, T> data;

        Node(const std::pair<const Key, T>& value = std::pair<const Key, T>(), Node* p = NULL, Node* l = NULL, Node* r = NULL) {
            data = value;
            parent = p;
            left = l;
            right = r;
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
                while (next->parent && next->parent->right == next) {
                    next = next->parent;
                }
                next = next->parent;          
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
                while (prev->parent && prev->parent->right == prev) {
                    prev = prev->parent;
                }
                prev = prev->parent;
            }
            return prev;
        }

        void free_node(Node* tree) {
            if (tree->left) free_node(tree->left); 
            if (tree->right) free_node(tree->right); 
            delete tree;
        }

        Node* copy_node(Node* root){
            Node* node = root;
            if (node) {
                node = new Node(root->data);
                node->left = copy_node(root->left);
                node->right = copy_node(root->right);
            }
            return node;
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

        MapIterator operator++(int value) {  // for me
            MapIterator buffer(*this);
            it = it->next();
            return buffer;
        }

        MapIterator& operator--() {
            it = it->prev();
            return *this;
        }

        MapIterator operator--(int value) {  //  for me
            MapIterator buffer(*this);
            it = it->prev();
            return buffer;
        }

        bool operator==(const MapIterator& other) const {
            return it == other.it;
        }

        bool operator!=(const MapIterator& other) const {
            return it != other.it;
        }


};

template< typename Key, typename T>
class MapConstIterator {   
    public:
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const key_type, mapped_type>;
        using const_reference = const value_type&;

        const Node<Key, T>* it;

        MapConstIterator(Node<Key, T>* root = NULL) : it(root) {}
        MapConstIterator(const MapConstIterator& other) {
            *this = other;
        }
        ~MapConstIterator() {}

        const_reference operator*() const {
            return it->data;
        }

        MapConstIterator& operator++() {
            it = it->next();
            return *this;
        }

        MapConstIterator operator++(int value) {  // for me
            MapConstIterator buffer(*this);
            it = it->next();
            return buffer;
        }

        MapConstIterator& operator--() {
            it = it->prev();
            return *this;
        }

        MapConstIterator operator--(int value) {  //  for me
            MapConstIterator buffer(*this);
            it = it->prev();
            return buffer;
        }

        bool operator==(const MapConstIterator& other) const {
            return it == other.it;
        }

        bool operator!=(const MapConstIterator& other) const {
            return it != other.it;
        }
};

#endif //  SRC_S21_MAP_ITERATOR_H
