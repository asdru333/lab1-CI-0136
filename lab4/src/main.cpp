#include <iostream>
#include <string>
#include <stack>

bool verificarSigno(std::string str)
{
    if (str.compare("+") == 0 or str.compare("-") == 0 or str.compare("*") == 0 or str.compare("/") == 0)
    {
        return 1;
    }
    return 0;
}

void split(std::string s, std::string del = " ")
{
    std::stack<std::string> operandos;
    int start = 0;
    int end = s.find(del);
    std::string substr;
    while (end != -1) 
    {
        substr = s.substr(start, end - start);
        if (substr.size() == 1 and verificarSigno(substr))
        {
            std::cout << substr << std::endl;
            //operar()
        }
        else
        {
            operandos.push(s.substr(start, end - start));
        }
        start = end + del.size();
        end = s.find(del, start);
    }
    std::cout << s.substr(start, end - start) << std::endl;
    //operar()
}

int main()
{
    std::string a = "3.5 2.8 * 9.5 -";
    split(a);
    return 0;
}
