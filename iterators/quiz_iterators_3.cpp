#include <cstdio>
#include "logger.h"
#include <cstring>


/* Array */
// ----------------------------------------------------------------------------
struct Array {
  size_t size; 
  int* data;

  void init(int array[], size_t size);
  void print();
};

void Array::init(int* array, size_t sz) {  // Quiz: implement deep copy
  INF("Copy Constructor");
  size = sz;
  data = new int[size];
  memcpy(data, array, sizeof(int)*sz);//почему-то не работает если вместо sizeof(int)*sz поставить sizeof(array)
}

void Array::print() {
  for (size_t i = 0; i < size; ++i) {
    printf("%i ", data[i]);
  }
  printf("\n");
}

/* Main */
// ----------------------------------------------------------------------------
int main(int argc, char** argv) {
  DBG("[Lesson 2]: Quiz Iterators 3");

  int values[] = {5, 8, -9, 17, 4, 2, -3, 0, 11, 6};
  size_t size = sizeof(values) / sizeof(values[0]);

  Array array;
  array.init(values, size);
  array.print();

  DBG("[Lesson 2]: Quiz Iterators 3 [END]");
}

