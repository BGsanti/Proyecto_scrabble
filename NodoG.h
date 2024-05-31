#ifndef NODOG
#define NODOG

#include <string>
#include <list>


class NodoG{
  public:
    NodoG();
    std::string getPalabra() const; // Agrega const aquí
    void setPalabra(std::string palabra);
  private:
    std::string palabra;
};

#endif // NODOG