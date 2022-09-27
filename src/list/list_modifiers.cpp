#include "S21_list.h"

// List functions
template <typename T>
void list<T>::clear() {
    for (int i = 0;i < this->size(); ) {
        this->pop_front();
    }
}


template <typename T>
list<T>::list() {
    count = 0;
    head = nullptr;
    tail = nullptr;
}

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

/* iterator insert(iterator pos, const T value) {
    Node *current = head;
    if (pos == 0) {
        push_front(value);
    } else {
        for(int i = 0; i < pos - 1; i++) {
            current = current->pnext;
        }
        current->pnext  = new Node(value, current->pnext);
        count++;
    }
}*/

// void erase(int pos) { // int iterator
//    Node *current = head;
//     if (pos == 0) {
//         pop_front();
//     } else {
//         for(int i = 0; i < pos - 1; i++) {
//             current = current->pnext;
//         }
//         Node *del_node = current->pnext;
//         current->pnext = del->pnext;
//         delete new_ins;
//         count--;
//     }
// }

template <typename T>
void list<T>::push_back(const_reference  value) {
    Node *add = new Node(value, nullptr, tail);
    if(head == nullptr) {
        head = add;
    } else {
        tail->pnext = add;
    }
    tail = add;
    // cout << head->prev << " " << head->pnext << endl;
    // cout << tail->prev << " " << tail->pnext << endl;
    count++;
}

template <typename T> // !!!!!!!!!!!!!!!!!!!!!!!1
void list<T>::pop_back() {
    Node *current = tail;
    if (head != tail) {
        current->prev->pnext = nullptr;
        tail = current->prev;
    }
    count--;
    delete current;
}

template <typename T> 
void list<T>::push_front(const_reference value) {
    Node *add = new Node(value, head, nullptr);
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
    Node *current = head;
    head = head->pnext;
    delete current;
    count--;
}



// перегрузка с конца
template <typename T>
T& list<T>::operator[](const int num) {
    int count = 0;
    Node *current = head;
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
//     Node *current = tail;
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
size_type list<T>::size() {
    return this->count;
}

template <typename T>
size_type list<T>::max_size() {

}



int main() {
    
    list <int> a;
    a.push_front(4);
    a.pop_back();
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(7);
    // a.push_back(154);
    // a.push_back(4);
    // a.push_back(5);
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();

    cout << "-------------------" << endl;
    Print_list(a);
    // for (int i = 0 ; i < a.size(); i++) {
    //     cout << a[i] << endl;
    // }
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    return 0;
}