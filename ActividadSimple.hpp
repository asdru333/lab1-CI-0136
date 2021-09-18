#pragma once
#include <string>
#include "Actividad.hpp"
#include "Tipo.hpp"

class ActividadSimple : public Actividad
{	
	public: 
		ActividadSimple(std::string responsable, std::string fechaPlanteadaInicio, std::string fechaPlanteadaFinal, 
              	std::string fechaRealInicio, std::string fechaRealFinalizacion, std::string descripcion)
		{ 
		    
		    if ((!padre and !tipo->getPadre()) or (tipo->getPadre()->getNombre() == padre->getTipo()->getNombre()))
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
		        std::cout << "problemas con la jerarquía" << std::endl;
		    }
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
