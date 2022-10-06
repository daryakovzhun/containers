#ifndef SRC_LIST_ITERATOR_H__
#define SRC_LIST_ITERATOR_H__
#include "node.h"
namespace s21 {
    template<typename T>
    class ListIterator
    {
    using reference = T&;
    public:
        ListIterator() {};
        ListIterator(Node<T>* node) : _currentNode(node) {}
        ListIterator<T>& operator--() {
            _currentNode = _currentNode->prev;
            return *this;            
        }
        ListIterator<T>& operator++() {
            _currentNode = _currentNode->pnext;
            return *this;           
        }
        const T& operator*() {return _currentNode->data;}
        bool operator!=(const ListIterator<T>& it) {return _currentNode != it._currentNode;}
        bool operator==(const ListIterator<T>& it) {return _currentNode == it._currentNode;}

        ListIterator<T>& shift(int n); // for me 

    private:
        Node<T>* _currentNode;
    };
}
#endif //  SRC_LIST_ITERATOR_H__
