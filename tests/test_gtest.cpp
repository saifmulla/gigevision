#include "gtest/gtest.h"

TEST(TestGtest, simple) { SUCCEED(); }

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}