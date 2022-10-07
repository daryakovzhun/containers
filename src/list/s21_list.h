#ifndef SRC_S21_LIST_H
#define SRC_S21_LIST_H

#include <iostream>
#include <initializer_list>
#include "node.h"
#include "list_iterator.h"
#include "list_const_iterator.h"
#include <utility>

using namespace std;


// #define value_type  T
// #define reference  T&
// #define const_reference  const T&
// #define size_type  size_t
// #define iterator ListIterator<T>
// #define const_iterator ListConstIterator<T>
namespace s21 {
    template <typename T>
    class list{
        
        public:
            using value_type = T;
            using reference = T&;
            using const_reference = const T&;
            using size_type = size_t;
            using iterator = ListIterator<T>;
            using const_iterator = ListConstIterator<T>;

            // List functions
            list();
            list(size_type n);
            list(std::initializer_list<value_type> const &items);
            list(const list &l);
            list(list &&l);
            ~list();
            list<T>& operator=(list &&l) noexcept;

            // List element access 
            const_reference front() {return head->data;}
            const_reference back() {return tail->data;}

            // List iterators
            iterator begin() {return iterator(head);}
            iterator end() {return iterator(tail);}

            const_iterator const_begin() {return const_iterator(head);}
            const_iterator const_end() {return const_iterator(tail);}

            // List Capacity
            bool empty() {return !this->size();}
            size_t size() {return this->size_;}
            //size_t max_size() {return std::numeric_limits<T>::max();}; // size_type

            // list modifiers
            void deleteNode(size_type pos);
            Node<T>* addNode(const T& value, size_type pos);
            void clear();
            iterator insert(iterator pos, const_reference value);
            void erase(iterator pos);
            void push_back(const_reference  value);
            void pop_back();
            void push_front(const_reference  value);
            void pop_front();
            void swap(list& other);
            void merge(list& other);
            void splice(const_iterator pos, list& other);
            void reverse();
            void unique();
            void sort();





            // functions for me 

            void Print_list(); // for me


            T& operator[](int num); // for me

            size_t	distance(iterator it) {
                ListIterator<T> start = this->begin();
                size_t n = 0;
                while(start != it) {
                    n++;
                    ++start;
                }
                return (n);
            }   

            



        private:

            Node<T> *head;
            Node<T> *tail;
            size_type size_;
    };
}



#endif // SRC_S21_LIST_H