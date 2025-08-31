#include "Incrementador.h"

Incrementador::Incrementador(){
  _valor = 0;
  _valorIncremento = 1;
  _cantidadIncrementos = 0;
}

Incrementador::Incrementador(int valorInicial, int valorIncremento){
  _valor = valorInicial;
  
  /// Operadores ternarios
  _valorIncremento = (valorIncremento > 0) ? valorIncremento : 1;
  /*
  if(valorIncremento > 0){
    _valorIncremento = valorIncremento;
  }
  else{
    _valorIncremento = 1;
  }
  */
  _cantidadIncrementos = 0;
}

void Incrementador::incrementar(){
  _valor += _valorIncremento;
  _cantidadIncrementos++;
}

int Incrementador::getValor(){
  return _valor;
}

int Incrementador::getCantidadIncremento(){
  return _cantidadIncrementos;
}
