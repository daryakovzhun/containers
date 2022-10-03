#include <gmock/gmock.h>
#include <queue>

#include "../queue/s21_queue.cc"

using namespace std;

TEST(TestGroupName, front) {
    queue<int> check;
    S21Queue<int> q;

    for (int i = 0; i < 50; i++) {
        check.push(i);
        q.push(i);

        if (i % 3 == 0) {
            check.pop();
            q.pop();
        }
    }

    ASSERT_TRUE(check.front() == q.front());
    ASSERT_TRUE(q.size() == check.size());
}

TEST(TestGroupName, back) {
    queue<int> check;
    S21Queue<int> q;

    for (int i = 0; i < 50; i++) {
        check.push(i);
        q.push(i);

        if (i % 3 == 0) {
            check.pop();
            q.pop();
        }
    }

    ASSERT_TRUE(check.back() == q.back());
    ASSERT_TRUE(q.size() == check.size());
}

TEST(TestGroupName, swap) {
    S21Queue<int> check;
    S21Queue<int> buffer;
    S21Queue<int> q;

    for (int i = 0; i < 50; i++) {
        buffer.push(i);
        check.push(i);

        if (i % 3 == 0) {
            buffer.pop();
            check.pop();
        }
    }

    for (int i = 50; i < 70; i++) {
        q.push(i);

        if (i % 3 == 0) {
            q.pop();
        }
    }

    q.swap(buffer); 

    ASSERT_TRUE(q.back() == check.back());
    ASSERT_TRUE(q.size() == check.size());
    ASSERT_TRUE(q.front() == check.front());
    ASSERT_TRUE((q != check) == false);
}

TEST(TestGroupName, not_empty) {
    S21Queue<int> q;

    for (int i = 0; i < 50; i++) {
        q.push(i);

        if (i % 3 == 0) {
            q.pop();
        }
    }
    ASSERT_TRUE(q.empty() == false);
}

TEST(TestGroupName, empty) {
    S21Queue<int> q;
    ASSERT_TRUE(q.empty() == true);
}

TEST(TestGroupName, operator_not_eq) {
    S21Queue<int> buffer;
    S21Queue<int> q;
    S21Queue<int> q2;

    for (int i = 0; i < 50; i++) {
        buffer.push(i);
        q2.push(i);

        if (i % 3 == 0) {
            buffer.pop();
            q2.pop();
        }
    }

    for (int i = 50; i < 70; i++) {
        q.push(i);

        if (i % 3 == 0) {
            q.pop();
        }
    }

    ASSERT_TRUE( (q != buffer) == true);
    ASSERT_TRUE( (q2 != buffer) == false);
}

TEST(TestGroupName, operator_eq) {
    S21Queue<int> q;
    S21Queue<int> buffer;

    for (int i = 0; i < 50; i++) {
        buffer.push(i);
        q.push(i);

        if (i % 3 == 0) {
            buffer.pop();
        }
    }

    S21Queue<int> check(buffer);
    q = move(buffer);

    ASSERT_TRUE(q.front() == check.front());
    ASSERT_TRUE(q.back() == check.back());
    ASSERT_TRUE(q.size() == check.size());
    ASSERT_TRUE((q != check) == false);
}

TEST(TestGroupName, constructor_init_list) {
    S21Queue<int> q{3, 5, 2, 1, 6};
    S21Queue<int> check;
    check.push(3);
    check.push(5);
    check.push(2);
    check.push(1);
    check.push(6);

    ASSERT_TRUE((q != check) == false);
}

TEST(TestGroupName, constructor_move) {
    S21Queue<int> q{3, 5, 2, 1, 6};
    S21Queue<int> check(move(q));

    ASSERT_TRUE((q != check) == true);
    ASSERT_TRUE(q.size() == 0);
}

