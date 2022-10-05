#include<iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
    list<string> a;
    // a.push_back("gg");
    cout << *a.end();
    
    // list<int>::iterator it = a.begin();
   
    // cout << *it << endl;

    return 0;
}