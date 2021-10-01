#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>

#include "Compresor1.hpp"
#include "Compresor2.hpp"

int main()
{
	std::string hola("hola");
	Compresor1<std::stringstream> compresorSs;
    	compresorSs << hola;
	std::cout << compresorSs.str();
    
    	std::cout << std::endl;
    
	Compresor1<std::ostringstream> compresorOs;
	compresorOs << hola;
	std::cout << compresorOs.str();
    
	std::cout << std::endl;
    
	Compresor1<std::fstream> compresorFs;
	compresorFs.open ("text1fs.txt", std::fstream::out);
	compresorFs << hola;
	compresorFs.close();
    
	Compresor1<std::ofstream> compresorOfs;
  	compresorOfs.open ("text1ofs.txt", std::fstream::out);
	compresorOfs << hola;
	compresorOfs.close();
    
	Compresor2<std::stringstream> compresorSs2;
	compresorSs2 << hola;
	std::cout << compresorSs2.str();
    
	return 0;
}

