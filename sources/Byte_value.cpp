//Copyright 2021 by Winter Solider


#include <string>
#include <cmath>

std::string Byte_value(int64_t value)
{
  if (value <= 1024)
    return std::to_string(value) + "b";
  if (value >= 1024 && value < pow(1024, 2))
    return std::to_string(value/1024.0) + "kb";
  if (value >= pow(1024, 2) && value < pow(1024, 3))
    return std::to_string(value/pow(1024, 2)) + "mb";
  if (value >= pow(1024, 3))
    return std::to_string(value/pow(1024, 3)) + "gb";
  return 0;
}
