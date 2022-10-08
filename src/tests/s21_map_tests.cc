#include <gmock/gmock.h>
#include <map>

#include "../map/s21_map.cc"

using namespace std;

TEST(TestGroupName, map_init_list) {
    s21::map<int, char> m{{3, '3'}, {2, '2'}, {5, '5'}};

    ASSERT_TRUE(m[3] == '3');
    ASSERT_TRUE(m[2] == '2');
    ASSERT_TRUE(m[5] == '5');
    ASSERT_TRUE(m[10] == char());
    m[2] = '1';
    ASSERT_TRUE(m[2] == '1');
    ASSERT_TRUE(m.size() == 4);
    auto check = m.insert(pair<int, char>(3, '0'));
    ASSERT_TRUE(check.second == false);
}

TEST(TestGroupName, map_insert_or_assign) {
    s21::map<int, int> m;
    m.insert(pair<int, int>(5, 5));
    m.insert(pair<int, int>(6, 6));
    m.insert(pair<int, int>(3, 3));
    m.insert(pair<int, int>(4, 4));
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(18, 18));
    m.insert(pair<int, int>(7, 7));
    m.insert(pair<int, int>(19, 19));
    m.insert(pair<int, int>(10, 10));
    m.insert(pair<int, int>(9, 9));
    m.insert(pair<int, int>(12, 12));

    m.insert_or_assign(3, 33);

    ASSERT_TRUE(m[3] == 33);
    ASSERT_TRUE(m.size() == 12);

    for(int x: {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 18, 19}) {
        if (x == 3) {
            ASSERT_TRUE(m[x] == 33);
        } else {
            ASSERT_TRUE(m[x] == x);
        }
    }
}

TEST(TestGroupName, map_copy_constructor) {
    s21::map<int, int> m;
    m.insert(pair<int, int>(5, 5));
    m.insert(pair<int, int>(6, 6));
    m.insert(pair<int, int>(3, 3));
    m.insert(pair<int, int>(4, 4));
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(18, 18));
    m.insert(pair<int, int>(7, 7));
    m.insert(pair<int, int>(19, 19));
    m.insert(pair<int, int>(10, 10));
    m.insert(pair<int, int>(9, 9));
    m.insert(pair<int, int>(12, 12));

    s21::map<int, int> copy(m);
    auto it_m = m.begin();
    auto it_copy = copy.begin();

    ASSERT_TRUE(m.size() == copy.size());
    for (; it_m != m.end(); it_m++, it_copy++) {
        ASSERT_TRUE(it_m.it->data.first == it_copy.it->data.first);
        ASSERT_TRUE(it_m.it->data.second == it_copy.it->data.second);
    }
}

TEST(TestGroupName, map_move_constructor) {
    s21::map<int, int> m;
    m.insert(pair<int, int>(5, 5));
    m.insert(pair<int, int>(6, 6));
    m.insert(pair<int, int>(3, 3));
    m.insert(pair<int, int>(4, 4));
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(18, 18));
    m.insert(pair<int, int>(7, 7));
    m.insert(pair<int, int>(19, 19));
    m.insert(pair<int, int>(10, 10));
    m.insert(pair<int, int>(9, 9));
    m.insert(pair<int, int>(12, 12));

     s21::map<int, int> move_m(move(m));

    ASSERT_TRUE(move_m.size() == 12);
    ASSERT_TRUE(m.size() == 0);

    for(int x: {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 18, 19}) {
        ASSERT_TRUE(move_m[x] == x);
    }
}

TEST(TestGroupName, map_operator_eq) {
    s21::map<int, int> m;
    m.insert(pair<int, int>(5, 5));
    m.insert(pair<int, int>(6, 6));
    m.insert(pair<int, int>(3, 3));
    m.insert(pair<int, int>(4, 4));
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(18, 18));
    m.insert(pair<int, int>(7, 7));
    m.insert(pair<int, int>(19, 19));
    m.insert(pair<int, int>(10, 10));
    m.insert(pair<int, int>(9, 9));
    m.insert(pair<int, int>(12, 12));

    s21::map<int, int> copy;
    copy = m;
    auto it_m = m.begin();
    auto it_copy = copy.begin();

    ASSERT_TRUE(m.size() == copy.size());
    for (; it_m != m.end(); it_m++, it_copy++) {
        ASSERT_TRUE(it_m.it->data.first == it_copy.it->data.first);
        ASSERT_TRUE(it_m.it->data.second == it_copy.it->data.second);
    }
}

TEST(TestGroupName, map_operator_eq_move) {
    s21::map<int, int> m;
    m.insert(pair<int, int>(5, 5));
    m.insert(pair<int, int>(6, 6));
    m.insert(pair<int, int>(3, 3));
    m.insert(pair<int, int>(4, 4));
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(18, 18));
    m.insert(pair<int, int>(7, 7));
    m.insert(pair<int, int>(19, 19));
    m.insert(pair<int, int>(10, 10));
    m.insert(pair<int, int>(9, 9));
    m.insert(pair<int, int>(12, 12));

     s21::map<int, int> move_m;
     move_m = move(m);

    ASSERT_TRUE(move_m.size() == 12);
    ASSERT_TRUE(m.size() == 0);

    for(int x: {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 18, 19}) {
        ASSERT_TRUE(move_m[x] == x);
    }
}

TEST(TestGroupName, map_at) {
    s21::map<int, char> m{{3, '3'}, {2, '2'}, {5, '5'}};

    m.at(2) = '9';
    ASSERT_TRUE(m[2] == '9');
    m.at(2) = '0';
    ASSERT_TRUE(m[2] == '0');
    m.at(5) = '4';
    ASSERT_TRUE(m[5] == '4');
}

TEST(TestGroupName, map_swap) {
    s21::map<int, int> m1{{3, 3}, {2, 2}, {5, 5}};
    s21::map<int, int> m2{{5, 5}, {7, 7}, {3, 3}, {4, 4}, {8, 8}, {6, 6}, {2, 2}, {1, 1}};

    s21::map<int, int> buffer_m1{{3, 3}, {2, 2}, {5, 5}};
    s21::map<int, int> buffer_m2{{5, 5}, {7, 7}, {3, 3}, {4, 4}, {8, 8}, {6, 6}, {2, 2}, {1, 1}};

    m1.swap(m2);

    ASSERT_TRUE(m1.size() == buffer_m2.size());
    ASSERT_TRUE(m2.size() == buffer_m1.size());

    for(int x: {1, 2, 3, 4, 5, 6, 7, 8}) {
        ASSERT_TRUE(m1[x] == x);
    }

    for(auto x: {2, 3, 5}) {
        ASSERT_TRUE(m2[x] == x);
    }
}

TEST(TestGroupName, map_insert_key_obj) {
    s21::map<int, int> m{{3, 3}, {2, 2}, {5, 5}};
    m.insert(0, 0);
    m.insert(9, 9);
    m.insert(25, 25);
    m.insert(7, 7);
    m.insert(1, 1);
    m.insert(-1, -1);

    ASSERT_TRUE(m.size() == 9);
    for(auto x: {-1, 0, 1, 2, 3, 5, 7, 9, 25}) {
        ASSERT_TRUE(m[x] == x);
    }
}

TEST(TestGroupName, map_merge) {
    s21::map<int, int> m{{3, 3}, {2, 2}, {5, 5}};
    s21::map<int, int> m2{{0, 0}, {9, 9}, {5, 55}, {7, 7}, {3, 33}};

    m.merge(m2);
    ASSERT_TRUE(m.size() == 6);
    for(auto x: {0, 2, 3, 5, 7, 9}) {
        ASSERT_TRUE(m[x] == x);
    }
}

TEST(TestGroupName, map_contains) {
    s21::map<int, int> m{{0, 0}, {9, 9}, {5, 55}, {7, 7}, {3, 33}};

    ASSERT_TRUE(m.size() == 5);
    for(auto x: {0, 3, 5, 7, 9}) {
        ASSERT_TRUE(m.contains(x) == true);
    }
    for(auto x: {2, 11, 26}) {
        ASSERT_TRUE(m.contains(x) == false);
    }
}

TEST(TestGroupName, map_erase_1) {
    s21::map<int, int> m{{5, 5}, {3, 3}, {6, 6}, {4, 4}, {1, 1}, {2, 2}, {18, 18}, {7, 7}, {19, 19}, {10, 10}, {9, 9}, {12, 12}};
    ASSERT_TRUE(m.size() == 12);

    auto it = m.begin();
    ++it; ++it; ++it;
    m.erase(it);

    ASSERT_TRUE(m.size() == 11);

    for(auto x: {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 18, 19}) {
        if (x == 4) {
            ASSERT_TRUE(m.contains(x) == false);
        } else {
            ASSERT_TRUE(m[x] == x);
        }
    }
}

TEST(TestGroupName, map_erase_2) {
    s21::map<int, int> m{{5, 5}, {3, 3}, {6, 6}, {4, 4}, {1, 1}, {2, 2}, {18, 18}, {7, 7}, {19, 19}, {10, 10}, {9, 9}, {12, 12}};
    ASSERT_TRUE(m.size() == 12);

    auto it = m.begin();
    ++it; ++it; ++it; ++it; ++it; ++it;
    m.erase(it);

    ASSERT_TRUE(m.size() == 11);

    for(auto x: {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 18, 19}) {
        if (x == 7) {
            ASSERT_TRUE(m.contains(x) == false);
        } else {
            ASSERT_TRUE(m[x] == x);
        }
    }
}

TEST(TestGroupName, map_erase_3) {
    s21::map<int, int> m{{5, 5}, {3, 3}, {6, 6}, {4, 4}, {1, 1}, {2, 2}, {18, 18}, {7, 7}, {19, 19}, {10, 10}, {9, 9}, {12, 12}};
    ASSERT_TRUE(m.size() == 12);

    auto it = m.begin();
    ++it; ++it;
    m.erase(it);

    ASSERT_TRUE(m.size() == 11);

    for(auto x: {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 18, 19}) {
        if (x == 3) {
            ASSERT_TRUE(m.contains(x) == false);
        } else {
            ASSERT_TRUE(m[x] == x);
        }
    }
}

TEST(TestGroupName, map_erase_4) {
    s21::map<int, int> m{{5, 5}, {3, 3}, {6, 6}, {4, 4}, {1, 1}, {2, 2}, {18, 18}, {7, 7}, {20, 20}, {10, 10}, {9, 9}, {12, 12}, {21, 21}};
    ASSERT_TRUE(m.size() == 13);

    auto it = m.begin();
    ++it; ++it; ++it; ++it; ++it; ++it; ++it; ++it; ++it; ++it;
    m.erase(it);

    ASSERT_TRUE(m.size() == 12);

    for(auto x: {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 18, 20, 21}) {
        if (x == 18) {
            ASSERT_TRUE(m.contains(x) == false);
        } else {
            ASSERT_TRUE(m[x] == x);
        }
    }
}
