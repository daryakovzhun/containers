#include<iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
    list<int> a;
     a.pop_back();
    list<int>::iterator it = a.begin();
    a.insert(it, 15);
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}