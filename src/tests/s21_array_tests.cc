#include <gmock/gmock.h>
#include <array>

#include "../array/s21_array.cc"

TEST(TestGroupName, array_init_list) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(a[i] == b[i]);
    }
}

TEST(TestGroupName, array_copy_constructor) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    std::array<int, 10>  copy_a(a);
    s21::array<int, 10>  copy_b(b);

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(a[i] == b[i]);
        ASSERT_TRUE(copy_a[i] == copy_b[i]);
    }
}

TEST(TestGroupName, array_move_constructor) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    std::array<int, 10>  move_a(std::move(a));
    s21::array<int, 10>  move_b(std::move(b));

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(a[i] == b[i]);
        ASSERT_TRUE(move_a[i] == move_b[i]);
    }
}

TEST(TestGroupName, array_at) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(a.at(i)== b.at(i));
    }
}

TEST(TestGroupName, array_swap) {
    s21::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {11, 22, 33, 44, 55};

    s21::array<int, 10> copy_a(a);
    s21::array<int, 10> copy_b(b);

    a.swap(b);

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(a[i] == copy_b[i]);
        ASSERT_TRUE(b[i] == copy_a[i]);
    }
}

TEST(TestGroupName, array_fill) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    a.fill(55);
    b.fill(55);

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(a[i] == b[i]);
    }
}

TEST(TestGroupName, array_operator_eq_move) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    std::array<int, 10> a1 = {11, 22, 33, 44, 55};
    
    s21::array<int, 10> b = {1, 2, 3, 4, 5};
    s21::array<int, 10> b1 = {11, 22, 33, 44, 55};

    a = std::move(a1);
    b = std::move(b1);

    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(a[i] == b[i]);
        ASSERT_TRUE(a1[i] == b1[i]);
    }
}

TEST(TestGroupName, array_size) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    ASSERT_TRUE(a.size() == b.size());
}

TEST(TestGroupName, array_max_size) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    ASSERT_TRUE(a.max_size() == b.max_size());
}

TEST(TestGroupName, array_front) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    ASSERT_TRUE(a.front() == b.front());
}

TEST(TestGroupName, array_back) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    ASSERT_TRUE(a.back() == b.back());
}

TEST(TestGroupName, array_data) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    ASSERT_TRUE(*(a.data()) == *(b.data()));
}

TEST(TestGroupName, array_begin) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    ASSERT_TRUE(*(a.begin()) == *(b.begin()));
}

TEST(TestGroupName, array_end) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    ASSERT_TRUE(*(a.end() - 1) == *(b.end() - 1));
}

TEST(TestGroupName, array_not_empty) {
    std::array<int, 10> a = {1, 2, 3, 4, 5};
    s21::array<int, 10> b = {1, 2, 3, 4, 5};

    ASSERT_TRUE(a.empty() == b.empty());
}

TEST(TestGroupName, array_empty) {
    std::array<int, 0> a;
    s21::array<int, 0> b;

    ASSERT_TRUE(a.empty() == b.empty());
}
