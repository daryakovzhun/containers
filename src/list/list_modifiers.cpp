#include "s21_list.h"
#include <string.h>
#include <limits>
// List functions

namespace s21 {
    template <typename T>
    void list<T>::clear() {
        if (!size_) {deleteNode(0);} else {
            for (size_t i = 0; i < this->size(); ) {
                deleteNode(i);
            }
        }
        // for (auto it = this->begin(); it != end(); ++it) {
        //     cout << distance(it) << endl;
        //     deleteNode(distance(it));
        // }
    }

    template <typename T>
    list<T>::list() : size_(0) {
        tail = head = new Node<T>(value_type());
        head->pnext = tail;
        tail->prev = head;
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

    template<typename T>
    Node<T>* list<T>::addNode(const T& value, size_type pos) {
        Node <T> *res;
        if (!size_) {
            head->data = value;
            res = head = tail;// = new Node<T>(value); ??
        } else if (pos == 0) {
            head = head->prev = new Node<T>(value, head);                                                                                                          
            res = head;
        } else {
            // cout << "***" << (head->pnext == tail) << "***" << endl;
            Node<T> *current = head;
            for(int i = 0; i < pos - 1; i++) {
                current = current->pnext;
            }                                                                        
            current->pnext  = new Node<T>(value, current->pnext, current);
            res = current->pnext;
            if (pos != size_) { res->pnext->prev = res;} else {tail = res;}
        }
        size_++;
        return res;
    }

    template<typename T>
    void list<T>::deleteNode(size_type pos) {
        Node <T> *current = head;
        if (head != tail) {
            if (pos == 0) {
                current->pnext->prev = nullptr;
                head = current->pnext;
            } else if (pos == size_ - 1) {
                current = tail;
                current->prev->pnext = nullptr;
                tail = current->prev;
            } else {
                for (size_type i = 0; i < pos; i++) {
                    current = current->pnext;
                    current->prev->pnext = current->pnext;
                    current->pnext->prev = current->prev;
                } 
            }
        } 
        size_--;
        delete current;
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
            iterator it = this->begin();
            for (; it != this->end(); ++it) {
                cout << *it << endl;
            }
            cout << back() << endl;
        }
    }

    /******************************************************************/


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

    s21::list <int> a = {1, 2, 3};
    s21::list <int> b = {7,5};
    b.operator=(std::move(a));
    // cout << a.front() << endl;
    
    // cout << a.front();
    // cout << a.max_size() << endl;
    // a.push_front(1454);
    // a.push_back(4);
    // a.push_back(98);
    // a.push_front(4);
    a.Print_list();
    // list<string>::iterator it(a.begin());
    // it.shift(2);
    // a.erase(it);
    // a.Print_list();
    return 0;
}