#pragma once
#include <ostream>

template <typename T>
class Compresor2: public T 
{
    public:
        friend Compresor2<T>& operator<<(Compresor2<T>& os, std::string& str)
        {
            for (int x = 0; x < str.size(); ++x)
                os << str[x] << '.';
            return os;
        }
};
