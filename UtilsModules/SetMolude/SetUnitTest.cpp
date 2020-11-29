#include "SetUnitTest.hpp"


void SetUnitTest::Test(){
  TestSetConstruction();
  TestPush();
  TestDelete();
  
}

void SetUnitTest::TestSetConstruction(){
  set<int> TestSet(1);
}

void SetUnitTest::TestPush(){
  TestSimplePushing();
  TestOutOfBoundsPushing();
  TestNonRepeatingValues();
}


void SetUnitTest::TestSimplePushing(){
  set<int> TestSet(1);
  TestSet.Push(1);
  testsUtils.AssetFalse(TestSet[0], 1, "Push Error");
}

void SetUnitTest::TestOutOfBoundsPushing(){
  const int SIZE_OF_SET = 1;
  int ReturnCode = 0;
  set<int> TestSet(SIZE_OF_SET);
  for (int i=0; i<SIZE_OF_SET+1;++i){
	ReturnCode = TestSet.Push(i);
  }
  if (ReturnCode!=-1){
	printf("%s\n", "Error In Pushing out of bounds");
  }
}

void SetUnitTest::TestNonRepeatingValues(){
  TestSetNonRepeatingValues test;
  test.Test();
}

void SetUnitTest::TestDelete(){
  TestSimpleDelete();
  TestDeletingWithMovingLastItems();
}

void SetUnitTest::TestSimpleDelete(){
  int LastLength, NewLength;
  set<int> TestSet(2);
  TestSet.Push(1);
  LastLength = TestSet.length();
  TestSet.Delete(1);
  NewLength = TestSet.length();
  if(LastLength==NewLength){
	printf("%s\n", "Error in deleting");
  }
}

void SetUnitTest::TestDeletingWithMovingLastItems(){
  set<int> TestSet(3);
  TestSet.Push(1);
  TestSet.Push(2);
  TestSet.Push(3);
  TestSet.Delete(2);
  if (TestSet[1] != 3){
	printf("%s\n", "Deleting with movings failed");
  }
}


///////////////////////////////////////////////////


TestSetNonRepeatingValues::TestSetNonRepeatingValues(){
  TestSet = new set<int>(SIZE_OF_SET);
}

void TestSetNonRepeatingValues::Test(){
  PushValues();
  CheckForRepeatingValues();
}

void TestSetNonRepeatingValues::PushValues(){
  TestSet->Push(1);
  TestSet->Push(2);
  TestSet->Push(1);
}

void TestSetNonRepeatingValues::CheckForRepeatingValues(){
  for(int i=0; i<SIZE_OF_SET; ++i){
	CheckSomeValueInSet(i);
  }
}

inline void TestSetNonRepeatingValues::CheckSomeValueInSet(int Index){
  CurrentValue = TestSet[0][Index];
  CurrentCheckIndex = Index;
  for(int i=0; i<SIZE_OF_SET; ++i){
	CheckIfSameValues(i);
  }
}

inline void TestSetNonRepeatingValues::CheckIfSameValues(int Index){
  if (TestSet[0][Index]==CurrentValue && Index!=CurrentCheckIndex){                                    	printf("%s\n", "Error in Pushin same values");                              
  }
}
