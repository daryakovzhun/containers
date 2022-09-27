#ifndef SRC_S21_LIST_H
#define SRC_S21_LIST_H

#include <iostream>
#include <string>
#include <initializer_list>
#include "list_iterator.h"
using namespace std;

#define value_type  T
#define reference  T&
#define const_reference  const T&
#define size_type  size_t
#define iterator ListIterator<T>
#define const_iterator ListConstIterator<T>
template <typename T>
class list{

    public:
        // using value_type = T;
        // using reference = T&;
        // using const_reference = const T&;
        // using size_type = size_t;
        // using iterator = ListIterator<T>;
        // using const_iterator = ListConstIterator<T>;

         // List functions
        list();
        list(size_type n);
        list(std::initializer_list<value_type> const &items);
        list(const list &l);
        list(list &&l);
        ~list();
        // operator=(list &&l);

        // List element access 
        const_reference front();
        const_reference back();

        // List iterators
        iterator begin();
        iterator end();

        // List Capacity
        bool empty();
        size_type size();
        size_type max_size();

        // list modifiers
        void clear();
        iterator insert(iterator pos, const T value);
        void erase(iterator pos);
        void push_back(const_reference  value);
        void pop_back();
        void push_front(const_reference  value);
        void pop_front();
        void swap(list& other);
        void merge(list& other);
        // void splice(const_iterator pos, list& other);
        void reverse();
        void unique();
        void sort();

        void Print_list(list<T>& list); // for me



        T& operator[](int num); // for me

    private:
        class Node{
            public:
                Node *pnext;
                Node *prev;
                T data;
                Node (T data = T(), Node *pnext = nullptr, Node *prev = nullptr) {
                    this->pnext = pnext;
                    this->prev = prev;
                    this->data = data;
                }
        };

        Node *head;
        Node *tail;
        size_type count;
};

#endif //  SRC_S21_LIST_H
