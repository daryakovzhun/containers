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
    // ListIterator<T> begin(head);
    Node<T> *current = head;
    if (pos == 0) {
        push_front(value);
    } else {
        for(int i = 0; i < pos - 1; i++) {
            current = current->pnext;
        }
        current->pnext  = new Node<T>(value, current->pnext);
        ListIterator<T>(current->pnext);
        count++;
    }
}

// void erase(int pos) { // int iterator
//    Node<T> *current = head;
//     if (pos == 0) {
//         pop_front();
//     } else {
//         for(int i = 0; i < pos - 1; i++) {
//             current = current->pnext;
//         }
//         Node<T> *del_Node<T> = current->pnext;
//         current->pnext = del->pnext;
//         delete new_ins;
//         count--;
//     }
// }

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
    Node<T> *current = tail;
    if (head != tail) {
        current->prev->pnext = nullptr;
        tail = current->prev;
    }
    count--;
    delete current;
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
void list<T>::pop_front() { // исправить и проверить пустой список
    Node<T> *current = head;
    head = head->pnext;
    delete current;
    count--;

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

// перегрузка с начала
// template <typename T>
// T& list<T>::operator[](const int num) {
//     int count = 0;
//     Node<T> *current = tail;
//     while (current != nullptr) { // sega !!!
//         if (count == num) {
//             break;
//         }
//         current = current->prev;
//         count++;
//     }
//     return current->data;
// }

template <typename T>
void Print_list(list<T>& list) {
    for (int i = 0 ; i < list.size(); i++) {
        cout << list[i] << endl;
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



int main() {
    
    list <string> a;
    a.pop_back();
    // a.push_back("hello");
    // a.push_back("fggf");
    // a.push_back("ss");
    // a.push_back("dfgdf");
    // list <string> ::iterator it;
    // it = a.begin();
    // for (it; it != ++a.end(); ++it) {
    //     cout << *it << endl;
    // }
    // while (i < 4) {
    //     cout << *it;
    //     list <string> ::it++;
    //     i++;
    // }
    
    // cout << a[1] << endl;
    // a.push_back(154);
    // a.push_back(4);
    // a.push_back(5);
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // for (int i = 0 ; i < a.size(); i++) {
    //     cout << a[i] << endl;
    // }
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    return 0;
}