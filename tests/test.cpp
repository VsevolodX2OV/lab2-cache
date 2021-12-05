//Copyright 2021 by Winter Solider

#ifndef TEST_CPP_
#define TEST_CPP_

#include <gtest/gtest.h>
#include "Check.h"
#include "Time.h"


TEST(ExperimentTest, printTest) {
  Check e(0, _reverse, 838860);
  e.run();
  std::stringstream ss;
  e.print(ss);
  std::string s("\t- experiment:\n"
      "\t\tnumber: 0\n"
      "\t\tinput_data:\n"
      "\t\t\tbuffer_size: "+
      Byte_value(e.size) +
      "\n\t\tresults:\n"
      "\t\t\tduration: "+ std::to_string(e.time) +" ms\n");
  std::string s2 = ss.str();
  ASSERT_EQ(s2, s);
}
TEST(ExperimentTest, forwardTest) {
  try {
    Check e(0, _random, 80);
    char* arr = e.initArray();
    char k;
    e._random(arr, k);
    delete[] arr;
    SUCCEED();
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}
TEST(ExperimentTest, reverseTest) {
  try {
    Check e(0, _random, 80);
    char* arr = e.initArray();
    char k=0;
    e._forward(arr, k);
    delete[] arr;
    SUCCEED();
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}
TEST(ExperimentTest, randomTest) {
  try {
    Check e(0, _random,  80);
    char* arr = e.initArray();
    char k;
    e._reverse(arr, k);
    delete[] arr;
    SUCCEED();
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}
TEST(ExperimentTest, runTest) {
  try {
    Check e(0, _reverse, 838860);
    int result = e.run();
    if(result >= 0)
      SUCCEED() << result;
    else FAIL() << "Time is " << result;
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}

TEST(InvestigationTest, constructorTest) {
  try {
    std::vector<long> size = {838860, 1677721, 3355443};
    Time i(_reverse, size);
    SUCCEED();
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}

#endif // TEST_CPP_