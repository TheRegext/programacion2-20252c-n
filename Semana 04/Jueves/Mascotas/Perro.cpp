#include <iostream>
#include "Perro.h"

using namespace std;

Perro::Perro(std::string nombre, int edad)
: Mascota::Mascota(nombre, edad), _ab(1){ 
  /// llamar a los construcres padres
  /// inicializar los atributos
  /// llamar los contructores de las composiciones
  
  // Logica
}

void Perro::ladrar(){
  cout << "Woof" << endl;
  setEdad(getEdad()-1);
}
