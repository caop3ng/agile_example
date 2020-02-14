// ext_object_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <gtest/gtest.h>

int MAX_EMP_ID = 0;

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}