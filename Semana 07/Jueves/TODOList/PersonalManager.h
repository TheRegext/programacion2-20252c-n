#pragma once
#include "PersonalArchivo.h"


class PersonalManager
{
  public:
    PersonalManager();
    
    void cargar();
    void mostrar();
    void eliminar();
    void actualizar();
    
  protected:
    void mostrarLista(Personal personal);
  private:
    PersonalArchivo _repo;
};
