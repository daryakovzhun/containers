#ifndef SRC_LIST_ITERATOR_H__
#define SRC_LIST_ITERATOR_H__
#include "node.h"
// #include "list_const_iterator.h"

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
        reference operator*() {return _currentNode->data;}
        bool operator!=(const ListIterator<T>& it) {return _currentNode != it._currentNode;}
        bool operator==(const ListIterator<T>& it) {return _currentNode == it._currentNode;}

        Node<T>* getNode() {return _currentNode;}
        Node<T>* operator->() {return _currentNode;}
        ListIterator<T>& shift(int n); // for me 
        // operator ListConstIterator<T>() const { return ListConstIterator<T>(_currentNode); }
    private:
        Node<T>* _currentNode;
    };
}
#endif //  SRC_LIST_ITERATOR_H__
