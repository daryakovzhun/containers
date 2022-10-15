#ifndef SRC_LIST_CONST_ITERATOR_H__
#define SRC_LIST_CONST_ITERATOR_H__
#include "node.h"
#include "list_iterator.h"

namespace s21 {
    template<typename T>
    class ListConstIterator
    {
    public:
        using const_reference = const T&;
        ListConstIterator() {};
        ListConstIterator(Node<T>* node) : _currentNode(node) {}
        ListConstIterator<T>& operator--() {
            _currentNode = _currentNode->prev;
            return *this;            
        }
        ListConstIterator<T>& operator++() {
            _currentNode = _currentNode->pnext;
            return *this;           
        }
        const_reference operator*() const {return _currentNode->data;}
        bool operator!=(const ListConstIterator<T>& it) const {return _currentNode != it._currentNode;}
        bool operator==(const ListConstIterator<T>& it) const {return _currentNode == it._currentNode;}

        Node<T>* getNode() {return _currentNode;}
        Node<T>* operator->() {return _currentNode;}
        ListConstIterator<T>& shift(int n) {
            while (n > 0) {
                ++(*this);
                n--;
            }
            return *this;
        }
    private:
        Node<T>* _currentNode;
    };
}
#endif //  SRC_LIST_CONST_ITERATOR_H__
