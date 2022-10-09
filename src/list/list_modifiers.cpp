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
        size_t n = distance(pos);
        // cout << n << " " << value << endl;
        auto it(addNode(value, n));
        return it;
    }

    template <typename T>
    void list<T>::erase(iterator pos) {
        size_t n = distance(pos);
        deleteNode(n);
    }

    template <typename T>
    void list<T>::push_back(const_reference  value) {
        addNode(value, this->size_);
    }

    template <typename T>
    void list<T>::pop_back() {
        deleteNode(this->size_ - 1);
    }

    template <typename T> 
    void list<T>::push_front(const_reference value) {
        addNode(value, 0);
    }

    template <typename T>
    void list<T>::pop_front() {
        deleteNode(0);
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
        Node<T> *t = head;
        head = tail;
        tail = t;
    }

    template <typename T>
    void list<T>::unique() {
        iterator it = this->begin(), temp = it->pnext;
        while(it != this->end()) {
            while (it.getNode()->data == temp.getNode()->data) {;
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
    Node<T>* list<T>::addNode(const T& value, size_type pos) {
        Node <T> *res;
        if (!size_) {
            head->data = value;
            res = head = tail;
        } else if (pos == 0) {
            head = head->prev = new Node<T>(value, head, end_);       
            end_->pnext = head;                                                                                                   
            res = head;
        } else {
            Node<T> *current = head;
            for(int i = 0; i < pos - 1; i++) {
                current = current->pnext;
            }                                                                        
            current->pnext  = new Node<T>(value, current->pnext, current);
            res = current->pnext;
            if (pos != size_) { 
                res->pnext->prev = res;
            } else {
                tail = res;
                tail->pnext = end_;
                end_->prev = tail;
            } 
        }
        size_++;
        this->end_->data = size_;
        return res;
    }

    template<typename T>
    void list<T>::deleteNode(size_type pos) {
        if (head != tail) {
            Node <T> *current = this->head;
            if (pos == 0) {
                current->pnext->prev = end_;
                head = current->pnext;
                end_->pnext = head;
            } else if (pos == size_ - 1) {
                current = tail;
                current->prev->pnext = end_;
                tail = current->prev;
                end_->prev = tail;
            } else {
                for (size_type i = 0; i < pos; i++) {
                    current = current->pnext;
                } 
                current->prev->pnext = current->pnext;
                current->pnext->prev = current->prev;
            }
            size_--;
            delete current;
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
        while (current != nullptr) { // sega !!!
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

    s21::list <int> a = {9,8,8, 8,8,8,8,8,8,8,8,9,9,9};
    s21::list <int> b = {7,8,9};
    s21::list <int> c{};
    a.unique();
    s21::list <int>::iterator sth = a.begin();
    a.Print_list();
    return 0;
}