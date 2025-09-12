#pragma once
#include "TareaArchivo.h"

class TareaManager
{
  public:
    TareaManager();
    void cargarTarea();
    void listarTareas();
    
  protected:
    void mostrarTarea(Tarea tarea);
    
  private:
    TareaArchivo _repo;
};
