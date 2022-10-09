#include<iostream>
#include <list>
#include <iterator>
using namespace std;

void print(list<int> const &list)
{
    for (auto const &i: list) {
        std::cout << i << std::endl;
    }
}

int main() {


    list <int> a = {1,2,3,4};
    list <int> b = {7,8,9};
    list <int> c(4);


    list<int>:: const_iterator ait = a.end();
    a.erase(ait);


    // // b.insert(bit, 55);
    // c.splice(ait, a); // continue
    // cout << a.tail->prev->data << endl; 
    // a.splice(it,b.insert(it, 45654); b);
    // print(b);
    // print(a);
    print(a);
    // print(a);
    // 
    // print(b);
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}