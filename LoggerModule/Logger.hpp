

#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <stdio.h>




class Logger{
public:
  int Log(const char* Color, const char* BracketsText, const char* LogMessange);
  int InfoLog(const char* InfoMessange);
  int ErrorLog(const char* ErrorMessange);  
};

#endif
