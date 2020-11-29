
#ifndef VECTOR_UNIT_TEST_HPP_
#define VECTOR_UNIT_TEST_HPP_
#include "../../TestsUtils/TestsUtils.hpp"
#include "Vector.hpp"

class VectorUnitTest{
public:
  void Test();
private:
  TestsUtils testUtils;
  void TestPushAndIndex();
};


#endif
