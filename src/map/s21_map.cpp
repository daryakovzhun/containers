#include "s21_map.h"

#include <map>
#include <vector>

template<typename Key, typename T>
S21Map<Key, T>::S21Map() {
    root_ = NULL;
    head_ = new Node<Key, T>();
    tail_ = new Node<Key, T>();
    head_->parent = tail_;
    tail_->parent = head_;
    size_ = 0;
}

// template<typename Key, typename T>
// S21Map<Key, T>::S21Map(std::initializer_list<value_type> const &items);

template<typename Key, typename T>
S21Map<Key, T>::S21Map(const S21Map &m) {
    root_ = new Node<Key, T>();  // ??
    head_ = new Node<Key, T>();
    tail_ = new Node<Key, T>();
    *this = m;
}

template<typename Key, typename T>
S21Map<Key, T>::S21Map(S21Map &&m) {
    root_ = m.root_;
    head_ = m.head_;
    tail_ = m.tail_;
    size_ = m.size_;
    m.root_ = nullptr;
}

template<typename Key, typename T>
S21Map<Key, T>::~S21Map() {
    clear(); 
}

// template<typename Key, typename T>
// S21Map<Key, T>& S21Map<Key, T>::operator=(S21Map &&m) {
//     if (*this != m) {
//         clear();
//         // insert(m.begin(), m.end());
//     }
//     return *this;
// }


template<typename Key, typename T>
T& S21Map<Key, T>::at(const Key& key) {
    auto buffer = find_by_key(key);
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
bool S21Map<Key, T>::empty() {
    return size_ == 0;
}

template<typename Key, typename T>
size_t S21Map<Key, T>::size() const {
    return size_;
}

// template<typename Key, typename T>
// size_type S21Map<Key, T>::max_size();



template<typename Key, typename T>
void S21Map<Key, T>::clear() {
    root_->free_node(root_);
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
        connect_node(result, &result->right, NULL);

    } else if (value.first > parent->data.first) {
        connect_node(parent, &parent->right, result);
        connect_node(result, &result->right, it);
        connect_node(result, &result->left, NULL);
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
    std::pair<MapIterator<Key, T>, bool> reuslt = insert(std::pair<Key, T>(key, obj));
    if (reuslt.second == false) {
        reuslt.first.it->data.second = obj;
    }
    return reuslt;
}

template<typename Key, typename T>
void S21Map<Key, T>::erase(MapIterator<Key, T> pos) {
    bool left_child = (pos.it->left) ? true : false;
    bool right_child = (pos.it->right) ? true : false;

    if (!left_child && !right_child) {               //  является листом
        rebuild_node(pos, NULL);
    } else if (!left_child || !right_child) {        //  только одно поддерево второго ребенка нет
        rebuild_node(pos, (right_child) ? pos.it->right : pos.it->left);
    } else {
        MapIterator<Key, T> next = pos;
        ++next;   
        if (!next.it->left && !next.it->right) {     //  самый левый из правого поддерева лист
            rebuild_node(next, NULL);
        } else {                                      //  самый левый из правого поддерева имеет одно поддерево
            rebuild_node(next, (next.it->right) ? next.it->right : next.it->left);
        }
        next.it->left = pos.it->left;
        next.it->right = pos.it->right;
        if (pos.it == root_) { root_ = next.it; }
    }
    delete pos.it;
}

// template<typename Key, typename T>
// void S21Map<Key, T>::swap(S21Map<Key, T>& other);

// template<typename Key, typename T>
// void S21Map<Key, T>::merge(S21Map<Key, T>& other);

// template<typename Key, typename T>
// bool S21Map<Key, T>::contains(const Key& key);



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
    // m.insert(pair<int, int>(6, 6));
    m.insert(pair<int, int>(3, 3));
    m.insert(pair<int, int>(4, 4));
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(18, 18));
    m.insert(pair<int, int>(7, 7));
    m.insert(pair<int, int>(19, 19));
    m.insert(pair<int, int>(10, 10));
    m.insert(pair<int, int>(9, 9));
    m.insert(pair<int, int>(12, 12));

    // m.insert_or_assign(3, 33);


    vector<int> i{1, 2, 3, 4, 5, 7, 9, 10, 12, 18, 19};
    m[0] = 12345;
    m.at(5) = 555;
    auto it = m.begin();
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;

    // if (i == 4) {
        m.erase(it);
    // }

    for (int k : i) {
        cout << "i = " << k << " map[i] = ";
        cout << m[k] << "\n";
        // it++;
    }
        
   

    // for (int i = 0; i < 9; i++) {
    //     cout << "i = " << i << " check[i] = ";
    //     cout << m[i] << "\n";
    // }

    // cout << "\n\n\n\n";

    // map<int, int> check;
    // check.insert(pair<int, int>(5, 5));
    // check.insert(pair<int, int>(6, 6));
    // check.insert(pair<int, int>(3, 3));
    // check.insert(pair<int, int>(4, 4));
    // check.insert(pair<int, int>(1, 1));
    // check.insert(pair<int, int>(2, 2));
    // check.insert(pair<int, int>(8, 8));
    // // check.insert_or_assign(3, 33);


    // int i = 0;
    // check[0] = 12345;
    // check.at(5) = 555;
    // // auto it = check.begin();
    // for (int i = 0; i < 9; i++) {
    //     cout << "i = " << i << " check[i] = ";
    //     cout << check[i] << "\n";
    // }
} 

