#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */

using namespace std;
//Contar cada char y pasarlo a minuscula 

string aMinusculas(const string &entrada) {
    string resultado;
    size_t inicio = 0; // Posición inicial de la cadena sin espacios en blanco.
    size_t fin = entrada.size(); // Posición final de la cadena sin espacios en blanco.

    // Encuentra el inicio de la cadena sin espacios en blanco.
    while (inicio < fin && isspace(static_cast<unsigned char>(entrada[inicio]))) { // isspace verifica si el carácter es un espacio en blanco
        ++inicio; // Avanza al siguiente carácter
    }

    // Encuentra el fin de la cadena sin espacios en blanco (apunta al último carácter + 1).
    while (fin > inicio && isspace(static_cast<unsigned char>(entrada[fin - 1]))) { // isspace verifica si el carácter es un espacio en blanco
        --fin; // Retrocede al carácter anterior
    }

    // Convierte a minúsculas y copia en resultado.
    for (size_t i = inicio; i < fin; ++i) { // Itera sobre cada carácter de la cadena
        resultado += tolower(static_cast<int>(static_cast<unsigned char>(entrada[i]))); // Convierte a minúsculas y añade al resultado
    }                                                                                      // (static_cast<unsigned char> convierte a unsigned char)
    // (static_cast<int> convierte a int), tolower convierte a minúsculas
    return resultado;
}


void mostrarAyudaGeneral() {
    std::cout <<GREEN << "\nComandos disponibles:\n\n"<< RESET << std::endl;

    std::cout << "- inicializar diccionario.txt: Inicializa el sistema a partir del archivo "
              << "diccionario.txt, que contiene un diccionario de palabras aceptadas en ingles.\n\n";

    std::cout << "- iniciar_inverso diccionario.txt: Inicializa el sistema a partir del archivo "
              << "diccionario.txt, que contiene un diccionario de palabras aceptadas en ingles.\n\n";

    std::cout << "- puntaje palabra: El comando permite conocer la puntuacion que puede obtenerse con una palabra dada, "
              << "de acuerdo a la tabla de puntuacion de cada letra presentada anteriormente.\n\n";

    std::cout << "- iniciar_arbol diccionario.txt: Inicializa el sistema a partir del archivo "
              << "diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma ingles. Este comando "
              << "almacena las palabras en uno o mas arboles de letras.\n\n";

    std::cout << "- iniciar_arbol_inverso diccionario.txt: Inicializa el sistema a partir del archivo "
              << "diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma ingles. Este comando "
              << "almacena las palabras en uno o mas arboles de letras, pero en sentido inverso.\n\n";

    std::cout << "- palabras_por_prefijo prefijo: Dado un prefijo de pocas letras, el comando recorre el(los) arbol(es) de letras "
              << "(construido(s) con el comando iniciar_arbol) para ubicar todas las palabras posibles a construir a partir de ese prefijo. "
              << "Se incluye todas las palabras posibles, su longitud y puntaje.\n\n";

    std::cout << "- palabras_por_sufijo sufijo: Dado un sufijo de pocas letras, el comando recorre el(los) arbol(es) de letras "
              << "(construido(s) con el comando iniciar_arbol_inverso) para ubicar todas las palabras posibles a construir que terminan "
              << "con ese sufijo. Se incluye todas las palabras posibles, su longitud y puntaje.\n\n";

    std::cout << "- grafo_de_palabras: Genera y muestra un grafo de palabras basado en las conexiones entre las palabras del diccionario.\n\n";

    std::cout << "- posibles_palabras letras: Dado un conjunto de letras, muestra todas las palabras posibles que pueden formarse "
              << "con esas letras segun el diccionario.\n\n";

    std::cout << "- ayuda [comando]: Indica la forma correcta de hacer el llamado\n\n";

    std::cout << "- salir: Devolverse a la pantalla principal.\n\n";
}


void mostrarAyudaEspecifica(const string& comando){

    if(comando == "inicializar diccionario.txt") {
        cout << "Ayuda para inicializar diccionario.txt: ...\n";
        cout << "\t- Entradas:  La ruta al archivo 'diccionario.txt'\n";
        cout << "\t- Exito: El diccionario se ha inicializado correctamente.\n";
        cout << "\t- Fracaso: El archivo diccionario.txt no existe o no puede ser leido.\n";
        cout << "\t- Descripcion: Las palabras deben ser verificadas para no\n"
                "\t               almacenar aquellas que incluyen simbolos invalidos\n"
                "\t               (como guiones, numeros y signos de puntuacion).\n";


    }
    else if(comando == "iniciar_inverso diccionario.txt") {
        cout << "Ayuda para iniciar_inverso diccionario.txt: ...\n";
        cout << "\t- Entradas:  La ruta al archivo 'diccionario.txt'\n";
        cout << "\t- Exito: El diccionario inverso se ha inicializado correctamente.\n";
        cout << "\t- Fracaso: El archivo diccionario.txt no existe o no puede ser leido.\n";
        cout << "\t- Descripcion: Este comando almacena las palabras en uno o mas arboles de letras,\n"
                "\t               pero en sentido inverso Las palabras deben ser verificadas para no\n"
                "\t               almacenar aquellas que incluyen simbolos invalidos\n"
                "\t               (como guiones, numeros y signos de puntuacion).\n";



    }
    else if(comando == "puntaje palabra") {
        cout << "Ayuda para puntaje palabra: ...\n";
        cout << "\t- Entradas: Una palabra para la cual se desea conocer el puntaje.\n";
        cout << "\t- Exito: La palabra tiene un puntaje de [puntaje].\n";
        cout << "\t- Fracaso: La palabra no existe en el diccionario.\n";
        cout << "\t           La palabra contiene símbolos invalidos.\n";
        cout << "\t- Descripcion: El comando debe verificar que la palabra sea valida,\n"
                "\t               es decir, que exista en el diccionario (tanto original como en sentido inverso),\n"
                "\t               y que este escrita con simbolos validos.\n";



    }

    else if(comando == "iniciar_arbol diccionario.txt") {
        cout << "Ayuda para iniciar_arbol diccionario: ...\n";
        cout << "\t- Entradas:  La ruta al archivo 'diccionario.txt'\n";
        cout << "\t- Exito: El arbol del diccionario se ha inicializado correctamente.\n";
        cout << "\t- Fracaso: El archivo diccionario.txt no existe o no puede ser leido.\n";
        cout << "\t- Descripcion:  A diferencia del comando inicializar, este comando almacena las palabras en uno o ,\n"
                "\t                mas arboles de letras (como se considere conveniente). Las palabras deben ser\n"
                "\t                verificadas para no almacenar aquellas que incluyen simbolos invalidos (como\n"
                "\t                guiones, numeros y signos de puntuacion).\n";

    }
    else if(comando == "iniciar_arbol_inverso diccionario.txt") {
        cout << "Ayuda para iniciar_arbol_inverso: ...\n";
        cout << "\t- Entradas:  La ruta al archivo 'diccionario.txt'\n";
        cout << "\t- Exito: El arbol del diccionario inverso se ha inicializado correctamente.\n";
        cout << "\t- Fracaso: El archivo diccionario.txt no existe o no puede ser leido.\n";
        cout << "\t- Descripcion: A diferencia de los comandos iniciar_inverso e iniciar_arbol, este comando\n"
                "\t               almacena las palabras en uno o mas arboles de letras, pero en sentido inverso\n"
                "\t               (leidas de derecha a izquierda). Las palabras tambien deben ser verificadas para no\n"
                "\t               almacenar aquellas que incluyen simbolos invalidos (como guiones, numeros y signos de puntuacion)..\n";

    }
    else if(comando == "palabras_por_prefijo prefijo") {
        cout << "Ayuda para palabras_por_prefijo prefijo: ...\n";
        cout << "\t- Entradas:  Un prefijo de pocas letras.\n";
        cout << "\t- Exito: Las palabras que inician con este prefijo son: seguido de la lista de palabras posibles,\n"
                "    la longitud de cada una y la puntuacion que cada una puede obtener.\n";
        cout << "\t- Fracaso: Prefijo [prefijo] no pudo encontrarse en el diccionario.\n";
        cout << "\t- Descripcion: Se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada\n"
                "\t               una y la puntuacion que cada una puede obtener.\n";


    }
    else if(comando == "palabras_por_sufijo sufijo") {
        cout << "Ayuda para palabras_por_sufijo sufijo: ...\n";
        cout << "\t- Entradas:  Un sufijo de pocas letras.'\n";
        cout << "\t- Exito: Las palabras que inician con este sufijo son: seguido de la lista de palabras posibles,\n"
                "    la longitud de cada una y la puntuacion que cada una puede obtener.\n";
        cout << "\t- Fracaso: Sufijo [sufijo] no pudo encontrarse en el diccionario.\n";
        cout << "\t- Descripcion: Se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada\n"
                "\t               una y la puntuacion que cada una puede obtener.\n";

    }

    else if(comando == "grafo_de_palabras") {
        cout << "Ayuda para grafo_de_palabras: ...\n";
        cout << "\t- Entradas:  Invocacion de comando.\n";
        cout << "\t- Exito: Grafo construido correctamente\n";
        cout << "\t- Fracaso: Error al construir el grafo: no se encontraron palabras en el diccionario.\n";
        cout << "\t- Descripcion: El comando construye un grafo de palabras, en donde cada palabra se conecta a las\n"
                "\t               demas si y solo si difieren en una unica letra (con las demas letras iguales y en las\n"
                "\t               mismas posiciones).\n";


    }
    else if(comando == "posibles_palabras letras") {
        cout << "Ayuda para posibles_palabras letras: ...\n";
        cout << "\t- Entradas:  Una cadena de caracteres <letras> que representa las letras disponibles para formar palabras.\n"
                "    Esta cadena puede incluir un unico simbolo comodin ('?').\n";
        cout << "\t- Exito: Las posibles palabras a construir con las letras <letras> son: (...)\n";
        cout << "\t- Fracaso: Error: el grafo de palabras no ha sido construido.\n";
        cout << "\t- Descripcion: En las letras de la cadena de caracteres, puede admitirse un unico simbolo comodin\n"
                "\t               (?), el cual representara una letra desconocida y permitira generar mayores \n"
                "\t               posibilidades de palabras a construir. Para este proposito, el comando debe hacer\n"
                "\t               uso del grafo de palabras construido con el comando grafo_de_palabras.\n";

    }
    else{
        cout << "Comando no existe\n";

    }

}

bool borrar() {
#ifdef _WIN32      // Si el sistema operativo es Windows
    int result = system("cls");
#else              // Si el sistema operativo es Linux o Mac
    int result = system("clear");
#endif

    if (result != 0) {
        std::cerr << "Error executing command to clear the screen." << std::endl;
        return false; // Retornar false si hubo un error
    }
    return true; // Retornar true si el comando se ejecutó correctamente
}