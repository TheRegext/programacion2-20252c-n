#pragma once
#include <string>
#include "Mascota.h"

class AB{
public:
  AB(int n){}
};


class Perro: public Mascota{
public:
  Perro(std::string nombre, int edad);
  void ladrar();
private:
  AB _ab;
};
