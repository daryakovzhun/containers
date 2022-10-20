#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../set/s21_set.h"

namespace s21 {

//  ________________________MULTISET_CLASS______________________________________

    template<typename Key>
    class multiset : public set<Key> {
        public:
            using key_type = Key;
            using value_type = const key_type;
            using iterator = SetIterator<Key>;
            using set<Key>::set;

            multiset(std::initializer_list<value_type> const &items);
            std::pair<iterator, bool> insert(const value_type& value);
            void merge(multiset& other);

    };  // set


//  _______________________MULTISET_METHODS_____________________________________
    template<typename Key>
    multiset<Key>::multiset(std::initializer_list<const Key> const &items) : multiset() {
        for (auto key : items) {
            insert(key);
        }
    }

    template<typename Key>
        std::pair<SetIterator<Key>, bool> multiset<Key>::insert(const value_type& value)
        {
            if (this->empty()) {
                this->root_ = new NodeSet<Key>(value);
                this->connect_node(this->root_, &this->root_->left, this->head_);
                this->connect_node(this->root_, &this->root_->right, this->tail_);
                this->size_++;
                return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(this->root_), true);
            }

            NodeSet<Key>* it = this->root_;
            NodeSet<Key>* parent = NULL;
            while (it && it != this->head_ && it != this->tail_) {
                parent = it;
                if (value <= it->data) {
                    it = it->left;
                } else if (value > it->data) {
                    it = it->right;
                } else {
                    return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(it), false);
                }
            }

            NodeSet<Key>* result = new NodeSet<Key>(value, parent);

            if (value <= parent->data) {
                this->connect_node(parent, &parent->left, result);
                this->connect_node(result, &result->left, it);

            } else if (value > parent->data) {
                this->connect_node(parent, &parent->right, result);
                this->connect_node(result, &result->right, it);
            }
            this->size_++;
            return std::pair<SetIterator<Key>, bool>(SetIterator<Key>(result), true);
        }

    template<typename Key>
    void multiset<Key>::merge(multiset<Key>& other) {
        auto it = other.begin();
        for (; it != other.end(); it++) {
            insert(it.it->data);
        }
    }


}  //  namespace s21




#endif