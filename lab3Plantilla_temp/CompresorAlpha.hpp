#pragma once
#include <ostream>

template <typename T>
class CompresorAlpha : public T {
 public:
  friend CompresorAlpha<T>& operator<<(CompresorAlpha<T>& os,
                                       std::string& str) {
    for (int x = 0; x < str.size(); ++x) os << str[x] << " ";
    return os;
  }
};
