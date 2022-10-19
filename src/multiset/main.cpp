#include "s21_multiset.h"

int main() {
    s21::multiset<int> ss;
    ss.insert(1);

    for (s21::multiset<int>::iterator it = ss.begin(); it != ss.end(); ++it)
    {
        std::cout << *it << "\n";
    }

}