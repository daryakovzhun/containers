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
    list<int> a = {1,2,3};
    list<int> b = {4,5,6};
    list<int>::iterator it = a.begin();
    ++it;
    a.splice(it, b);
    // print(a);
    // 
    print(b);
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}