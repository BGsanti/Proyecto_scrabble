#include "Diccionario_dec.h"
#include "Comando_dec.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm> // Para la funcion reverse
#include <list>


bool Diccionario::validarPalabra(const string& palabra) { // Argumento constante para evitar cambios
    for (char c : palabra) { // Iterar sobre cada carácter de la palabra
        if (!isalpha(c)) { // Si el carácter no es alfabético
            return false; // La palabra contiene símbolos inválidos
        }
    }
    return true; // Todos los caracteres son alfabéticos
}

vector<string> Diccionario::procesarArchivo(const string& ruta_Diccionario, const string& ruta_Invalidas) {

    ifstream archivoDiccionario(ruta_Diccionario);
    vector<string> palabrasValidas; // Lista (tipo vector) de palabras válidas
    string palabra;
    ofstream archivoInvalidas;
    bool archivoInvalidasAbierto = false; // Bandera para saber si el archivo de palabras inválidas está abierto

    if (!archivoDiccionario.is_open()) {  // Si no se puede abrir el archivo de diccionario
        cout << "El archivo diccionario.txt no existe o no puede ser leido" << endl;
        return palabrasValidas; // Retorna vector vacío si no se puede abrir el archivo

    }

    while (getline(archivoDiccionario, palabra)) { // Leer cada palabra del archivo
        if (validarPalabra(palabra)) { // Si la palabra es válida
            string palabraMinusculas = aMinusculas(palabra); // Convertir la palabra a minúsculas
            palabrasValidas.push_back(palabraMinusculas); // Añade a la lista de válidas
        } else {
            // Abre el archivo de palabras inválidas solo si es necesario y si aún no está abierto
            if (!archivoInvalidasAbierto) {
                archivoInvalidas.open(ruta_Invalidas);
                archivoInvalidasAbierto = true;
                if (!archivoInvalidas.is_open()) {
                    cout << "Error al abrir el archivo de palabras invalidas." << endl;
                    break; // Salir del bucle si no se puede abrir el archivo de palabras inválidas
                }
            }
            archivoInvalidas << palabra << '\n'; // Registra la palabra inválida
        }
    }

    // Cerrar archivos
    archivoDiccionario.close();
    cout << "\nEl diccionario se ha inicializado correctamente\n";
    if (archivoInvalidasAbierto) {
        archivoInvalidas.close();
    }
    cout << "Palabras incorrectas creadas con exito\n";
    cout << "Primer palabra del diccionario: " << palabrasValidas[0] << "\n";
    return palabrasValidas;

    /* Mostrar palabras válidas
    for (vector<string>::iterator it = palabrasValidas.begin(); it != palabrasValidas.end(); ++it) {
        std::cout << *it << '\n';
    }*/

}

vector<string> Diccionario::procesarArchivoReves(const string& ruta_Diccionario, const string& ruta_Invalidas) {
    ifstream archivoDiccionario(ruta_Diccionario);
    vector<string> palabrasValidas; // Lista (tipo vector) de palabras válidas
    string palabra;
    ofstream archivoInvalidas;
    bool archivoInvalidasAbierto = false; // Bandera para saber si el archivo de palabras inválidas está abierto

    if (!archivoDiccionario.is_open()) {  // Si no se puede abrir el archivo de diccionario
        cout << "El archivo diccionario.txt no existe o no puede ser leido" << endl;
        return palabrasValidas; // Retorna vector vacío si no se puede abrir el archivo
    }

    while (getline(archivoDiccionario, palabra)) { // Leer cada palabra del archivo
        if (validarPalabra(palabra)) { // Si la palabra es válida
            string palabraMinusculas = aMinusculas(palabra); // Convertir la palabra a minúsculas
            reverse(palabraMinusculas.begin(), palabraMinusculas.end()); // Invertir la palabra
            palabrasValidas.push_back(palabraMinusculas); // Añade a la lista de válidas en sentido inverso
        } else {
            // Abre el archivo de palabras inválidas solo si es necesario y si aún no está abierto
            if (!archivoInvalidasAbierto) {
                archivoInvalidas.open(ruta_Invalidas);
                archivoInvalidasAbierto = true;
                if (!archivoInvalidas.is_open()) {
                    cout << "Error al abrir el archivo de palabras invalidas." << endl;
                    break; // Salir del bucle si no se puede abrir el archivo de palabras inválidas
                }
            }
            archivoInvalidas << palabra << '\n'; // Registra la palabra inválida
        }
    }

    // Cerrar archivos
    archivoDiccionario.close();
    if (archivoInvalidasAbierto) {
        archivoInvalidas.close();
    }

    cout << "\nEl diccionario se ha inicializado correctamente\n";
    cout << "Palabras incorrectas creadas con exito\n";
    // Opcional: mostrar la primera palabra válida invertida para verificar
    if (!palabrasValidas.empty()) {
        cout << "Primer palabra del diccionario invertido: " << palabrasValidas[0] << "\n";
    }

    return palabrasValidas;
}

int Diccionario:: puntosLetra(char letra) {
    switch (letra) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'N':
        case 'R':
        case 'T':
        case 'L':
        case 'S':
            return 1;
        case 'D':
        case 'G':
            return 2;
        case 'C':
        case 'B':
        case 'M':
        case 'P':
            return 3;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            return 4;
        case 'K':
            return 5;
        case 'J':
        case 'X':
            return 8;
        case 'Q':
        case 'Z':
            return 10;
        default:
            return 0; // Si la letra no es válida, retornar 0
    }
}

int Diccionario::calcularPuntaje(const string& palabra) {
    int puntaje = 0;
    for (char letra : palabra) {
        puntaje += puntosLetra(toupper(letra)); // Convertir a mayúsculas para hacer la comparación
    }
    return puntaje;
}

int Diccionario::encontrarPalabra(const vector<string> &palabras, const vector<string> &palabrasInvertidas, const string &palabraBuscada) {

    // Buscar en el vector de palabras normales
    for (size_t i = 0; i < palabras.size(); ++i) {
        if (palabras[i] == palabraBuscada) {
            return calcularPuntaje(palabraBuscada);
        }
    }

    // Si no se encuentra, buscar en el vector de palabras invertidas
    for (size_t j = 0; j < palabrasInvertidas.size(); ++j) {
        if (palabrasInvertidas[j] == palabraBuscada) {
            return calcularPuntaje(palabraBuscada);
        }
    }

    return 0; // Retorna 0 si la palabra no se encuentra en ninguno de los vectores
}

std::list<std::string> Diccionario::listaDiccionario(string ruta_Diccionario){
    std::list<std::string> palabras;
    string palabra;
    std::fstream diccionario(ruta_Diccionario);
    
    if(diccionario.is_open()){
        while(std::getline(diccionario, palabra)){
            palabras.push_back(palabra);
        }
        diccionario.close();
    }
        
    else {
         std::cout << "no se pudo abrir el diccionario!!!!" << std::endl;
    }

    return palabras;
}
