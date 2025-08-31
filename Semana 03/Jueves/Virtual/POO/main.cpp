#include <iostream>
#include "Incrementador.h"
using namespace std;

/****
  Una forma de resolver un problema a travez de objetos
  Paradigma de Programacion Orientada a objetos
    Adaptando el lenguaje de programacion para solucionar el problema
  
  Paradigma de programacion estructurada
    Adaptar la solucion al lenguaje de programacion
    
  Que es un objeto?
  La abstraccion de un objeto del mundo real, quedandonos con lo esencial para
  la solucion de mi problema
  
  Que es un objeto del mundo real?
  Toda entidad real o inmaginaria, tangible o intangible
  
  Como esta compuesto un objeto?
  Estados        : valores que tienen sus atributos (memoria)
  Comportamiento : las acciones que puede realizar el objeto (metodos)
  Identidad      : nombre del objeto
  
  Encapsulamiento
  Esconder el funcionamiento interno, exponer una interface
  
  /// Esquema de resolucion de problemas
  Identificar el problema
  Identificar los objetos
  Identificar de que manera se van a comunicar esos objetos
  Clasificar los objetos --- Clases
  Generalizar las clases --- Herencia
  
  class NombreClase{
    private:
    public:
  }
  
  
  Incrementador
  private:
    Valor Inicial
    Valor Incremento
    Cantidad Incrementos
    
  public:  
    Incrementador(valorInicial, valorIncremento)
    Incrementar();
    getValor();
    getCantidadIncremento();
  
*/

int main()
{
    Incrementador in(0, 50), in2(-10, -1), in3;
    
    in.incrementar();
    in.incrementar();
    
    cout << "Valor: " << in.getValor() << endl;
    cout << "Cantidad: " << in.getCantidadIncremento() << endl;
    
    in2.incrementar();
    in2.incrementar();
    in2.incrementar();
    
    cout << "Valor: " << in2.getValor() << endl;
    cout << "Cantidad: " << in2.getCantidadIncremento() << endl;
    
    in3.incrementar();
    in3.incrementar();
    
    cout << "Valor: " << in3.getValor() << endl;
    cout << "Cantidad: " << in3.getCantidadIncremento() << endl;
    return 0;
}







