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
		std::vector<std::vector<Actividad*>> vectorActividades;
		
	public:
		Interfaz(int cantidad, std::vector<Tipo*> vectorTipos)
		{
			this->vectorTipos = vectorTipos;
			this->vectorActividades.resize(cantidad);
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
				std::cout << "2. Ver jerarquia de tipos" << std::endl;
				std::cout << "3. Ver instancias" << std::endl;
				std::cout << "4. salir" << std::endl;
				std::cin >> opcion;
				if (opcion == 1)
					crearInstancias();
				else if (opcion == 2)
					verJerarquia();	
				else if (opcion == 3)
					verInstancias();
				else if (opcion == 4)
					terminar = 1;
				else
					std::cout << "Opcion incorrecta. Por favor escriba un numero valido" << std::endl;	
			}
		}
		
		void crearInstancias()
		{
			Actividad* proyecto;
			int tamano = this->vectorTipos.size();
			if (tamano == 0)
				std::cout << "Error con la jerarquía de tipos (no existe)" << std::endl;	
			else if (tamano == 1)
			{
				proyecto = CrearActividadSimple(0);
				this->vectorActividades[0].push_back(proyecto);
			}
			else
			{
				proyecto = CrearActividadCompuesta(0);
				this->vectorActividades[0].push_back(proyecto);
				int numHijos = 0;
				Actividad* hijo;
				for (int contador = 0; contador < tamano-1; ++contador)
				{
					for (int index = 0; index < this->vectorActividades[contador].size(); ++index)
					{
						std::cout << "Ingrese la cantidad de hijos que quiere para " << this->vectorTipos[contador]->getNombre() << index+1 << std::endl;
						std::cin >> numHijos;
						for (int contador2 = 0; contador2 < numHijos; ++contador2)
						{
							this->crearHijos(this->vectorActividades[contador][index], contador+1);
						}
					}		
				}
			}
		}
		
		void verJerarquia()
		{
			for (int index = 0; index < this->vectorTipos.size(); ++index)
			{
				std::cout << this->vectorTipos[index]->getNombre();
				if (index + 1 != this->vectorTipos.size())
					std::cout << " > ";
				else
					std::cout << '\n';
			}
		}
		
		void verInstancias()
		{
			ActividadCompuesta* actividad = nullptr;
			if (this->vectorActividades.empty())
				std::cout << "No existen las instancias" << std::endl;
			else
			{
				for (int row = 0; row < vectorActividades.size(); ++row)
				{
					for (int col = 0; col < vectorActividades[row].size(); ++col)
					{
						std::cout << "Se tiene " << vectorActividades[row][col]->getTipo()->getNombre() << col << std::endl;
					}
				}
			}
		}
		
	private:
		
		Actividad* CrearActividadCompuesta(int index)
		{
			return new ActividadCompuesta("Carlos", vectorTipos[index], "21/07/2021", "26/07/2021", "21/07/2021", "26/07/2021", "");
		}	
		
		Actividad* CrearActividadSimple(int index)
		{
			return new ActividadSimple("Carlos", vectorTipos[index], "21/07/2021", "26/07/2021", "21/07/2021", "26/07/2021", "");
		}
		
		void crearHijos(Actividad* padre, int index)
		{
			Actividad* hijo;
			if (index+1 < this->vectorTipos.size())
				hijo = CrearActividadCompuesta(index);
			else
				hijo = CrearActividadSimple(index);	
			padre->add(hijo);
			this->vectorActividades[index].push_back(hijo);
		}
};
