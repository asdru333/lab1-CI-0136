#pragma once
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

class ActividadCompuesta : public Actividad
{
	protected:
    		std::vector<Actividad*> hijos;
		
	public:
		ActividadCompuesta(std::string responsable, std::string fechaPlanteadaInicio, std::string fechaPlanteadaFinal, std::string fechaRealInicio, 
						  std::string fechaRealFinalizacion, std::string descripcion, Actividad* padre)
		{ 
			this->responsable = responsable;
			this->fechaPlanteadaInicio = fechaPlanteadaInicio;
			this->fechaPlanteadaFinal = fechaPlanteadaFinal;
			this->fechaRealInicio = fechaRealInicio;
			this->fechaRealFinalizacion = fechaRealFinalizacion;
			this->descripcion = descripcion;
			this->padre = padre;
		}

		~ActividadCompuesta()
		{
			this->padre = nullptr;
			this->hijos.empty();
		}

		virtual void calcularFechas()
		{
			if (this->hijos.size() > 0)
			{
				std::string fechaCandidataInicio = this->hijos[0]; 
				std::string fechaCandidataFinal = this->hijos[0]; 
				for (int index = 1; index < hijos.size(); ++index)
				{
					fechaCandidataInicio = this->calcularFecha(fechaCandidataInicio, this->hijos[index], -1);
					fechaCandidataFinal = this->calcularFecha(fechaCandidataFinal, this->hijos[index], 1);
				}
				this->fechaPlanteadaInicio = fechaCandidataInicio;
				this->fechaPlanteadaFinal = fechaCandidataFinal
			}
		}

		virtual void add(Actividad* nuevoHijo)
		{
			this->hijos.push_back(nuevoHijo);
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
					if ((stoi(fecha1) - stoi(fecha2))*signo > 0)
					{
						return fechaCandidata;
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
