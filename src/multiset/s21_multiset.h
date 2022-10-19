#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../set/s21_set.h"

namespace s21 {

    template<typename Key>
    class multiset : public set<Key> {
        public:
            using key_type = Key;
            using value_type = const key_type;
            using reference = value_type&;
            using const_reference = const value_type&;
            using iterator = SetIterator<Key>;
            using const_iterator = SetConstIterator<Key>;
            using size_type = std::size_t;
            // using set<Key>::set;

        //     std::pair<iterator, bool> insert(const value_type& value)
        //     {
        //         if (empty()) {
        //             root_ = new NodeSet<Key>(value);
        //             connect_node(root_, &root_->left, head_);
        //             connect_node(root_, &root_->right, tail_);
        //             size_++;
        //             return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(root_), true);
        //         }

        //         NodeSet<Key>* it = root_;
        //         NodeSet<Key>* parent = NULL;
        //         while (it && it != head_ && it != tail_) {
        //             parent = it;
        //             if (value < it->data) {
        //                 it = it->left;
        //             } else if (value > it->data) {
        //                 it = it->right;
        //             } else {
        //                 return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(it), false);
        //             }
        //         }

        //         NodeSet<Key>* result = new NodeSet<Key>(value, parent);
    
        //         if (value < parent->data) {
        //             connect_node(parent, &parent->left, result);
        //             connect_node(result, &result->left, it);

        //         } else if (value > parent->data) {
        //             connect_node(parent, &parent->right, result);
        //             connect_node(result, &result->right, it);
        //         }
        //         size_++;
        //         return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(result), true);
        //     }

        // private:
        //     NodeSet<Key>* root_;
        //     NodeSet<Key>* head_;
        //     NodeSet<Key>* tail_;
        //     size_type size_;

    };  // set

    // template<typename Key>
    // std::pair<SetIterator<Key>, bool> set<Key>::insert(const Key& value) {
    //     if (empty()) {
    //         root_ = new NodeSet<Key>(value);
    //         connect_node(root_, &root_->left, head_);
    //         connect_node(root_, &root_->right, tail_);
    //         size_++;
    //         return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(root_), true);
    //     }

    //     NodeSet<Key>* it = root_;
    //     NodeSet<Key>* parent = NULL;
    //     while (it && it != head_ && it != tail_) {
    //         parent = it;
    //         if (value < it->data) {
    //             it = it->left;
    //         } else if (value > it->data) {
    //             it = it->right;
    //         } else {
    //             return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(it), false);
    //         }
    //     }

    //     NodeSet<Key>* result = new NodeSet<Key>(value, parent);
    
    //     if (value < parent->data) {
    //         connect_node(parent, &parent->left, result);
    //         connect_node(result, &result->left, it);

    //     } else if (value > parent->data) {
    //         connect_node(parent, &parent->right, result);
    //         connect_node(result, &result->right, it);
    //     }
    //     size_++;
    //     return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(result), true);
    // }



}  //  namespace s21




#endif