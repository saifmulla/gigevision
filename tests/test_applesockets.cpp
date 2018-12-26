#include "GigeV/AppleSockets.hpp"
#include "GigeV/Sockets.hpp"
#include "gtest/gtest.h"

using namespace gigev;

TEST(TestApplesockets, simple) {
  Sockets *socket = new AppleSockets();
  ASSERT_TRUE(socket->InitSocketAPI());
  ASSERT_TRUE(socket->CloseSocketAPI());
}

TEST(TestApplesockets, networkinterfaces){
  Sockets *socket = new AppleSockets();
  ASSERT_NE(0,socket->GetMaxNetworkInterfaces());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}