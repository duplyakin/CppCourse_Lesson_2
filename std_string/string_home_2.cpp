/*
2. Compare performance between std::string and std::vector<char>.
Provide lots of push-operations and measures time elapsed.
*/

#include <iostream>
#include <string>
#include "include/logger.h"
#include <vector>
#include <ctime>

struct Score {
  long int vector_wins;
  long int string_wins;
};
/*
В чем отличие между первым тестом?

В первом тесте performanceTest1:
размер size - случайное число. 
Результат: 
INF in [string_home_2.cpp:79] >>> "Score: Filling string is faster in [26] cases, Vector is faster in [107] cases"
при 
int size = rand() % 1000000 + 1000;


Во втором тесте performanceTest2:
size линейно увеличивается размер - думал найти какую-то зависимость..
Результат: 
INF in [string_home_2.cpp:143] >>> "Score: Filling string is faster in [999] cases, Vector is faster in [1] cases"
при 
for (int size = 100; size < 1000000; size+=1000)

Первый тест - более правильный. Второй тест выдаёт странный результат.
*/
void performanceTest1() {

  clock_t start = clock();//текущее время
  clock_t elapsed = start;//время, которое займёт сначала одна итерация, потом две итерации и тд. Когда это время будет больше на 5 сек, чем стартовое, то мы прервёмся. 
  double min_ratio = 99999.9, max_ratio = 0;
  int size_at_min_ratio = 0, size_at_max_ratio = 0;
  struct Score score;
  score.vector_wins = 0;
  score.string_wins = 0;

  while ((elapsed - start) < 5 * CLOCKS_PER_SEC) {
    int size = rand() % 1000000 + 1000;

    std::vector<int> initial_array;
    for (int i = 0; i < size; ++i) {
      int value = rand() % 1000;
      initial_array.push_back(value);
    }

    std::vector<int> array;
    array.reserve(size);

    std::string str;
    str.reserve(size);

    clock_t vector_fill_start = clock();
    for (int i = 0; i < size; ++i) {
      array.push_back(initial_array[i]);
    }
    clock_t vector_fill_elapsed = clock();


    clock_t string_fill_start = clock();
    for (int i = 0; i < size; ++i) {
      array.push_back(initial_array[i]);
    }
    clock_t string_fill_elapsed = clock();


    double vector_time = static_cast<double>(vector_fill_elapsed - vector_fill_start) / CLOCKS_PER_SEC;//заполнеие вектора
    double string_time = static_cast<double>(string_fill_elapsed - string_fill_start) / CLOCKS_PER_SEC;//заполнеие строки 
    if (string_time < vector_time) 
      ++score.string_wins;
    else 
      ++score.vector_wins;

    double ratio = string_time / vector_time; 
    INF("FILL size [%i]: vector [%.8lf], string [%.8lf], ratio [%.8lf]", size, vector_time, string_time, ratio);

    if (ratio > max_ratio) {
      max_ratio = ratio;
      size_at_max_ratio = size;
    }
    if (ratio < min_ratio) {
      min_ratio = ratio;
      size_at_min_ratio = size;
    }

    elapsed = clock();
  }
  WRN("Max ratio string / vector [%.8lf] at size [%i]", max_ratio, size_at_max_ratio);
  DBG("Min ratio string / vector [%.8lf] at size [%i]", min_ratio, size_at_min_ratio);
  INF("Score: Filling string is faster in [%ld] cases, Vector is faster in [%ld] cases", score.string_wins, score.vector_wins);

}



void performanceTest2() {
  double min_ratio = 99999.9, max_ratio = 0;
  int size_at_min_ratio = 0, size_at_max_ratio = 0;
  struct Score score;
  score.vector_wins = 0;
  score.string_wins = 0;


    for (int size = 100; size < 1000000; size+=1000) { 

    std::vector<int> initial_array;
    for (int i = 0; i < size; ++i) {
      int value = rand() % 1000;
      initial_array.push_back(value);
    }


    std::vector<int> array;
    array.reserve(size);

    std::string str;
    str.reserve(size);

    clock_t vector_fill_start = clock();
    for (int i = 0; i < size; ++i) {
      array.push_back(initial_array[i]);
    }
    clock_t vector_fill_elapsed = clock();


    clock_t string_fill_start = clock();
    for (int i = 0; i < size; ++i) {
      str.push_back(initial_array[i]);
    }
    clock_t string_fill_elapsed = clock();


    double vector_time = static_cast<double>(vector_fill_elapsed - vector_fill_start) / CLOCKS_PER_SEC;//заполнеие вектора
    double string_time = static_cast<double>(string_fill_elapsed - string_fill_start) / CLOCKS_PER_SEC;//заполнеие строки 
    if (string_time < vector_time) 
      ++score.string_wins;
    else 
      ++score.vector_wins;
    double ratio = string_time / vector_time; 
    INF("FILL size [%i]: vector [%.8lf], string [%.8lf], ratio [%.8lf]", size, vector_time, string_time, ratio);

    if (ratio > max_ratio) {
      max_ratio = ratio;
      size_at_max_ratio = size;
    }
    if (ratio < min_ratio) {
      min_ratio = ratio;
      size_at_min_ratio = size;
    }

  }
  WRN("Max ratio string / vector [%.8lf] at size [%i]", max_ratio, size_at_max_ratio);
  DBG("Min ratio string / vector [%.8lf] at size [%i]", min_ratio, size_at_min_ratio);
  INF("Score: Filling string is faster in [%ld] cases, Vector is faster in [%ld] cases", score.string_wins, score.vector_wins);

}

int main(int argc, char** argv) {
  DBG("[Lesson 2]: STD string home 2");
  performanceTest1();
  printf("Введите любой символ:");
  getchar();
  performanceTest2();
  DBG("[Lesson 2]: STD string home 2 [END]");
  return 0;
}
