#ifndef ENTREGA1_DICCIONARIO_DEC_H
#define ENTREGA1_DICCIONARIO_DEC_H

#include <string>
#include <vector>
#include <list>

using namespace std;

class Diccionario {
private:
    vector<std::string> palabrasValidasInvertidas, palabrasValidas; // Vector que almacena las palabras validas invertidas y no invertidas

public:
    bool validarPalabra(const string& palabra);
    vector<string> procesarArchivo(const string& ruta_Diccionario, const string& ruta_Invalidas);
    vector<string> procesarArchivoReves(const string& ruta_Diccionario, const string& ruta_Invalidas);
    int encontrarPalabra(const vector<string> &palabras, const vector<string> &palabrasInvertidas, const string &palabraBuscada);
    int puntosLetra(char letra);
    int calcularPuntaje(const string& palabra);
    vector<string> procesarArchivo(const string &ruta_Diccionario);

    /*funcion axiliar para crear lista con todas las palabras del diccionario y asi crear el grafo*/
    std::list<std::string> listaDiccionario(string ruta_Diccionario);
};

#endif //ENTREGA1_DICCIONARIO_DEC_H
