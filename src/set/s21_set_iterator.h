#ifndef SRC_S21_SET_ITERATOR_H
#define SRC_S21_SET_ITERATOR_H

#include <utility>
#include <cstddef>
#include <iostream>

template<typename Key>
class Node {
    public:
        Node* parent;
        Node* left;
        Node* right;
        Key data; // const

        Node(const Key& value = Key(), Node* p = NULL, Node* l = NULL, Node* r = NULL) {
            // data.first = value.first;
            // data.second = value.second;
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

template< typename Key>
class SetIterator {
    public:
        using key_type = Key;
        using value_type = const key_type;
        using reference = value_type&;

        Node<Key>* it;

        SetIterator(Node<Key>* root = NULL) : it(root) {}
        SetIterator(const SetIterator& other) {
            *this = other;
        }
        ~SetIterator() {}

        SetIterator& operator=(const SetIterator& other) {
            it = other.it;
            return *this;
        }

        reference operator*() {
            return it->data;
        }

        SetIterator& operator++() {
            it = it->next();
            return *this;
        }

        SetIterator operator++(int value) {  // for me
            SetIterator buffer(*this);
            it = it->next();
            return buffer;
        }

        SetIterator& operator--() {
            it = it->prev();
            return *this;
        }

        SetIterator operator--(int value) {  //  for me
            SetIterator buffer(*this);
            it = it->prev();
            return buffer;
        }

        bool operator==(const SetIterator& other) const {
            return it == other.it;
        }

        bool operator!=(const SetIterator& other) const {
            return it != other.it;
        }


};

template< typename Key>
class SetConstIterator {
    public:
        using key_type = Key;
        using value_type = const key_type;
        using const_reference = const value_type&;

        const Node<Key>* it;

        SetConstIterator(Node<Key>* root = NULL) : it(root) {}
        SetConstIterator(const SetConstIterator& other) {
            *this = other;
        }
        ~SetConstIterator() {}

        // SetConstIterator& operator=(const SetConstIterator& other) {
        //     it = other.it;
        //     return *this;
        // }

        const_reference operator*() const {
            return it->data;
        }

        SetConstIterator& operator++() {
            it = it->next();
            return *this;
        }

        SetConstIterator operator++(int value) {  // for me
            SetConstIterator buffer(*this);
            it = it->next();
            return buffer;
        }

        SetConstIterator& operator--() {
            it = it->prev();
            return *this;
        }

        SetConstIterator operator--(int value) {  //  for me
            SetConstIterator buffer(*this);
            it = it->prev();
            return buffer;
        }

        bool operator==(const SetConstIterator& other) const {
            return it == other.it;
        }

        bool operator!=(const SetConstIterator& other) const {
            return it != other.it;
        }
};

#endif //  SRC_S21_SET_ITERATOR_H
