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
    list <int> b = {7};
   

    list<int>:: const_iterator ait = a.begin();
    ++ait;
    // ait.shift(4);

    // // cout << *ait;

    // // b.insert(bit, 55);
    b.splice(ait, a); // continue
    // cout << a.tail->prev->data << endl; 
    // a.splice(it,b.insert(it, 45654); b);
    print(b);

    // print(a);
    // 
    // print(b);
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}