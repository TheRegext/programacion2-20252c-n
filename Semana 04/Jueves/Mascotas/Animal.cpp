#include "Animal.h"

Animal::Animal()
:_edad(0){
  
}

Animal::Animal(int edad)
:Animal::Animal(){
  setEdad(edad);
}

int Animal::getEdad() { 
  return _edad; 
}

void Animal::setEdad(int edad) { 
  //// operador ternario
  _edad = edad >= 0 ? edad : 0;
}

