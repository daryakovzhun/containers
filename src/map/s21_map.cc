#include "s21_map.h"

#include <limits>
#include <stdlib.h>
// #include <vector>
#include <map>
#include <string>

template<typename Key, typename T>
S21Map<Key, T>::S21Map() {
    root_ = NULL;
    head_ = new Node<Key, T>();
    tail_ = new Node<Key, T>();
    head_->parent = tail_;
    tail_->parent = head_;
    size_ = 0;
}

template<typename Key, typename T>
S21Map<Key, T>::S21Map(std::initializer_list<std::pair<const Key, T>> const &items) {
    root_ = NULL;
    head_ = new Node<Key, T>();
    tail_ = new Node<Key, T>();
    head_->parent = tail_;
    tail_->parent = head_;
    size_ = 0;

    for (auto pair : items) {
        insert(pair);
    }
}

template<typename Key, typename T>
S21Map<Key, T>::S21Map(const S21Map<Key, T>& m) {
    root_ = NULL;
    head_ = NULL;
    tail_ = NULL;
    *this = m;
}

template<typename Key, typename T>
S21Map<Key, T>::S21Map(S21Map &&m) {
    root_ = m.root_;
    head_ = m.head_;
    tail_ = m.tail_;
    size_ = m.size_;
    m.root_ = NULL;
    m.head_ = NULL;
    m.tail_ = NULL;
    m.size_ = 0;
}

template<typename Key, typename T>
S21Map<Key, T>::~S21Map() {
    if (root_ || head_ || tail_) {
        clear();
    }
}

template<typename Key, typename T>
S21Map<Key, T>& S21Map<Key, T>::operator=(S21Map &&m) {
    clear();
    root_ = m.root_;
    head_ = m.head_;
    tail_ = m.tail_;
    size_ = m.size_;
    m.root_ = NULL;
    m.head_ = NULL;
    m.tail_ = NULL;
    m.size_ = 0;
    return *this;
}

template<typename Key, typename T>
S21Map<Key, T>& S21Map<Key, T>::operator=(const S21Map &m) {
    // if (*this != m) {
        clear();
        // root_ = root_->copy_node(m.root_);
        // head_ = m.head_;
        // tail_ = m.tail_;
        // size_ = m.size_;
        
        root_ = NULL;
        head_ = new Node<Key, T>();
        tail_ = new Node<Key, T>();
        head_->parent = tail_;
        tail_->parent = head_;
        size_ = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            insert(it.it->data);
        }

    // }
    return *this;
}

template<typename Key, typename T>
T& S21Map<Key, T>::at(const Key& key) const {
    const auto buffer = find_by_key(key);
    if (buffer.second == false) {
        throw std::out_of_range("Key not found");
    }
    return buffer.first.it->data.second;
}

template<typename Key, typename T>
T& S21Map<Key, T>::operator[](const Key& key) {
    auto buffer = find_by_key(key);
    MapIterator<Key, T> it = buffer.first;
    if (buffer.second == false) {
        it = insert(std::pair<const Key, T>(key, T())).first;
    }
    return it.it->data.second;
}

template<typename Key, typename T>
MapIterator<Key, T> S21Map<Key, T>::begin() const {
    return MapIterator<Key, T>(head_->parent);
}

template<typename Key, typename T>
MapIterator<Key, T> S21Map<Key, T>::end() const {
    return MapIterator<Key, T>(tail_);
}

template<typename Key, typename T>
bool S21Map<Key, T>::empty() const {
    return size_ == 0;
}

template<typename Key, typename T>
size_t S21Map<Key, T>::size() const {
    return size_;
}

template<typename Key, typename T>
size_t S21Map<Key, T>::max_size() const {
    std::allocator<pair<const Key, T>> alloc;
    std::cout << "sizeof = " << sizeof(pair<const Key, T>)<< "\n";
    return alloc.max_size() / (sizeof(pair<const Key, T>)); 
}

template<typename Key, typename T>
void S21Map<Key, T>::clear() {
    if (root_) {
        root_->free_node(root_);
        root_ = NULL; 
        head_ = NULL;
        tail_ = NULL;
    }
    if (head_) {
        head_->free_node(head_);
        head_ = NULL;
    }
    if (tail_) {
        tail_->free_node(tail_);
        tail_ = NULL;
    }
    size_ = 0;
}

template<typename Key, typename T>
std::pair<MapIterator<Key, T>, bool> S21Map<Key, T>::insert(const std::pair<const Key, T>& value) {
    if (empty()) {
        root_ = new Node<Key, T>(value);
        connect_node(root_, &root_->left, head_);
        connect_node(root_, &root_->right, tail_);
        size_++;
        return std::pair<MapIterator<Key, T>, bool>(MapIterator<Key, T>(root_), true);
    }

    Node<Key, T>* it = root_;
    Node<Key, T>* parent = NULL;
    while (it && it != head_ && it != tail_) {
        parent = it;
        if (value.first < it->data.first) {
            it = it->left;
        } else if (value.first > it->data.first) {
            it = it->right;
        } else {
            return std::pair<MapIterator<Key, T>, bool>(MapIterator<Key, T>(it), false);
        }
    }

    Node<Key, T>* result = new Node<Key, T>(value, parent);
   
    if (value.first < parent->data.first) {
        connect_node(parent, &parent->left, result);
        connect_node(result, &result->left, it);

    } else if (value.first > parent->data.first) {
        connect_node(parent, &parent->right, result);
        connect_node(result, &result->right, it);
    }
    size_++;
    return std::pair<MapIterator<Key, T>, bool>(MapIterator<Key, T>(result), true);
}

template<typename Key, typename T>
std::pair<MapIterator<Key, T>, bool> S21Map<Key, T>::insert(const Key& key, const T& obj) {
    return insert(std::pair<Key, T>(key, obj));
}

template<typename Key, typename T>
std::pair<MapIterator<Key, T>, bool> S21Map<Key, T>::insert_or_assign(const Key& key, const T& obj) {
    auto reuslt = insert(std::pair<Key, T>(key, obj));
    if (reuslt.second == false) {
        reuslt.first.it->data.second = obj;
    }
    return reuslt;
}

template<typename Key, typename T>
void S21Map<Key, T>::erase(MapIterator<Key, T> pos) {
    if (empty()) { return; }

    bool left_child = (pos.it->left) ? true : false;
    bool right_child = (pos.it->right) ? true : false;

    if (!left_child && !right_child) {               //  является листом
        rebuild_node(pos, NULL);
        delete pos.it;
    } else if (!left_child || !right_child) {        //  только одно поддерево второго ребенка нет
        rebuild_node(pos, (right_child) ? pos.it->right : pos.it->left);
        delete pos.it;
    } else {
        MapIterator<Key, T> next = pos;
        ++next;   
        if (!next.it->left && !next.it->right) {     //  самый левый из правого поддерева лист
            rebuild_node(next, NULL);
        } else {    
            rebuild_node(next, (next.it->right) ? next.it->right : next.it->left);   //  самый левый из правого поддерева имеет одного ребенка
        }
        pos.it->data = next.it->data;
        delete next.it;
    }
    size_--;
}

template<typename Key, typename T>
void S21Map<Key, T>::swap(S21Map<Key, T>& other) {
    S21Map<Key, T> buffer(other);
    other = *this;
    *this = buffer;
}

template<typename Key, typename T>
void S21Map<Key, T>::merge(S21Map<Key, T>& other) {
    auto it = other.begin();
    for (; it != other.end(); it++) {
        insert(it.it->data);
    }
}

template<typename Key, typename T>
bool S21Map<Key, T>::contains(const Key& key) const {
    return find_by_key(key).second;
}


int main () {
    S21Map<int, double> m;
    map<int, double> check;

    cout << "    m = " << m.max_size() << "\ncheck = " << check.max_size();
}