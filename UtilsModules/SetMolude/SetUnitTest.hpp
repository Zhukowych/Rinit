
#ifndef SET_UNIT_TEST_HPP_
#define SET_UNIT_TEST_HPP_
#include "../../TestsUtils/TestsUtils.hpp"
#include "Set.hpp"
#include <stdio.h>



class TestSetNonRepeatingValues{
public:
  TestSetNonRepeatingValues();
  void Test();
private:
  const int SIZE_OF_SET = 3;
  set<int> *TestSet;
  int CurrentValue, CurrentCheckIndex;
  void PushValues();
  void CheckForRepeatingValues();
  inline void CheckSomeValueInSet(int Index);
  inline void CheckIfSameValues(int Index);
};

class SetUnitTest{
public:
  void Test();
  void TestSetConstruction();
  void TestPush();
  void TestDelete();
  void TestSimplePushing();
  void TestOutOfBoundsPushing();
  void TestNonRepeatingValues();
  void TestSimpleDelete();
  void TestDeletingWithMovingLastItems();
private:
  TestsUtils testsUtils;

};


#endif
