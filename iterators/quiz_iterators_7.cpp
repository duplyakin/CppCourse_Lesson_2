#include <iostream>
#include <cstdio>
#include "logger.h"


struct Node {  // Quiz: initialize Node instance from stdin and print into stdout
  int key;
  std::string value;

  void init(int key, const std::string& value);
};

void Node::init(int k, const std::string& v) {
  key = k;
  value = v;
}

std::istream& operator >> (std::istream& in, Node& node) {
  int key;
  std::string value;
  
  in >> key >> value;
  node.init(key, value);
  
  return in;
}


/* Array */
// ----------------------------------------------------------------------------
template <typename T>
struct Array {
  typedef T* iterator;

  size_t size;
  T* data;

  void init(T* array, size_t size);

  iterator begin();
  iterator end();
};

template <typename T>
void Array<T>::init(T* array, size_t sz) {
  size = sz;
  data = array;
}

/* Iterator member-functions */
// ----------------------------------------------
template <typename T>
typename Array<T>::iterator Array<T>::begin() {
  return data;
}

template <typename T>
typename Array<T>::iterator Array<T>::end() {
  return data + size;
}

/* Main */
// ----------------------------------------------------------------------------
int main(int argc, char** argv) {
  DBG("[Lesson 2]: Quiz Iterators 7");

  Node node_1, node_2, node_3, node_4, node_5;
  std::cin >> node_1;
  std::cin >> node_2;
  std::cin >> node_3;
  std::cin >> node_4;
  std::cin >> node_5;
  
  Node node_values[] = {node_1, node_2, node_3, node_4, node_5};
  size_t node_size = sizeof(node_values) / sizeof(Node);

  Array<Node> node_array;
  node_array.init(node_values, node_size);
  /*
  Оставил здесь так как и было. Вывод осуществляется в объект std::cout - то есть в std::out 
  */
  for (typename Array<Node>::iterator it = node_array.begin(); it != node_array.end(); ++it) {
    std::cout << "{" << it->key << ", " << it->value << "} ";
  }
  printf("\n");

  DBG("[Lesson 2]: Quiz Iterators 7 [END]");
}

