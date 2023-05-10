#include <gtest/gtest.h>
#include <network.h>
#include <station.h>



TEST(Station, GetPath) {  
  Station s(my_argv[1], my_argv[2]);
  s.get_path();
  EXPECT_TRUE(s.reached);
}


TEST(Station, GetStation) {  
  Station s(my_argv[1], my_argv[2]);
  auto st = s.get_station(my_argv[1]);
  EXPECT_EQ(network[st].name,my_argv[1]);
}





