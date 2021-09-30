#pragma once
#include <ostream>

template <typename T>
class Compresor1: public T 
{
    public:
        friend Compresor1<T>& operator<<(Compresor1<T>& os, std::string& str)
        {
            for (int x = 0; x < str.size(); ++x)
                os << str[x] << " ";
            return os;
        }
};
