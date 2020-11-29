

#ifndef LOGGER_UNIT_TEST_HPP_
#define LOGGER_UNIT_TEST_HPP_
#include "Logger.hpp"
#include "../TestsUtils/TestsUtils.hpp"
class LoggerUnitTest{
public:
  void Test();
private:
  Logger logger;
  TestsUtils testsUtils;
  const int INFO_TOTAL_BYTES = 28;
  const int ERROR_TOTAL_BYTES = 29;
};



#endif


