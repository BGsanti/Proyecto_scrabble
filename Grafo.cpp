#include "Grafo.h"
#include "NodoG.h"
#include <iostream>
#include <list>
#include <string>

Grafo::Grafo(){};

std::list<NodoG> Grafo::getNodos(){
  return Grafo::nodos;
}

void Grafo::insertarNodo(std::string palabra){
  NodoG vertice;
  vertice.setPalabra(palabra);
  Grafo::nodos.push_back(vertice);
  std::list<std::string> verticeAdyacentes;
  Grafo::listaADY.push_back(verticeAdyacentes);
}

void Grafo::eliminarNodo(std::string palabra){
  int posLista = -1;
  for(auto it = Grafo::nodos.begin(); it != Grafo::nodos.end(); it++){
    posLista += 1;
    if(it->getPalabra() == palabra){
      Grafo::nodos.erase(it);
      break;
    }
  }

  int posActual = 0;
  for(auto it = Grafo::listaADY.begin(); it != Grafo::listaADY.end(); it++){
    if(posActual != posLista){
      Grafo::listaADY.erase(it);
      break;
    }
    posActual += 1;
  }
  
  /* eliminar todas las conexiones de la lista de adyacensia que tenian este nodo que no existe: */
  for(auto it = Grafo::listaADY.begin(); it != Grafo::listaADY.end(); it++){
    for(auto it2 = it->begin(); it2 != it->end(); it2++){
      if(*it2 == palabra){
        it->erase(it2);
      }
    }
  }
  
}

int Grafo::obtenerPosLista(std::string palabra){
  int posLista = -1;
  for(auto it = Grafo::nodos.begin(); it != Grafo::nodos.end(); it++){
    posLista += 1;
    if(it->getPalabra() == palabra){
      break;
    }
  }
  return posLista;
}

void Grafo::agregarConeccion(std::string palabra1, std::string palabra2){
  int posLista1 = Grafo::obtenerPosLista(palabra1);
  int posicionActual1 = 0;

  for(auto it = Grafo::listaADY.begin(); it != Grafo::listaADY.end(); it++){
    if(posicionActual1 == posLista1){
      it->push_back(palabra2);
    }
    posicionActual1 += 1;
  }  
}

void Grafo::eliminarConeccion(std::string palabra1, std::string palabra2){
  int posLista1 = Grafo::obtenerPosLista(palabra1);
  int posLista2 = Grafo::obtenerPosLista(palabra2);

  int posicionActual1 = 0;
  int posicionActual2 = 0;

  for(auto it = Grafo::listaADY.begin(); it != Grafo::listaADY.end(); it++){
    if(posicionActual1 == posLista1){
      for(auto it2 = it->begin(); it2 != it->end(); it2++){
        if(*it2 == palabra2){
          it->erase(it2);
        }
      }
    }
    posicionActual1 += 1;
  }

  for(auto it = Grafo::listaADY.begin(); it != Grafo::listaADY.end(); it++){
    if(posicionActual2 == posLista2){
      for(auto it2 = it->begin(); it2 != it->end(); it2++){
        if(*it2 == palabra1){
          it->erase(it2);
        }
      }
    }
    posicionActual2 += 1;
  }
}

void Grafo::imprimirGrafo() {
    std::cout << "Contenido del grafo de palabras:" << std::endl;

    int i = 0;
    auto it = nodos.begin();
    auto it_ady = listaADY.begin();
    for (; it != nodos.end() && it_ady != listaADY.end(); ++it, ++it_ady, ++i) {
        std::cout << i << ": " << it->getPalabra() << " -> ";
        for (const std::string& adyacente : *it_ady) {
            std::cout << adyacente << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> Grafo::generarPalabrasComodin(const std::string& cadena) {
    std::vector<std::string> palabrasValidas;
    std::list<NodoG>::iterator it;

    for (it = nodos.begin(); it != nodos.end(); ++it) {
        std::string palabra = it->getPalabra();
        bool esValida = true;

        if (palabra.length() == cadena.length()) {
            for (size_t i = 0; i < palabra.length(); ++i) {
                if (cadena[i] != '?' && tolower(palabra[i]) != tolower(cadena[i])) {
                    esValida = false;
                    break;
                }
            }
            if (esValida) {
                palabrasValidas.push_back(palabra);
            }
        }
    }

    return palabrasValidas;
}