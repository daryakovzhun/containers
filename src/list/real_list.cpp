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


    list <int> a = {4,3,2,1,6,5,8,7};
    list<string> b = {"hello", "world"};
    list<char> c = {'y', 'l'};
    list<float> d = {1.5, 2.8};
    cout << a.max_size() << endl;
    cout << b.max_size() << endl;
    cout << c.max_size() << endl;
    cout << d.max_size() << endl;
    // // b.insert(bit, 55);
    // c.splice(ait, a); // continue
    // cout << a.tail->prev->data << endl; 
    // a.splice(it,b.insert(it, 45654); b);
    // print(b);
    // print(a);
    // cout << "**" << b.size() << "**" << endl;
    // print(a);
    // 
    // print(b);
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}