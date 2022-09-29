#include "s21_map.h"

#include <string>
#include <iostream>
using namespace std;

template<typename Key, typename T>
S21Map<Key, T>::S21Map() {
    root_ = NULL;
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

// template<typename Key, typename T>
// S21Map<Key, T>::S21Map(std::initializer_list<value_type> const &items);

// template<typename Key, typename T>
// S21Map<Key, T>::S21Map(const S21Map &m) {
//     root_->CopyTree(m.root_, root_);
//     size_ = m.root_->sizeT(m.root_);
// }

// template<typename Key, typename T>
// S21Map<Key, T>::S21Map(S21Map &&m);

// template<typename Key, typename T>
// S21Map<Key, T>::~S21Map();

// template<typename Key, typename T>
// S21Map<Key, T>::operator=(S21Map &&m);

// template<typename Key, typename T>
// T& S21Map<Key, T>::at(const Key& key);

// template<typename Key, typename T>
// T& S21Map<Key, T>::operator[](const Key& key);

template<typename Key, typename T>
MapIterator<Key, T> S21Map<Key, T>::begin() {
    return MapIterator<Key, T>(head_->parent);
}

template<typename Key, typename T>
MapIterator<Key, T> S21Map<Key, T>::end() {
    return MapIterator<Key, T>(tail_);
}

template<typename Key, typename T>
bool S21Map<Key, T>::empty() {
    return size_ == 0;
}

// template<typename Key, typename T>
// size_type S21Map<Key, T>::size();

// template<typename Key, typename T>
// size_type S21Map<Key, T>::max_size();

// template<typename Key, typename T>
// void S21Map<Key, T>::clear();

template<typename Key, typename T>
std::pair<MapIterator<Key, T>, bool> S21Map<Key, T>::insert(const std::pair<const Key, T>& value) {
    if (empty()) {
        root_ = new Node<Key, T>(value);  //  ??
        connect_node(root_, &root_->left, head_);
        connect_node(root_, &root_->right, tail_);
        size_++;
        return std::pair<MapIterator<Key, T>, bool>(MapIterator<Key, T>(root_), true);
    }

    Node<Key, T>* it;
    Node<Key, T>* parent = NULL;
    while (it && it != head_ && it != tail_) {
        
    }
}

// // template<typename Key, typename T>
// // std::pair<iterator, bool> insert(cons t Key& key, const T& obj);

// // template<typename Key, typename T>
// // std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);;

// // template<typename Key, typename T>
// // void erase(iterator pos);

// template<typename Key, typename T>
// void swap(S21Map<Key, T>& other);

// template<typename Key, typename T>
// void merge(S21Map<Key, T>& other);

// template<typename Key, typename T>
// bool contains(const Key& key);

int main() {
    S21Map<int, string> m;
    // cout << "AAA = " << m.begin();
} 

