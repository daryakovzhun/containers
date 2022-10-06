#include<iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
    list<string> a;
    list<string> b;
    b.operator=(a);
    
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}