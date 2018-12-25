#include "GigeV/AppleSockets.hpp"
#include "GigeV/ISockets.hpp"
#include "gtest/gtest.h"

using namespace gigev;

TEST(Testapplesockets, simple) {
  Sockets *socket = new AppleSockets();
  ASSERT_TRUE(socket->InitSocketAPI())
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}