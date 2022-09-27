#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <queue>

#include "../queue/s21_queue.cpp"

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
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
