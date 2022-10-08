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


    list <int> a = {49, 78};
    list <int> b = {1,2,3,4};
    list<int>:: const_iterator ait = a.begin();
    list<int>:: iterator bit = a.begin();
    ++ait;
    ++ait;


    // ++ait;
    // ++ait;

    // ++bit;
    // ++bit;
    // cout << *bit << endl;
    // c.splice(cit, d);
    // print(c);
    // ++res;
    // ++res;
    // ++res;
    // ++res;
    // a.splice(res, b);
    // cout << b.size();
    

    // list <int> b = {1,2,3,4};
    // list <int> a = {};
    // list<int>::iterator it = a.begin();
    // ++it;
    a.splice(ait, b);

    // a.splice(it,b.insert(it, 45654); b);
    print(a);
    // print(a);
    // 
    // print(b);
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}