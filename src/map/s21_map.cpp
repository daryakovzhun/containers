#include "s21_map.h"

template<typename Key, typename T>
S21Map<Key, T>::S21Map() {
    root_ = nullptr;
    size_ = 0;
}

// template<typename Key, typename T>
// S21Map<Key, T>::S21Map(std::initializer_list<value_type> const &items);

template<typename Key, typename T>
S21Map<Key, T>::S21Map(const S21Map &m) {
    root_->CopyTree(m.root_, root_);
    size_ = m.root_->sizeT(m.root_);
}

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

// template<typename Key, typename T>
// MapIterator<Key, T> S21Map<Key, T>::begin() {
//     S21Map<Key, T> = buffer(*this);
//     while (buffer.root_.left != nullptr) {

//     }
// }

// template<typename Key, typename T>
// iterator end();

// template<typename Key, typename T>
// bool S21Map<Key, T>::empty();

// template<typename Key, typename T>
// size_type S21Map<Key, T>::size();

// template<typename Key, typename T>
// size_type S21Map<Key, T>::max_size();

// template<typename Key, typename T>
// void S21Map<Key, T>::clear();

template<typename Key, typename T>
std::pair<MapIterator<Key, T>, bool> S21Map<Key, T>::insert(const std::pair<const Key, T>& value) {
    root_->add(root_, value);
    
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



