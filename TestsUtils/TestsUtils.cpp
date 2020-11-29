#include "TestsUtils.hpp"

void TestsUtils::AssetFalse(int FirstCondition, int SecondCondition, const char* FalseStr){
  if(FirstCondition!=SecondCondition){
	printf("%s\n", FalseStr);
  }
}
