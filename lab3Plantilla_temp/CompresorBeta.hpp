#pragma once
#include <ostream>

template <typename T>
class CompresorBeta : public T {
 public:
  friend CompresorBeta<T>& operator<<(CompresorBeta<T>& os, std::string& str) {
    for (int x = 0; x < str.size(); ++x) os << str[x] << '.';
    return os;
  }
};
