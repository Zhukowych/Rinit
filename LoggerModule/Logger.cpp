#include "Logger.hpp"

int Logger::Log(const char* Color, const char* BracketsText , const char* LogMessange){
  int BytesWroted = printf("%s[%s]%s %s\n", Color, BracketsText, RESET, LogMessange);
  return BytesWroted;
}

int Logger::InfoLog(const char* InfoMessange){
  return Log(GREEN, "INFO", InfoMessange);
}

int Logger::ErrorLog(const char* ErrorMessange){
  return Log(RED, "ERROR", ErrorMessange);
}
