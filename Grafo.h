#ifndef GRAFO
#define GRAFO

#include "NodoG.h"
#include <list>
#include <string>
#include <vector>

class Grafo{
private:
    std::list<NodoG> nodos;
    std::list<std::list<std::string>> listaADY;

public:
    Grafo();
    std::list<NodoG> getNodos();
    void insertarNodo(std::string palabra);
    void eliminarNodo(std::string palabra);
    void agregarConeccion(std::string palabra1, std::string palabra2);
    void eliminarConeccion(std::string palabra1, std::string palabra2);
    void imprimirGrafo();
    std::vector<std::string> generarPalabrasComodin(const std::string& letras);

/* funciones axiliares */
    int obtenerPosLista(std::string palabra);
    void busquedaProfundidad(int inicio);
    void busquedaAnchura(int inicio);
};

#endif // GRAFO