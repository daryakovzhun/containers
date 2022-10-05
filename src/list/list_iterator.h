#ifndef SRC_LIST_ITERATOR_H__
#define SRC_LIST_ITERATOR_H__

namespace s21 {
    template <typename T> 
    class Node{
        public:
            Node *pnext;
            Node *prev;
            T data;
            Node (T data = T(), Node *pnext = nullptr, Node *prev = nullptr) {
                this->pnext =  pnext;
                this->prev = prev;
                this->data = data;
            }

    };

    template<typename T>
    class ListIterator
    {
    public:
        ListIterator();
        ListIterator(Node<T>* node);
        ListIterator<T>& operator--();
        ListIterator<T>& operator++();
        const T& operator*() const;
        bool operator!=(const ListIterator<T>& it) const;
        bool operator==(const ListIterator<T>& it) const;

        ListIterator<T>& shift(int n); // for me 

    private:
        Node<T>* _currentNode;
    };

    template<class T>
    ListIterator<T>::ListIterator()
    { }



    template<class T>
    ListIterator<T>::ListIterator(Node<T>* node)
        : _currentNode(node)
    { }

    template<class T>
    ListIterator<T>& ListIterator<T>::operator++()
    {
        _currentNode = _currentNode->pnext;
        return *this;
    }

    template<class T>
    ListIterator<T>& ListIterator<T>::operator--()
    {
        _currentNode = _currentNode->prev;
        return *this;
    }


    template<class T>
    const T& ListIterator<T>::operator*() const
    {
        return _currentNode->data;
    }

    template<class T>
    bool ListIterator<T>::operator!=(const ListIterator<T>& it) const
    {
        return _currentNode != it._currentNode;
    }

    template<class T>
    bool ListIterator<T>::operator==(const ListIterator<T>& it) const {
        return _currentNode == it._currentNode;
    }
}
#endif //  SRC_LIST_ITERATOR_H__

