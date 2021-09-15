#pragma once
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

class ActividadCompuestas : public Actividad
{
	protected:
    	vector<Actividad*> hijos;
		
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
		/*
			if (this->hijos.size() > 0)
			{
				this->fechaPlanteadaInicio = this->obtenerFechaMinima();
				this->fechaPlanteadaFinal = this->obtenerFechaMaxima();
			}
		*/
		}

		virtual void add(Actividad* nuevoHijo)
		{
			this->hijos.push_back(nuevoHijo);
		}

		virtual void remove(Actividad* noHijo)
		{
			std::vector<int>::iterator iterator = this->hijos.begin();
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
	/*
		obtenerFechaMinima()
		{
			string fechaMinima;
			for (int iterator = 0; iterator < this->hijos; ++iterator)
			{
				obtenerNum
				fechaMinima = 
			}
		}
		
		obtenerFechaMaxima()
		{
			this->
		}
	*/
		
};
