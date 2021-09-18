#include "Tipo.hpp"

Tipo::Tipo(std::string nombre, Tipo* padre = nullptr, Tipo* hijo = nullptr) {
  this->nombre = nombre;
  this->padre = padre;
  this->hijo = hijo;
}

Tipo::~Tipo() {
  this->padre = nullptr;
  this->hijo = nullptr;
}

std::string Tipo::getNombre() { return this->nombre; }
void Tipo::setNombre(std::string nuevoNombre) { this->nombre = nuevoNombre; }

Tipo* Tipo::getPadre() { return this->padre; }
void Tipo::setPadre(Tipo* nuevoPadre) { this->padre = nuevoPadre; }

Tipo* Tipo::getHijo() { return this->hijo; }
void Tipo::setHijo(Tipo* nuevoHijo) { this->hijo = nuevoHijo; }