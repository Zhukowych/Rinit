#include "LoggerUnitTest.hpp"



void LoggerUnitTest::Test(){
  const char* LogText = "Simple Text";
  testsUtils.AssetFalse(logger.ErrorLog(LogText), ERROR_TOTAL_BYTES, "Error log Error");
  testsUtils.AssetFalse(logger.InfoLog(LogText), INFO_TOTAL_BYTES, "Info Log Error");
}
