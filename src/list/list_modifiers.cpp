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
        tail = head = new Node<T>(value_type());
        end_ = new Node<T>(size_, head, tail);
        tail->pnext = end_;
        head->prev = end_;
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
    list<T>::list(list &&l) : tail(l.tail), head(l.head), size_(l.size_) {
        l.head = nullptr;
        l.tail = nullptr;
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
        tail = l.tail;
        size_ = l.size_;
        // }
        l.head = nullptr;
        l.tail = nullptr;
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
            if (pos != this->end()) { 
                res->pnext->prev = res.getNode();
            } else {
                tail = res.getNode();
                tail->pnext = end_;
                end_->prev = tail;
            } 
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
        erase(--this.end());
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

    }

    template <typename T>
    void list<T>::merge(list& other) {

    }

    template <typename T>
    void list<T>::splice(const_iterator pos, list& other) {
        if (!other.empty()) {
            const_iterator temp = pos;
            const_iterator check = other.const_begin();
            while(check != other.tail) {
                if (check == temp) {
                    other.clear();
                    return;
                }
                ++check;
            }
            if (pos.getNode() == head || pos.getNode() == end_ ) {
                head = other.head;
            } else {
                pos->prev->pnext = other.head;
                other.head->prev = pos->prev;
            }
            if (this->empty()) {tail = other.tail; tail->pnext = end_;}
            else {
                other.tail->pnext = temp.getNode();
                temp->prev = other.tail;
            }
            other.head = other.tail = nullptr;
            size_ += other.size_;
            other.size_ = 0;
        }
    }

    template <typename T>
    void list<T>::reverse() {
        iterator it = this->begin();     
        int count = size_ + 1;
        while(count--) {
            Node<T> *temp = it.getNode()->pnext;
            it.getNode()->pnext = it.getNode()->prev;
            it.getNode()->prev = temp;
            ++it;
        }
        Node<T> *temp = head;
        head = tail;
        tail = temp;
    }

    template <typename T>
    void list<T>::unique() {
        iterator it = this->begin(), temp = it->pnext;
        while(!this->empty() && it->pnext != tail) {
            while (it.getNode()->data == temp.getNode()->data) {
                ++temp;
                erase(it->pnext);
            }
            ++it, ++temp;
        }
    }

    template <typename T>
    void list<T>::sort() {

    }

    template<typename T>
    void list<T>::erase(iterator pos) {
        if (head != tail) {
            if (pos == this->begin()) {
                pos->pnext->prev = end_;
                head = pos->pnext;
                end_->pnext = head;
            } else if (pos == --this->end()) {
                pos = tail;
                pos->prev->pnext = end_;
                tail = pos->prev;
                end_->prev = tail;
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
            this->end_ = this->head = nullptr;
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

    s21::list <int> a = {-3,-2,-1};
    // s21::list <int> b = {7,8,9};
    // s21::list <int> c{};

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);


    s21::list <int>::iterator sth = a.begin();
    sth.shift(0);
    a.insert(sth, 666);
    a.erase(a.begin());
    a.Print_list();
    return 0;
}