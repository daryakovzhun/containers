#include "s21_multiset.h"

int main() {
    s21::multiset<int> m21 {1,2,3,1,1};
    s21::multiset<int> m21_2 {3,3,3};
    m21.merge(m21_2);

    int i = 0;
    for (s21::multiset<int>::iterator it = m21.begin(); it != m21.end(); ++it, i++)
    {
        std::cout << *it << "\n";
    }

    return 0;
}