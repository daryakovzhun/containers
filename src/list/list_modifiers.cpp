#include "s21_list.h"
#include <string.h>

// List functions
template <typename T>
void list<T>::clear() {
    for (int i = 0;i < this->size(); ) {
        deleteNode(i);
    }
}


template <typename T>
list<T>::list() : count(0), head(nullptr), tail(nullptr) {}

template<typename T>
list<T>::list(size_type n) {
    
}

template<typename T>
list<T>::list(std::initializer_list<value_type> const &items) {
    
}

template<typename T>
list<T>::list(const list &l) {
    
}

template<typename T>
list<T>::list(list &&l) {
    
}

template <typename T>
list<T>::~list() {
    clear();
}

// List element access 
template <typename T>
const T& list<T>::front(){return this->head;}

template <typename T>
const T& list<T>::back(){return this->tail;}


// List iterators
template <typename T>
ListIterator<T> list<T>::begin() {return iterator(head);}

template <typename T>
ListIterator<T> list<T>::end() {return iterator(nullptr);};


// List Capacity
template <typename T>
bool list<T>::empty() {
    return !this->size();
}

template <typename T>
size_t list<T>::size() {
    return this->count;
}

template <typename T>
size_t list<T>::max_size() {

    return 0;
}


template <typename T>
ListIterator<T> list<T>::insert(iterator pos, const T value) {
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
    addNode(value, this->count);
}

template <typename T>
void list<T>::pop_back() {
    deleteNode(this->count - 1);
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
    if (!count) {
        res = head = tail = new Node<T>(value);
    } else if (pos == 0) {
        head = head->prev = new Node<T>(value, head);
        res = head;
    } else {
        Node<T> *current = head;
        for(int i = 0; i < pos - 1; i++) {
            current = current->pnext;
        }
        current->pnext  = new Node<T>(value, current->pnext, current);
        res = current->pnext;
        if (pos != count) { res->pnext->prev = res;} else {tail = res;}
    }
    count++;
    return res;
}

template<typename T>
void list<T>::deleteNode(size_type pos) {
    if (!count) {
        return;
    }
    Node <T> *current = head;
    if (head != tail) {
        if (pos == 0) {
            current->pnext->prev = nullptr;
            head = current->pnext;
        } else if (pos == count - 1) {
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
    count--;
    delete current;
}


// перегрузка с конца
template <typename T>
T& list<T>::operator[](const int num) {
    int count = 0;
    Node<T> *current = head;
    while (current != nullptr) { // sega !!!
        if (count == num) {
            break;
        }
        current = current->pnext;
        count++;
    }
    return current->data;
}

template <typename T>
void list<T>::Print_list() {
    if (count) {
        iterator it = this->begin();
        for (; it != this->end(); ++it) {
            cout << *it << endl;
        }
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

int main() {

    list <string> a;
    a.push_back("back");
    a.push_front("front");
    a.push_back("back2");
    list<string>::iterator it(a.begin());
    it.shift(2);
    a.erase(it);
    a.Print_list();
    return 0;
}