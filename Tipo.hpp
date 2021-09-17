#pragma once
#include <string>

class Tipo
{
	private:
		std::string nombre;
		Tipo* padre;
		Tipo* hijo;
			
	public: 
		Tipo(std::string nombre, Tipo* padre = nullptr, Tipo* hijo = nullptr)
		{
			this->nombre = nombre;
			this->padre = padre;
			this->hijo = hijo;
		}
	
		std::string getNombre()
		{
			return this->nombre;
		}
		void setNombre(std::string nuevoNombre)
		{
			this->nombre = nuevoNombre;
		}
		
		Tipo* getPadre()
		{
			return this->padre;
		}
		void setPadre(Tipo* nuevoPadre)
		{
			this->padre = nuevoPadre;
		}
	
		Tipo* getHijo()
		{
			return this->hijo;
		}
		void setHijo(Tipo* nuevoHijo)
		{
			this->hijo = nuevoHijo;
		}
};
