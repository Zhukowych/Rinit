#include "VectorUnitTest.hpp"

void VectorUnitTest::Test(){
  TestPushAndIndex();
}

void VectorUnitTest::TestPushAndIndex(){
  vector<float> TestVector(1);
  TestVector.Push(1.9);
  testUtils.AssetFalse(TestVector.length(), 1, "Error in pushing");
  testUtils.AssetFalse(1.9, TestVector[0], "Error in index");
}
