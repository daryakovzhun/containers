#include "s21_map.h"



template<typename Key, typename T>
S21Map<Key, T>::S21Map() {
    root_ = NULL;
    // head_ = NULL;
    // tail_ = NULL;
    head_ = new Node<Key, T>();
    tail_ = new Node<Key, T>();
    // head_->parent = tail_;
    // tail_->parent = head_;

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

template<typename Key, typename T>
S21Map<Key, T>::~S21Map() {
    //  
}

// template<typename Key, typename T>
// S21Map<Key, T>::operator=(S21Map &&m);

// template<typename Key, typename T>
// T& S21Map<Key, T>::at(const Key& key);

template<typename Key, typename T>
T& S21Map<Key, T>::operator[](const Key& key) {
    MapIterator<Key, T> it = find_by_key(key);
    if (it == end() || it == MapIterator<Key, T>(head_)) {
        it = insert(std::pair<Key, T>(key, T())).first;
    }
    return it.it->data.second;
}

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

    Node<Key, T>* result = new Node<Key, T>(value, parent, NULL, NULL);
    if (value.first < parent->data.first) {
        connect_node(parent, &parent->left, result);
        connect_node(result, &result->left, it);
        connect_node(result, &result->right, NULL);
    } else if (value.first > parent->data.first) {  //  it == tail_ || 
        connect_node(parent, &parent->right, result);
        connect_node(result, &result->right, it);
        connect_node(result, &result->left, NULL);
    }
    size_++;
    return std::pair<MapIterator<Key, T>, bool>(MapIterator<Key, T>(result), true);
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
    // S21Map<int, string> m;
    // m.insert(pair<int, string>(5, "5"));
    // m.insert(pair<int, string>(8, "8"));
    // m.insert(pair<int, string>(1, "1"));
    // m.insert(pair<int, string>(23, "23"));
    // m.insert(pair<int, string>(3, "3"));
    // m.insert(pair<int, string>(2, "2"));
    // m.insert(pair<int, string>(15, "15"));
    // m.insert(pair<int, string>(20, "20"));
    // m.insert(pair<int, string>(13, "13"));
    // m.insert(pair<int, string>(11, "11"));

    S21Map<int, int> m;
    m.insert(pair<int, int>(5, 5));
    m.insert(pair<int, int>(6, 6));
    m.insert(pair<int, int>(3, 3));
    m.insert(pair<int, int>(4, 4));
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));

    int i = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << "i = " << i << " map[i] = " << m[i] << "\n";
        i++;
    }

    // for (int j = 1; j < 24; j++) {
    //     cout << "j = " << j << " map[j] = " << m[j] << "\n";
    // }
} 

