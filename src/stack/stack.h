#ifndef SRC_S21_STACK_H
#define SRC_S21_STACK_H

#include <iostream>
#include <initializer_list>

#include <stack>
using namespace std;

namespace s21 {
    template <typename T>
    class stack{
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;
        public:
            stack();
            stack(std::initializer_list<value_type> const &items);
            stack(const stack &s);
            stack(stack &&s);
            ~stack();
            stack<T>& operator=(stack &&s);
            const_reference top();
            bool empty() {};
            size_type size();
            void push(const_reference value);
            void pop();
            void swap(stack& other);
        private:
            Node<T>* head;
            size_type size_;
    };
}

// int main() {
//     s21::stack<int> a;
//     // cout << a.empty() << endl;
// }
#endif 