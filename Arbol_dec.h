#ifndef ENTREGA1_ARBOL_DEC_H
#define ENTREGA1_ARBOL_DEC_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Nodo { // Clase Nodo
public:
    char letra;
    bool finPalabra;
    vector<Nodo*> hijos;

    // Constructor
    Nodo(char letra);
};

class ArbolGeneral {
public:
    Nodo* raiz;

    // Constructor
    ArbolGeneral();

    // Función para insertar una palabra en el árbol
    void insertar(const string& palabra);

    // Destructor
    ~ArbolGeneral();

    //Función para insertar palabras en el árbol
    void insertarPalabras(const vector<string>& palabras);

    // Función para buscar una palabra en el árbol
    bool buscar(const std::string& palabra);

    // Función auxiliar para eliminar todos los nodos del árbol
    void limpiar(Nodo* nodo);

    // Funciones para archivos
    vector<string> procesarArchivo_Arbol(const string& ruta_Diccionario);
    vector<string> procesarArchivo_ArbolReves(const string& ruta_Diccionario);

    // Función para prefijos
    vector<string> encontrarPalabrasPrefijo(const string& prefijo);

    // Función para sufijos
    vector<string> encontrarPalabrasSufijo(const string& sufijo);
private:
    // Función auxiliar para encontrar un hijo con el carácter dado
    Nodo* encontrarHijo(Nodo* nodo, char letra);

    // Función auxiliar para recorrer y recolectar palabras
    void recorrerYRecolectar(Nodo* nodo, string palabraActual, vector<string>& palabrasEncontradas);
};

#endif // ENTREGA1_ARBOL_DEC_H
