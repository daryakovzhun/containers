#include "s21_list.h"
#include <string.h>

// List functions
template <typename T>
void list<T>::clear() {
    for (int i = 0;i < this->size(); ) {
        this->pop_front();
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

template <typename T>
ListIterator<T> list<T>::insert(iterator pos, const T value) {
    size_t n = distance(pos);
    ListIterator<T> it(addNode(value, n));
    return it;
}

template <typename T>
void list<T>::erase(iterator pos) {

}

template <typename T>
void list<T>::push_back(const_reference  value) {
    Node<T> *add = new Node<T>(value, nullptr, tail);
    if(head == nullptr) {
        head = add;
    } else {
        tail->pnext = add;
    }
    tail = add;
    count++;
}

template <typename T> // проверить пустой список 
void list<T>::pop_back() {
    deleteNode(this->count - 1);
    // Node<T> *current = tail;
    // if (head != tail) {
    //     current->prev->pnext = nullptr;
    //     tail = current->prev;
    // }
    // count--;
    // delete current;
}

template <typename T> 
void list<T>::push_front(const_reference value) {
    Node<T> *add = new Node<T>(value, head, nullptr);
    if (tail == nullptr) {
        tail = add;
    } else {
        head->prev = add;
    }
    head = add;
    count++;
}

template <typename T>
void list<T>::pop_front() {
    deleteNode(0);
    // Node<T> *current = head;
    // if (head != tail) {
    //     current->pnext->prev = nullptr;
    //     head = current->pnext;
    // }
    // count--;
    // delete current;
}


template<typename T>
Node<T>* list<T>::addNode(const T& value, size_type pos) {
    Node <T> *res;
    if (pos == 0) {
        push_front(value);
        res = head;
    } else {
        Node<T> *current = head;
        for(int i = 0; i < pos - 1; i++) {
            current = current->pnext;
        }
        current->pnext  = new Node<T>(value, current->pnext, current);
        res = current->pnext;
    }
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
    iterator it = this->begin();
    for (; it != this->end(); ++it) {
        cout << *it << endl;
    }
}

/******************************************************************/

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

}

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
    a.push_back("fff");
    // a.push_back("fggf");
    // a.push_back("ss");
    // a.push_back("dfgdf");
    a.pop_front();
    a.Print_list();


    // ListIterator<string> it;
    // it = a.begin();
    // it.shift(3);
    // a.insert(it, "Helloworld");
    // a.Print_list();
    // shift(it, 3);
    // a.insert(it, "Helloworld");
    // while (i < 4) {
    //     cout << *it;
    //     list <string> ::it++;
    //     i++;
    // }
    return 0;
}