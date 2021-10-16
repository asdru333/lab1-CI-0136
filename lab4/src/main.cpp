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

void operar(std::stack<std::string> &operandos, std::string tipo, std::string signo)
{
    std::string operando1 = operandos.top();
    operandos.pop();
    std::string operando2 = operandos.top();
    operandos.pop();
    std::string resultado;
    
    //if tipo (aqui se determina el operando)
    
    switch (signo[0]) // cambiar los cases para que se ajuste a lo que se necesita
    {
        case '+':
            std::cout << operando1 << " + " << operando2 << std::endl;
            resultado = "1.1";
            operandos.push(resultado);
            break;
            
        case '-':
            std::cout << operando1 << " - " << operando2 << std::endl;
            resultado = "1.2";
            operandos.push(resultado);
            break;
            
        case '*':
            std::cout << operando1 << " * " << operando2 << std::endl;
            resultado = "1.3";
            operandos.push(resultado);
            break;
            
        case '/':
            std::cout << operando1 << " / " << operando2 << std::endl;
            resultado = "1.4";
            operandos.push(resultado);
            break;
            
        default:
            std::cout << "simbolo invalido" << std::endl;
            break;
    }
}

void split(std::string operacion, std::string tipo, std::string del = " ")
{
    std::stack<std::string> operandos;
    int start = 0;
    int end = operacion.find(del);
    std::string substr;
    while (end != -1) 
    {
        substr = operacion.substr(start, end - start);
        if (substr.size() == 1 and verificarSigno(substr))
        {
            operar(operandos, tipo, substr);
        }
        else
        {
            operandos.push(operacion.substr(start, end - start));
        }
        start = end + del.size();
        end = operacion.find(del, start);
    }
    substr = operacion.substr(start, end - start);
    operar(operandos, tipo, substr);
}

int main()
{
    std::string a = "3.5 2.8 * 9.5 -";
    std::string b = "entero";
    split(a, b);
    std::cout << "listo";
    return 0;
}
