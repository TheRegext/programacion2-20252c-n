#pragma once
class Incrementador{
  private:
    int _valor;
    int _valorIncremento;
    int _cantidadIncrementos;
    
  public:  
    /// CONSTRUCTOR
    Incrementador();
    Incrementador(int valorInicial, int valorIncremento);
    
    void incrementar();
    int getValor();
    int getCantidadIncremento();
};
