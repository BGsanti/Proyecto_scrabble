#include "NodoG.h"
#include <string>

NodoG::NodoG(){};

void NodoG::setPalabra(std::string palabra){
  NodoG::palabra = palabra;
}

std::string NodoG::getPalabra() const { // Aquí se agrega const
  return NodoG::palabra;
}