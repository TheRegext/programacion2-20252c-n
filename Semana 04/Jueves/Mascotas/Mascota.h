#pragma once
#include <string>
#include "Animal.h"

class Mascota: public Animal
{
public:
  Mascota(std::string nombre, int edad);
  void setNombre(std::string nombre);
  std::string getNombre();
  
private:
  std::string _nombre;
};
