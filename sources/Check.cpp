//Copyright 2021 by Winter Solider

#include "Check.h"
#include <chrono>
#include <random>
#include <sstream>

char* Check::initArray()
{
  std::random_device rd;
  std::mt19937_64 mt(rd());
  std::uniform_int_distribution<int64_t> dist(0, Check::size);
  char* arr = new char[Check::size];
  for (int64_t i=0; i < size; i+=16)
    arr[i] = dist(mt);
  return arr;
}

Check::Check(int i, Check_type t, int64_t s)
{
  Check::id = i;
  Check::type = t;
  Check::size = s;
}


double Check::run() {
  using std::chrono::duration;
  using std::chrono::milliseconds;
  char k = 0;
  char* arr = initArray();
  for (int64_t i = 0; i < Check::size; i += 16)
    k = arr[i];
  auto t1 = std::chrono::high_resolution_clock::now();
  switch (Check::type)
  {
      case ::_random:
        for (int j = 0; j < 1000; j++) _random(arr, k);
        break;
      case ::_forward:
        for (int j = 0; j < 1000; j++) _forward(arr, k);
        break;
      case ::_reverse:
        for (int j = 0; j < 1000; j++) _reverse(arr, k);
        break;
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  duration<double, std::milli> ms = t2 - t1;
  time = ms.count();
  delete[] arr;
  return time;
}
void Check::_forward(char* arr, char& k) {
  for (int64_t i = 0; i < Check::size; i += 16)
    k = arr[i];
}
void Check::_reverse(char* arr, char& k) {
  for (int64_t i = Check::size-1; i > 0; i -= 16)
    k = arr[i];
}

void Check::_random(char* arr, char& k)
{
  std::random_device rd;
  std::mt19937_64 mt(rd());
  std::uniform_int_distribution<int64_t> dist(0, Check::size/16);
  for (int64_t i=0; i < Check::size/16; i++)
    k = arr[dist(mt)];
}

void Check::print(std::ostream& os) {
  os << "\t- experiment:\n"
  << "\t\tnumber: " << id << std::endl
  << "\t\tinput_data:\n"
     <<"\t\t\tbuffer_size: "
  << Byte_value(size) << std::endl
  << "\t\tresults:\n"
     <<"\t\t\tduration: "
  << time << " ms\n";
}
