# Proyecto_Scrabble
# Integrantes: 
Andrés Felipe Galán Cárdenas, Santiago Barrero Granados, Jerónimo Vanegas Jiménez, Samuel Andrés Tovar Sarmiento y Sebastián Sánchez Olaya.

Este proyecto fue construido para la clase Estructura de Datos en el primer semestre de 2024.

# Objetivo: 
Este proyecto tiene como objetivo ser una asistencia al momento de jugar "Scrabble", brindando funcionalidades como la búsqueda de palabras del diccionario por prefijos y sufijos proporcionados por el usuario, así como la búsqueda de palabras dadas un conjunto ordenado de letras proporcionado por el usuario. Estas herramientas están diseñadas para ayudar al usuario durante su partida de Scrabble.

# Composición: 

Se compone de 3 grandes entregas este proyecto:

  1 Entrega: se planteaba la forma de comunicación del usuario final a la máquina a través de la consola, y se proponían estructuras básicas como listas, vectores, pilas y colas con el objetivo de analizar un archivo de formato "txt" y verificar que las palabras de este archivo fueran válidas para el idioma inglés. El fin de esta entrega era inicializar el sistema.
  
  2 Entrega: Se implementó una estructura de datos conocida como "Árbol general" para hallar palabras que, partiendo del diccionario, coincidan con un sufijo o prefijo dado.
  
  3 Entrega: Usamos una estructura de datos conocida como "Grafo no dirigido" con el fin de, dada una secuencia de caracteres, proporcionar al usuario la capacidad de encontrar palabras válidas para el juego.

descripcion de cada clase a traves de su archivo de encabezado:

  - comando_dec.h: es un archivo de encabezado que proporciona declaraciones de funciones para la manipulación de cadenas de texto y la presentación de ayuda en un programa. Está diseñado para ser incluido en múltiples archivos fuente sin causar problemas de redefinición. Las funciones declaradas permiten convertir cadenas a minúsculas, mostrar ayuda general y específica, y realizar alguna operación de borrado con indicación de éxito.
  - Diccionario_dec.h: es un archivo de encabezado que define la interfaz de la clase Diccionario, que maneja operaciones relacionadas con la validación y procesamiento de palabras, cálculo de puntajes y la generación de listas de palabras para otras estructuras de datos. La clase proporciona métodos para procesar archivos de diccionarios, buscar palabras, y calcular puntajes, facilitando el manejo de datos textuales en aplicaciones más complejas.
  - consola.cpp es la parte interactiva por consola que permite a los usuarios manipular un diccionario de palabras, buscar palabras por prefijos y sufijos, calcular puntajes de palabras, y trabajar con un grafo de palabras. La aplicación utiliza varias estructuras de datos avanzadas como árboles y grafos para ofrecer funcionalidades complejas relacionadas con el procesamiento de palabras. Basicamente es el "main".
  - NodoG.h: Encapsula la lógica necesaria para manejar los nodos en un grafo de palabras, proporcionando métodos para acceder y modificar la palabra que contienen.
  - Grafo.h: proporciona una estructura y métodos completos para manipular y explorar un grafo de palabras, permitiendo operaciones básicas como inserción, eliminación y búsqueda, así como la generación de palabras basadas en comodines.
  - Arbol_dec: El archivo proporciona la estructura y funcionalidad para trabajar con un árbol de palabras, incluyendo inserción, búsqueda, eliminación, y procesamiento de archivos para construir el árbol para encontrar palabras dado un sufijo o prefijo.

# Ejecución:
- Por consola se debe ejecutar usando un compilador de C++ el archivo "Consola.cpp". Posteriormente, cuando ya se ejecutó, se escribe el comando "ayuda", en el cual se explica adecuadamente cómo usar cada comando. Si se necesita más información sobre un comando dado, se puede dar el comando "ayuda (comando_cualquiera)" sin los paréntesis, sobre el cual se quiere más información.
- Se podria ejecutar usando compiladores online como "replit" si se sube todos los archivos de este proyecto incluyendo .cpp, .h y .txt. posterior a subir este documento se ejecuta en el boton de "Run" para replit o el boton de ejecucion de otros compiladores online de c++.

A continuación, dejaré un enlace del proyecto en Replit, que es donde principalmente se desarrolló este proyecto: https://replit.com/@SantiagoBarrer6/ProyectoScrable?v=1.
