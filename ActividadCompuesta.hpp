#pragma once
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include "Actividad.hpp"
#include "Tipo.hpp"

class ActividadCompuesta : public Actividad
{
	protected:
    		std::vector<Actividad*> hijos;
		
	public:
		ActividadCompuesta(std::string responsable, Tipo* tipo, std::string fechaPlanteadaInicio, std::string fechaPlanteadaFinal, 
		std::string fechaRealInicio, std::string fechaRealFinalizacion, std::string descripcion)
		{ 
		    if (tipo->getHijo())
		    {
    			this->responsable = responsable;
    			this->tipo = tipo;
    			this->fechaPlanteadaInicio = fechaPlanteadaInicio;
    			this->fechaPlanteadaFinal = fechaPlanteadaFinal;
    			this->fechaRealInicio = fechaRealInicio;
    			this->fechaRealFinalizacion = fechaRealFinalizacion;
    			this->descripcion = descripcion;
    			this->padre = nullptr;
		    }
		    else
		    {
		        std::cout << "Una actividad compuesta no puede contener el tipo más bajo de la jerarquía (que no tenga hijo)" << std::endl;
		    }
		}

		~ActividadCompuesta()
		{
			this->padre = nullptr;
			this->hijos.empty();
		}
		
		std::vector<Actividad*> getHijos()
		{
		    return this->hijos;
		}
		
		virtual void calcularFechas()
		{
			if (this->hijos.size() > 0)
			{
				std::string fechaCandidataInicio = this->hijos[0]->getFechaPlanteadaInicio(); 
				std::string fechaCandidataFinal = this->hijos[0]->getFechaPlanteadaFinal(); 
				for (int index = 1; index < hijos.size(); ++index)
				{
					fechaCandidataInicio = this->calcularFecha(fechaCandidataInicio, this->hijos[index]->getFechaPlanteadaInicio(), 1);
					fechaCandidataFinal = this->calcularFecha(fechaCandidataFinal, this->hijos[index]->getFechaPlanteadaFinal(), -1);
				}
				this->fechaPlanteadaInicio = fechaCandidataInicio;
				this->fechaPlanteadaFinal = fechaCandidataFinal;
			}
		}

		virtual void add(Actividad* nuevoHijo)
		{
			if (!nuevoHijo)
				std::cout << "No se permiten agregar hijos nulos" << std::endl;
			else 
			{
				Tipo* elPadre = nuevoHijo->getTipo()->getPadre();
				Tipo* elHijo = this->tipo->getHijo();
				if (elHijo and elPadre and elPadre->getNombre() == this->tipo->getNombre() 
				and nuevoHijo->getTipo()->getNombre() == elHijo->getNombre())
				{
					nuevoHijo->setPadre(this);
					this->hijos.push_back(nuevoHijo);
    				}
			   	 else
					std::cout << "No se puede agregar el hijo por problemas de jerarquía" << std::endl;
			}
		}

		virtual void remove(Actividad* noHijo)
		{
			std::vector<Actividad*>::iterator iterator = this->hijos.begin();
			while (*iterator != noHijo and iterator != this->hijos.end())
			{
				++iterator;
			}
			if (iterator != this->hijos.end())
			{
			    noHijo->setPadre(nullptr);
				this->hijos.erase(iterator);
			}
		}
		
	private:
		std::string calcularFecha(std::string fechaActual, std::string fechaCandidata, int signo)
		{
			std::string fecha1, fecha2;
			int index = fechaActual.size()-1;
			while(index >= 0)
			{
				if (fechaActual[index] != '/')
				{
					fecha1.insert(0, fechaActual.substr(index, 1));
					fecha2.insert(0, fechaCandidata.substr(index, 1));
				}
				else
				{
				    int resultado = (stoi(fecha1) - stoi(fecha2))*signo;
					if (resultado != 0)
					{
					    if (resultado > 0)
						    return fechaCandidata;
						else
						   return fechaActual;
					}
					else
					{
						fecha1.clear();
						fecha2.clear();
					}
				}
				--index;
			}
			return fechaActual;
		}	
};
