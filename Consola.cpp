#include <stdlib.h>
#include "Comando_dec.h"
#include "Diccionario_dec.h"
#include "Arbol_dec.h"
#include "Grafo.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <list>




using namespace std;

int main() {

    string entrada, comando, argumento; // Variables para almacenar la entrada del usuario
    bool cambio = true; // Variable para controlar el ciclo del menú
    vector<string> palabrasValidasInvertidas, palabrasValidas, letrasArbol, letrasArbolInvertidas;
    Diccionario dic;     // Objeto de la clase Diccionario
    ArbolGeneral arbolPre, arbolSu;       // Objeto de la clase Arbol
    Grafo grafoPalabras;
    do {
        cout << "_";
        getline(cin, entrada);
        entrada = aMinusculas(entrada);

        // Encuentra el primer espacio para separar el comando de los argumentos
        size_t espacio = entrada.find(" ");
        comando = entrada.substr(0, espacio); // Extrae el comando de la entrada
        argumento.clear(); // Limpia el argumento


        if (espacio != string::npos) { // Si hay un espacio en la entrada
            argumento = entrada.substr(espacio + 1); // Extrae el argumento
        }

        if (comando == "ayuda") { // Si el comando es "ayuda"
            if (!argumento.empty()) { // Si hay un argumento
                mostrarAyudaEspecifica(argumento);
            } else {
                mostrarAyudaGeneral(); // Si no hay argumento, mostrar la ayuda general
            }
        } else if (comando == "cls") {
            borrar();
        }
            //////////////////////////////////////////////////////
        else if (comando == "inicializar" && argumento == "diccionario.txt") {

            string ruta_Diccionario, ruta_Invalidas;
            bool ciclo = true;
            do {
                cout << "Ingrese la ruta del archivo del diccionario: ";
                getline(cin, ruta_Diccionario); // Lee la ruta del archivo de entrada
                cout << endl << "Ingrese la ruta del archivo de las palabras invalidas: ";
                getline(cin, ruta_Invalidas); // Lee la ruta del archivo de entrada
                ruta_Invalidas += "_Invalid_Words.txt";
                cout << "Es correcta la informacion ingresada? (si/no): ";
                string respuesta;
                cout << endl;
                getline(cin, respuesta);
                respuesta = aMinusculas(respuesta);
                if (respuesta == "si") {
                    ciclo = false;
                }
            } while (ciclo == true);


            palabrasValidas = dic.procesarArchivo(ruta_Diccionario, ruta_Invalidas);

        } else if (comando == "iniciar_inverso" && argumento == "diccionario.txt") {

            string ruta_Diccionario, ruta_Invalidas;
            bool ciclo = true;
            do {
                cout << "Ingrese la ruta del archivo del diccionario: ";
                getline(cin, ruta_Diccionario); // Lee la ruta del archivo de entrada
                cout << endl << "Ingrese la ruta del archivo de las palabras invalidas: ";
                getline(cin, ruta_Invalidas); // Lee la ruta del archivo de entrada
                ruta_Invalidas += "_Invalid_Words.txt";
                cout << "Es correcta la informacion ingresada? (si/no): ";
                string respuesta;
                cout << endl;
                getline(cin, respuesta);
                respuesta = aMinusculas(respuesta);
                if (respuesta == "si") {
                    ciclo = false;
                }
            } while (ciclo == true);

            palabrasValidasInvertidas = dic.procesarArchivoReves(ruta_Diccionario, ruta_Invalidas);

        } else if (comando == "puntaje" && argumento == "palabra") {

            if (!palabrasValidas.empty() || !palabrasValidasInvertidas.empty()) {
                // Si alguno de los diccionarios está inicializado, proceder con la lógica
                string palabra;
                cout << "Ingrese la palabra: ";
                getline(cin, palabra);
                palabra = aMinusculas(palabra);
                int puntaje = dic.encontrarPalabra(palabrasValidas, palabrasValidasInvertidas, palabra);
                if (puntaje == 0) {
                    cout << "La palabra '" << palabra << "' no se encuentra en el diccionario.\n";
                } else {
                    cout << "El puntaje de la palabra '" << palabra << "' es: " << puntaje << "\n";
                }
                //cout << "El puntaje de la palabra '" << palabra << "' es: " << dic.encontrarPalabra(palabrasValidas, palabrasValidasInvertidas, palabra) << "\n";
            } else {
                // Si ambos diccionarios están vacíos, mostrar mensaje de que no se ha inicializado ningún diccionario
                cout << "No se ha inicializado ningun diccionario. Por favor, inicialice al menos uno.\n";
            }

        }
            ////////////////////////////////////////////////
        else if (comando == "iniciar_arbol" && argumento == "diccionario.txt") {

            arbolPre.limpiar(arbolPre.raiz);
            arbolSu.limpiar(arbolSu.raiz);
            arbolPre.raiz = new Nodo('\0');  // Reestablece el nodo raíz
            arbolSu.raiz = new Nodo('\0');  // Reestablece el nodo raíz

            string ruta_Diccionario;
            bool ciclo = true;
            do {
                cout << "Ingrese la ruta del archivo del diccionario: ";
                getline(cin, ruta_Diccionario); // Lee la ruta del archivo de entrada
                cout << "Es correcta la informacion ingresada? (si/no): ";
                string respuesta;
                cout << endl;
                getline(cin, respuesta);
                respuesta = aMinusculas(respuesta);
                if (respuesta == "si") {
                    ciclo = false;
                }
            } while (ciclo);

            letrasArbol = arbolPre.procesarArchivo_Arbol(ruta_Diccionario);
            letrasArbolInvertidas = arbolSu.procesarArchivo_ArbolReves(ruta_Diccionario);
            arbolPre.insertarPalabras(letrasArbol);
            arbolSu.insertarPalabras(letrasArbolInvertidas);
            cout << "Arbol General inicializado con exito.\n";
            string verificacion;
            cout << endl << "Ingrese una palabra que se encuentre en el arbol o escriba 'salir' para terminar: ";
            getline(cin, verificacion);
            verificacion = aMinusculas(verificacion);

            while (true) {
                if (verificacion == "salir") {  // Permite al usuario salir del bucle
                    break;
                }

                if (arbolPre.buscar(verificacion)) {  // Verifica si la palabra está en el árbol
                    cout << "La palabra se encuentra en el arbol." << endl;
                    break;  // Sale del bucle si encuentra la palabra
                } else {
                    cout << "La palabra no se encuentra en el arbol. Intente nuevamente o escriba 'salir' para terminar: ";
                    getline(cin, verificacion);
                    verificacion = aMinusculas(verificacion);
                }
            }


        } else if (comando == "iniciar_arbol_inverso" && argumento == "diccionario.txt") {
            string ruta_Diccionario;
            bool ciclo = true;

            arbolPre.limpiar(arbolPre.raiz);
            arbolSu.limpiar(arbolSu.raiz);
            arbolPre.raiz = new Nodo('\0');  // Reestablece el nodo raíz
            arbolSu.raiz = new Nodo('\0');  // Reestablece el nodo raíz

            do {
                cout << "Ingrese la ruta del archivo del diccionario: ";
                getline(cin, ruta_Diccionario); // Lee la ruta del archivo de entrada
                cout << "Es correcta la informacion ingresada? (si/no): ";
                string respuesta;
                cout << endl;
                getline(cin, respuesta);
                respuesta = aMinusculas(respuesta);
                if (respuesta == "si") {
                    ciclo = false;
                }
            } while (ciclo == true);


            letrasArbolInvertidas = arbolPre.procesarArchivo_ArbolReves(ruta_Diccionario);
            letrasArbol = arbolSu.procesarArchivo_Arbol(ruta_Diccionario);
            arbolSu.insertarPalabras(letrasArbol);
            arbolPre.insertarPalabras(letrasArbolInvertidas);
            cout << "Arbol General inverso inicializado con exito.\n";
            string verificacion;
            cout << endl << "Ingrese una palabra que se encuentre en el arbol o escriba 'salir' para terminar: ";
            getline(cin, verificacion);
            verificacion = aMinusculas(verificacion);

            while (true) {
                if (verificacion == "salir") {  // Permite al usuario salir del bucle
                    break;
                }

                if (arbolPre.buscar(verificacion)) {  // Verifica si la palabra está en el árbol
                    cout << "La palabra se encuentra en el arbol." << endl;
                    break;  // Sale del bucle si encuentra la palabra
                } else {
                    cout << "La palabra no se encuentra en el arbol. Intente nuevamente o escriba 'salir' para terminar: ";
                    getline(cin, verificacion);
                    verificacion = aMinusculas(verificacion);
                }
            }

        } else if (comando == "palabras_por_prefijo") {

            string palabra;

            if (!letrasArbolInvertidas.empty() || !letrasArbol.empty()) {
                string prefijo;
                cout << "Ingrese el prefijo para buscar palabras: ";
                cin >> prefijo;
                prefijo = aMinusculas(prefijo);
                vector<string> palabrasPrefijo = arbolPre.encontrarPalabrasPrefijo(prefijo);
                if (palabrasPrefijo.empty()) {
                    cout << "No se encontraron palabras con el prefijo '" << prefijo << "'.\n";
                } else {
                    cout << "Palabras encontradas con el prefijo '" << prefijo << "':" << endl;
                    for (const string &palabra: palabrasPrefijo) {
                        cout << "Palabra: " << palabra << ", Longitud: " << palabra.size() << ", Puntuacion: "
                             << dic.calcularPuntaje(palabra) << endl;
                    }
                }


            } else {
                // Si ambos diccionarios están vacíos, mostrar mensaje de que no se ha inicializado ningún diccionario
                cout << "No se ha inicializado ningun diccionario en arbol. Por favor, inicialice al menos uno.\n";
            }


        } else if (comando == "palabras_por_sufijo") {

            string palabra;

            if (!letrasArbolInvertidas.empty() || !letrasArbol.empty()) {
                string sufijo;
                cout << "Ingrese el sufijo para buscar palabras: ";
                cin >> sufijo;
                sufijo = aMinusculas(sufijo);
                vector<string> palabrasSufijo = arbolSu.encontrarPalabrasSufijo(sufijo);
                if (palabrasSufijo.empty()) {
                    cout << "No se encontraron palabras con el sufijo '" << sufijo << "'.\n";
                } else {
                    cout << "Palabras encontradas con el prefijo '" << sufijo << "':" << endl;
                    for (const string &palabra: palabrasSufijo) {
                        string palabraInvertida = palabra;
                        reverse(palabraInvertida.begin(), palabraInvertida.end());  // Invierte la copia
                        cout << "Palabra: " << palabraInvertida
                             << ", Longitud: " << palabraInvertida.size()
                             << ", Puntuacion: " << dic.calcularPuntaje(palabraInvertida) << endl;
                    }
                }


            } else {
                // Si ambos diccionarios están vacíos, mostrar mensaje de que no se ha inicializado ningún diccionario
                cout << "No se ha inicializado ningun diccionario en arbol. Por favor, inicialice al menos uno.\n";
            }
        } else if (comando == "salir") {
            cambio = false;
            cout << "Saliendo\n";
            cambio = false;
        } else if (comando == "iniciar" || comando == "incializar" || comando == "palabras" || comando == "puntaje") {

            cout << "Requiere mas argumentos para poder inicializar el comando de manera correcta\n";
        } else if (comando.empty()) {
            continue;
        } 
        
        else if(comando == "grafo_de_palabras" ){
            std::list<std::string> palabras = dic.listaDiccionario("Diccionario.txt");
           

            /*añadimos todo el diccionario*/
            for(auto it = palabras.begin(); it != palabras.end(); it ++){
                grafoPalabras.insertarNodo(*it);
            }
            /*añadimos las aristas*/   
            for(auto it = palabras.begin(); it != palabras.end(); it++){
                std::list<std::string> palabrasBros;
                for(auto it2 = palabras.begin()++; it2 != palabras.end(); it2++){
                    std::string palabra = *it;
                    std::string palbraBro = *it2;
          
                    int contadorErrores = 0;
                    for(int i = 0; i < palbraBro.size(); i++){
                        if(palabra[i] != palbraBro[i]){
                            contadorErrores += 1;
                        }
                        if(contadorErrores > 1){
                            break;
                        } 
                    } 
                    if(contadorErrores == 1){
                        palabrasBros.push_back(palbraBro);
                    }
                }
                for(auto itBros = palabrasBros.begin(); itBros != palabrasBros.end(); itBros++){
                    grafoPalabras.agregarConeccion(*it, *itBros);
                }
            }
            if(grafoPalabras.getNodos().size() != 0){
                std::cout << "Se creo el grafo con exito" << std::endl;
            }
          grafoPalabras.imprimirGrafo();
        } else if (comando == "posibles_palabras" && !argumento.empty()) {
    // Validar que la cadena de letras sea válida
    bool letraValida = true;
    for (char c : argumento) {
        if (!isalpha(c) && c != '?') {
            letraValida = false;
            break;
        }
    }

    if (!letraValida) {
        cout << "La cadena " << argumento << " contiene símbolos inválidos." << endl;
    } else {
        std::vector<std::string> palabrasValidas = grafoPalabras.generarPalabrasComodin(argumento);
        if (palabrasValidas.empty()) {
            cout << "No se encontraron palabras válidas con las letras proporcionadas." << endl;
        } else {
            cout << "Las posibles palabras a construir con las letras " << argumento << " son:" << endl;
            for (const std::string& palabra : palabrasValidas) {
                cout << "Palabra: " << palabra << ", Longitud: " << palabra.length()
                     << ", Puntuación: " << dic.calcularPuntaje(palabra) << endl;
            }
        }
    }
}
        
        else {
            cout << "Comando " << "'" << entrada << "'" << " no existe, digite el comando de nuevo:\n";
            cout << "Ingrese el comando 'ayuda' para ver la lista de comandos\n";
        }

        


    } while (cambio);

}