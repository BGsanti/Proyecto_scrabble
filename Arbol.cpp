 #include "Diccionario_dec.h"
#include "Comando_dec.h"
#include <algorithm> // para std::max
#include <fstream>
#include "Arbol_dec.h"

using namespace std;
//Funciones del árbol------------------------------------------------------------------

// Implementación del constructor de Nodo
Nodo::Nodo(char letra) {
    this->letra = letra;
    this->finPalabra = false;
}

// Implementación del constructor de ArbolGeneral
ArbolGeneral::ArbolGeneral() {
    raiz = new Nodo('\0');  // Nodo raíz con carácter nulo como marcador
}

// Implementación de la función para insertar palabras en el árbol
void ArbolGeneral::insertar(const string& palabra) {
    Nodo* actual = raiz;
    // Iterar sobre cada carácter de la palabra
    for (char ch : palabra) {
        // Buscar un hijo con el carácter actual
        Nodo* hijo = encontrarHijo(actual, ch);
        if (!hijo) {
            // Si no se encuentra, crear un nuevo nodo hijo
            hijo = new Nodo(ch);
            // Añadir el nuevo nodo hijo al nodo actual
            actual->hijos.push_back(hijo);
        }
        actual = hijo;
    }
    actual->finPalabra = true;  // Marca el final de la palabra
}

// Implementación del destructor de ArbolGeneral
ArbolGeneral::~ArbolGeneral() {
    limpiar(raiz);
}

// Implementación de encontrarHijo
Nodo* ArbolGeneral::encontrarHijo(Nodo* nodo, char letra) {
    // Iterar sobre los hijos del nodo
    for (Nodo* hijo : nodo->hijos) {
        // Si se encuentra un hijo con el carácter dado, retornar el hijo
        if (hijo->letra == letra) {
            return hijo;
        }
    }
    return nullptr;
}

// Implementación de la función limpiar
void ArbolGeneral::limpiar(Nodo* nodo) {
    for (Nodo* hijo : nodo->hijos) {
        limpiar(hijo);
    }
    delete nodo;
}

//Implementación de la función para insertar palabras en el árbol
void ArbolGeneral::insertarPalabras(const vector<string>& palabras) {
    for (const string& palabra : palabras) {
        insertar(palabra);
    }
}

// Implementación de la función para buscar una palabra en el árbol
bool ArbolGeneral::buscar(const std::string &palabra) {
    Nodo* actual = raiz;
    for (char ch : palabra) {
        Nodo* hijo = encontrarHijo(actual, ch);
        if (!hijo) {
            return false;
        }
        actual = hijo;
    }
    return actual->finPalabra;

}


//Implementación de procesamiento de archivos----------------------------------------------

vector<string> ArbolGeneral::procesarArchivo_Arbol(const string& ruta_Diccionario) {

    ifstream archivoDiccionario(ruta_Diccionario);
    vector<string> palabrasValidas; // Lista (tipo vector) de palabras válidas
    string palabra;
    Diccionario dic;


    if (!archivoDiccionario.is_open()) {  // Si no se puede abrir el archivo de diccionario
        cout << "El archivo diccionario.txt no existe o no puede ser leido" << endl;
        return palabrasValidas; // Retorna vector vacío si no se puede abrir el archivo

    }

    while (getline(archivoDiccionario, palabra)) { // Leer cada palabra del archivo
        if (dic.validarPalabra(palabra)) { // Si la palabra es válida
            string palabraMinusculas = aMinusculas(palabra); // Convertir la palabra a minúsculas
            palabrasValidas.push_back(palabraMinusculas); // Añade a la lista de válidas
        }
    }
    archivoDiccionario.close();
    return palabrasValidas;
}

vector<string> ArbolGeneral::procesarArchivo_ArbolReves(const string& ruta_Diccionario) {

    ifstream archivoDiccionario(ruta_Diccionario);
    vector<string> palabrasValidas; // Lista (tipo vector) de palabras válidas
    string palabra;
    Diccionario dic;


    if (!archivoDiccionario.is_open()) {  // Si no se puede abrir el archivo de diccionario
        cout << "El archivo diccionario.txt no existe o no puede ser leido" << endl;
        return palabrasValidas; // Retorna vector vacío si no se puede abrir el archivo

    }

    while (getline(archivoDiccionario, palabra)) { // Leer cada palabra del archivo
        if (dic.validarPalabra(palabra)) { // Si la palabra es válida
            string palabraMinusculas = aMinusculas(palabra); // Convertir la palabra a minúsculas
            reverse(palabraMinusculas.begin(), palabraMinusculas.end()); // Invertir la palabra
            palabrasValidas.push_back(palabraMinusculas); // Añade a la lista de válidas
        }
    }
    archivoDiccionario.close();
    return palabrasValidas;
}

//Implementación de recorrer y recolectar----------------------------------------------
void ArbolGeneral::recorrerYRecolectar(Nodo* nodo, string palabraActual, vector<string>& palabrasEncontradas) {
    // Si se llega al final de una palabra, añadir la palabra actual a la lista de palabras encontradas
    if (nodo->finPalabra) {
        palabrasEncontradas.push_back(palabraActual);
    }
    // Recorrer los hijos del nodo actual
    for (Nodo* hijo : nodo->hijos) {
        // Llamar recursivamente a la función con el hijo actual
        recorrerYRecolectar(hijo, palabraActual + hijo->letra, palabrasEncontradas);
    }
}

//Implementación de prefijo----------------------------------------------
vector<string> ArbolGeneral::encontrarPalabrasPrefijo(const string& prefijo) {
    vector<string> palabrasEncontradas;
    Nodo* actual = raiz;
    // Iterar sobre cada carácter del prefijo
    for (char ch : prefijo) {
        // Buscar un hijo con el carácter actual
        Nodo* hijo = encontrarHijo(actual, ch);
        if (!hijo) {
            return palabrasEncontradas;
        }
        actual = hijo;
    }

    recorrerYRecolectar(actual, prefijo, palabrasEncontradas);
    return palabrasEncontradas;
}

//Implementación de sufijos----------------------------------------------

vector<string> ArbolGeneral::encontrarPalabrasSufijo(const string& sufijo) {
  vector<string> palabrasEncontradas;
    string sufijoInvertido = sufijo;

    // Invertir el sufijo para convertirlo en un prefijo
    reverse(sufijoInvertido.begin(), sufijoInvertido.end());

    // Utilizar la función de prefijo para encontrar todas las palabras que comienzan con el "prefijo" (sufijo invertido)
    palabrasEncontradas = encontrarPalabrasPrefijo(sufijoInvertido);

    // Invertir las palabras encontradas para obtener las palabras originales que terminan con el sufijo
    for (string& palabra : palabrasEncontradas) {
        reverse(palabra.begin(), palabra.end());
    }

    return palabrasEncontradas;
}
