#include "simplevector.h"
#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "tests.cpp"
using namespace std;


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestConstruction);
  RUN_TEST(tr, TestPushBack);
  RUN_TEST(tr, TestCopyAssignment);
  return 0;
}
