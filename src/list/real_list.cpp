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


    list <int> a = {7,8,9,10};
    list <int> b = {1000};
    // cout << b.front() << endl;
    // b.push_back(1);
    // b.deleteNode(0);
    list<int>:: const_iterator res = a.begin();
        list<int>::iterator it = a.begin();
    // ++res;
    // ++res;
    // ++res;
    // ++res;
    // a.splice(res, b);
    // cout << b.size();
    ++it;
    

    // list <int> b = {1,2,3,4};
    // list <int> a = {};
    // list<int>::iterator it = a.begin();
    // ++it;
    // a.splice(it, b);

    // a.splice(it,b.insert(it, 45654); b);
    // print(b);
    // print(a);
    // 
    // print(b);
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}