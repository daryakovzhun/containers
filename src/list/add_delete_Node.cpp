// #include"s21_list.h"



// // template<typename T>
// // void list<T>::deleteNode(size_type pos) {

// //     // Node<T>* prt = this->head->next;

// //     // if (!this->count)
// //     //     return ;
// //     // for (size_type i = 0; i < pos && ptr && ptr->next != this->tail; i++)
// //     //     ptr = ptr->next;
// //     // if (!ptr || ptr == this->tail)
// //     //     return ;
// //     // Node<T>* prev = ptr->prev;
// //     // ptr->prev->next = ptr->next;
// //     // ptr->next->prev = prev;
// //     // this->_size--;
// //     // delete ptr;
// // }

// template<typename T>
// Node<T>* list<T>::addNode(const T& value, size_type pos) {
//     Node<T> *current = head;
//     // if (pos == 0) {
//     //     push_front(value);
//     // } else {
//     //     for(int i = 0; i < pos - 1; i++) {
//     //         current = current->pnext;
//     //     }
//     //     current->pnext  = new Node<T>(value, current->pnext, current);
//     // }
//     return current;
//     // return(current->pnext);
// }