#include "s21_array_tests.cc"
#include "s21_map_tests.cc"
#include "s21_queue_tests.cc"
#include "s21_set_tests.cc"

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
