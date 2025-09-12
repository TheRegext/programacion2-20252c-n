#pragma once
#include <string>
#include "Tarea.h"

class TareaArchivo
{
  public:
    TareaArchivo(std::string nombreArchivo = "tareas.dat");
    bool guardar(Tarea registro);
    Tarea leer(int pos);
    int getCantidadRegistros();
    int getNuevoID();

  private:
    std::string _nombreArchivo;
};


