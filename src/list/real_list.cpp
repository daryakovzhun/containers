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
    list <int>::const_iterator it;
    // cout << a.max_size() << endl;
    // cout << b.max_size() << endl;
    // cout << c.max_size() << endl;
    // cout << d.max_size() << endl;
    return 0;
}