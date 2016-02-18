#include <string>
#include <vector>
#include <cstdio>
#include "logger.h"

int main(int argc, char** argv) {  // Quiz: write all methods you know to output an array into stdout
  DBG("[Lesson 2]: Quiz Iterators 0");

  std::vector<std::string> array = {"This", "is", "lesson", "two", "part", "of", "iterators", "concept"};
  // standard io
  for (typename std::vector<std::string>::iterator it = array.begin(); it != array.end(); ++it) {
    printf("%s ", it->c_str());
  }
  printf("\n");
  
  // streams
  for (typename std::vector<std::string>::iterator it = array.begin(); it != array.end(); ++it) {
    std::cout << it->c_str() << " ";
  }
  std::cout << std::endl;

  // standard io + for_each
  for (std::string item : array) {
    printf("%s ", item.c_str());
  }
  printf("\n");

  // streams + for_each
  for (std::string item : array) {
    std::cout << item.c_str() << " ";
  }
  std::cout << std::endl;

  DBG("[Lesson 2]: Quiz Iterators 0 [END]");
}
