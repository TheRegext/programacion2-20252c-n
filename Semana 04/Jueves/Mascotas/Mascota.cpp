#include "Mascota.h"

using namespace std;

Mascota::Mascota(std::string nombre, int edad)
:Animal::Animal(edad){
  setNombre(nombre);
}

void Mascota::setNombre(string nombre){
  _nombre = nombre; 
}

string Mascota::getNombre(){
  return _nombre;
}
