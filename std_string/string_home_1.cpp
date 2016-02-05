/*
1. Modify string_3.cpp and trim leading whitespaces as well.

*/


#include <iostream>
#include <string>
#include "include/logger.h"

int main(int argc, char** argv) {
  DBG("[Lesson 2]: STD string 3");

  // Trim whitespaces
  std::string str = "   Some leading and trailing whitespaces   Yeah   ";
  std::string whitespaces(" \t\f\v\n\r"); 
  size_t found = str.find_last_not_of(whitespaces);
  if (found != std::string::npos) { 
    str.erase(found + 1);
  } else {
    str.clear();  
  }

  found = str.find_first_not_of(whitespaces);
  if (found != std::string::npos) { 
    str.erase(0, found);
  } else {
    str.clear();
  }
  std::cout << '[' << str << "]\n";

  DBG("[Lesson 2]: STD string 3 [END]");
  return 0;
}
