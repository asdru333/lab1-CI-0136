#pragma once
#include <string>
#include "Actividad.hpp"

class ActividadSimple : public Actividad
{	
	public: 
		ActividadSimple(std::string responsable, std::string fechaPlanteadaInicio, std::string fechaPlanteadaFinal, 
              	std::string fechaRealInicio, std::string fechaRealFinalizacion, std::string descripcion, Actividad* padre)
		{ 
			this->responsable = responsable;
			this->fechaPlanteadaInicio = fechaPlanteadaInicio;
			this->fechaPlanteadaFinal = fechaPlanteadaFinal;
			this->fechaRealInicio = fechaRealInicio;
			this->fechaRealFinalizacion = fechaRealFinalizacion;
			this->descripcion = descripcion;
			this->padre = padre;
		}
		
		~ActividadSimple()
		{
			this->padre = nullptr;
		}
		
		virtual void calcularFechas() override
		{
		    ;
		}
		virtual void add(Actividad*) override
		{
		    ;
		}
		virtual void remove(Actividad*) override
		{
		    ;
		}
};
