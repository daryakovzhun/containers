#include "s21_set.h"

#include <limits>
#include <set>
#include <cmath>

namespace s21 {
    template<typename Key>
    set<Key>::set() {
        root_ = NULL;
        head_ = new Node<Key>();
        tail_ = new Node<Key>();
        head_->parent = tail_;
        tail_->parent = head_;
        size_ = 0;
    }

    template<typename Key>
    set<Key>::set(const set<Key>& m) {
        root_ = NULL;
        head_ = NULL;
        tail_ = NULL;
        *this = m;
    }

    template<typename Key>
    set<Key>::~set() {
        if (root_ || head_ || tail_) {
            clear();
        }
    }

    template<typename Key>
    set<Key>& set<Key>::operator=(set &&m) {
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

    template<typename Key>
    std::size_t set<Key>::max_size() const {
        std::allocator<int> alloc;
        return alloc.max_size() / 10;
    }

    template<typename Key>
    void set<Key>::clear() {
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

    template<typename Key>
    std::pair<SetIterator<Key>, bool> set<Key>::insert(const Key& value) {
        if (empty()) {
            root_ = new Node<Key>(value);
            connect_node(root_, &root_->left, head_);
            connect_node(root_, &root_->right, tail_);
            size_++;
            return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(root_), true);
        }

        Node<Key>* it = root_;
        Node<Key>* parent = NULL;
        while (it && it != head_ && it != tail_) {
            parent = it;
            if (value < it->data) {
                it = it->left;
            } else if (value > it->data) {
                it = it->right;
            } else {
                return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(it), false);
            }
        }

        Node<Key>* result = new Node<Key>(value, parent);
    
        if (value < parent->data) {
            connect_node(parent, &parent->left, result);
            connect_node(result, &result->left, it);

        } else if (value > parent->data) {
            connect_node(parent, &parent->right, result);
            connect_node(result, &result->right, it);
        }
        size_++;
        return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(result), true);
    }

    template<typename Key>
    void set<Key>::erase(SetIterator<Key> pos) {
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
            SetIterator<Key> next = pos;
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

    template<typename Key>
    void set<Key>::swap(set<Key>& other) {
        set<Key> buffer(other);
        other = *this;
        *this = buffer;
    }

    template<typename Key>
    void set<Key>::merge(set<Key>& other) {
        auto it = other.begin();
        for (; it != other.end(); it++) {
            insert(it.it->data);
        }
    }
}

int main () {
//     s21::set <int> mst;
 
//     std::cout << "Добавление случайных значений: " << std::endl;
//     for (int i = 0; i < 10; i++) {
//         int random = rand() % 10 + 1;
//         mst.insert(random);
//         std::cout << i + 1 << ") " << random << std::endl;
//     }
 
//     s21::set <int> :: iterator it = mst.begin();
 
//     std::cout << "Отсортированный вариант: " << std::endl;
//     for (int i = 1; it != mst.end(); i++, it++) {
//         std::cout << *it << " ";
//     }

    s21::set<char> char_my;
    std::set<char> char_st;
    std::cout << " my = " << char_my.max_size() << "\nstd = " << char_st.max_size() << '\n';

    s21::set<double> double_my;
    std::set<double> double_st;
    std::cout << " my = " << double_my.max_size() << "\nstd = " << double_st.max_size() << '\n';

    s21::set<int> int_my;
    std::set<int> int_st;
    std::cout << " my = " << int_my.max_size() << "\nstd = " << int_st.max_size() << '\n';
}
