#include<iostream>
#include <initializer_list>
#include "../list/s21_list.h"
#include "stack.h"
using namespace std;

int main() {
    s21::list<int> a;
    s21::stack<int> v;

    s21::stack<int> b = {1,2,3};
    s21::stack<int> c = {1,2,3};
    b = move(c);
    // b = move(c);
    // c.top();
    // a.push(1);
    // a.pop();
    // cout << a.top() << endl;
}