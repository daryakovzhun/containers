#include "s21_list.h"
#include <string.h>
#include <limits>
// List functions

namespace s21 {
    template <typename T>
    void list<T>::clear() {
        while (head) {
            pop_front();
        }
        if (end_) delete end_;
    }

    template <typename T>
    list<T>::list() : size_(0) {
        head = new Node<T>(value_type());
        end_ = new Node<T>(size_, head, head);
        head->prev = end_;
        head->pnext = end_;
    }

    template<typename T>
    list<T>::list(size_type n) : list() {
        while(n--) {
            this->push_back(value_type());
        }
    }

    template<typename T>
    list<T>::list(std::initializer_list<value_type> const &items) : list(){
        for (auto nodes : items) {
            this->push_back(nodes);
        }
    }

    template<typename T>
    list<T>::list(const list &l) :  list() {
        for (auto nodes : l) {
            push_back(nodes);
        }
    }

    template<typename T>
    list<T>::list(list &&l) : head(l.head), end_(l.end_), size_(l.size_) {
        l.head = nullptr;
        l.end_ = nullptr;
        l.size_ = 0;
    }

    template <typename T>
    list<T>::~list() {
        clear();
    }

    template <typename T>
    list<T>& list<T>::operator=(list &&l) noexcept {
        // if (*this != l) {
        //     this->clear();
        head = l.head;
        end_ = l.end_;
        size_ = l.size_;
        // }
        l.head = nullptr;
        l.end_ = nullptr;
        l.size_ = 0;
        return *this;
    }

    // List Capacity

    template <typename T>
    ListIterator<T> list<T>::insert(iterator pos, const_reference value) {
        iterator res;
        if (!size_) {
            head->data = value;
            res = this->begin();
        } else if (pos == this->begin()) {
            head = head->prev = new Node<T>(value, head, end_);       
            end_->pnext = head;                                                                                                   
            res = this->begin();
        } else {
            pos->prev->pnext = new Node<T>(value, pos.getNode(), pos->prev);
            res = pos->prev->pnext;      
            pos->prev = res.getNode();
        }
        size_++;
        this->end_->data = size_;
        return res;
    }


    template <typename T>
    void list<T>::push_back(const_reference  value) {
        insert(this->end(), value);
    }

    template <typename T>
    void list<T>::pop_back() {
        erase(--this->end());
    }

    template <typename T> 
    void list<T>::push_front(const_reference value) {
        insert(this->begin(), value);
    }

    template <typename T>
    void list<T>::pop_front() {
        erase(this->begin());
    }

    template <typename T>
    void list<T>::swap(list& other) {
        std::swap(this->head, other.head);
        std::swap(this->end_, other.end_);
        std::swap(this->size_, other.size_);
    }

    template <typename T>
    void list<T>::merge(list& other) {
        iterator this_it = this->begin(), other_it = other.begin();
        if(!other.empty()) {
            while(this_it != end_) {
                while(*this_it > *other_it && other_it != other.end_) {
                    this->insert(this_it, *other_it);
                    ++other_it;
                }
                ++this_it;
            }
            while(other_it != other.end()) {
                this->insert(this->end(), *other_it);
                ++other_it;
            }
        }
        other.clear();
    }

    template <typename T>
    void list<T>::splice(const_iterator pos, list& other) {
        if (!other.empty()) {
            const_iterator check = other.const_begin();
            if (this->empty()) {
                pos = end_;
                delete begin().getNode();
            }
            if (pos.getNode() == head || this->empty() ) {
                head = other.head;
            } else {
                pos->prev->pnext = other.head;
                other.head->prev = pos->prev;
            }
            other.end_->prev->pnext = pos.getNode();
            pos->prev = other.end_->prev;

            other.head = nullptr;
            size_ += other.size_;
            other.size_ = 0;
        }
    }

    template <typename T>
    void list<T>::reverse() {
        iterator it = this->begin();     
        int count = size_ + 1;
        while(count--) {
            std::swap(it.getNode()->pnext, it.getNode()->prev);
            ++it;
        }
        head = end_->pnext;
    }

    template <typename T>
    void list<T>::unique() {
        iterator it = this->begin(), temp = it->pnext;
        while(!this->empty() && it->pnext != end_) {
            while (it.getNode()->data == temp.getNode()->data) {
                ++temp;
                erase(it->pnext);
            }
            ++it, ++temp;
        }
    }

    template <typename T>
    void list<T>::sort() {
        if (size_ <= 1) {
            return;
        }
        list<T> first;
        list<T> second;
        int counter = 0;
        for (auto i : *this) {
            if (counter < size_ / 2) {
                first.push_back(i);
            } else {
                second.push_back(i);
            }
            counter++;
        }
        first.sort();
        second.sort();
        first.merge(second);
        this->swap(first);
    }

    template<typename T>
    void list<T>::erase(iterator pos) {
        if (pos == end()) {
            return;
        } 
        if (head->pnext != end_) {
            if (pos == this->begin()) {
                pos->pnext->prev = end_;
                head = pos->pnext;
                end_->pnext = head;
            } else {
                pos->prev->pnext = pos->pnext;
                pos->pnext->prev = pos->prev;
            }
            size_--;
            delete pos.getNode();
            this->end_->data = size_;
        } else {
            delete head;
            delete end_;
            this->head = this->end_ = nullptr;
        }
    }

    // перегрузка с конца
    template <typename T>
    T& list<T>::operator[](const int num) {
        int size_ = 0;
        Node<T> *current = head;
        while (current != nullptr) { 
            if (size_ == num) {
                break;
            }
            current = current->pnext;
            size_++;
        }
        return current->data;
    }

    template <typename T>
    void list<T>::Print_list() {
            if (size_) {
            for (iterator it = this->begin(); it != this->end(); ++it) {
                cout << *it << endl;
            }
        }
    }

    template <typename T>
    ListIterator<T>& ListIterator<T>::shift(int n) {
        while (n > 0) {
            ++(*this);
            n--;
        }
        return *this;
    }
}

int main() {

    s21::list <int> a = {-100,-50, 10,3};
    s21::list <int> b = {-2000,-1000,-100,10000,10};
    // s21::list <int> c{};
    s21::list <int>::const_iterator sth = a.const_end();
    s21::list <int>::iterator it = a.end();
    a.merge(b);
    b.Print_list();

    return 0;
}