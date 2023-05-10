/**
 * @file main.cpp
 * @author Naveen Mangla (nmangla@terpmail.umd.edu)
 * @brief Test main file
 * @version 0.1
 * @date 2023-05-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <gtest/gtest.h>
int my_argc;
char** my_argv;
int main(int argc, char** argv) {
  my_argc = argc;
  my_argv = argv;
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}