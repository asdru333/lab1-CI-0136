#pragma once
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include "Tipo.hpp"
#include "Actividad.hpp"
#include "ActividadSimple.hpp"
#include "ActividadCompuesta.hpp"

class Interfaz
{
	private:
		std::vector<Tipo*> vectorTipos;
		std::vector<Actividad*> vectorActividades;
		
	public:
		Interfaz(std::vector<Tipo*> vectorTipos)
		{
			this->vectorTipos = vectorTipos;
		}
		
		void menuPrincipal()
		{
			bool terminar = 0;
			int opcion = 0;
			while (!terminar)
			{
				std::cout << "Por favor seleccione algunas de las siguientes opciones:" << std::endl;
				std::cout << "1. Crear instancias de tipos" << std::endl;
				//std::cout << "2. Ver actividad padre" << std::endl;
				std::cout << "3. Ver jerarquia de tipos" << std::endl;
				std::cout << "4. salir" << std::endl;
				std::cin >> opcion;
				if (opcion == 1)
					menuInstancias();
				//else if (opcion == 2)
					//interactuarInstancias();
				else if (opcion == 3)
					verJerarquia();	
				else if (opcion == 4)
					terminar = 1;
				else
					std::cout << "Opcion incorrecta. Por favor escriba un numero valido" << std::endl;	
			}
		}
		
		/**
		std::cout << "Actividad raiz de tipo " << raiz->getTipo()->getNombre() << " ha sido creada" << std::endl;
		int numHijos = 0;
		std::cout << "Ingrese la cantidad de hijos" << std::endl;
		std::cin >> numhijos
		*/
		
		
		
		void verJerarquia()
		{
			for (int index = 0; index < this->vectorTipos.size(); ++index)
			{
				std::cout << this->vectorTipos[index]->getNombre();
				if (index + 1 != this->vectorTipos.size())
					std::cout << "> ";
				else
					std::cout << '\n';
			}
		}
		
	private:
		
		CrearActividadCompuesta(int index)
		{
			return new ActividadCompuesta("Carlos", vectorTipos[index], "21/07/2021", "26/07/2021", "21/07/2021", "26/07/2021", "")
		}	
		
		CrearActividadSimple(int index)
		{
			return new ActividadSimple("Carlos", vectorTipos[index], "21/07/2021", "26/07/2021", "21/07/2021", "26/07/2021", "")
		}
		
		Actividad* crearHijos(Actividad* padre, int index)
		{
			Actividad* hijo;
			if (index+1 < this->vectorTipos.size())
				hijo = CrearActividadCompuesta(index);
			else
				hijo = CrearActividadSimple(index);	
			return hijo;
		}
};
