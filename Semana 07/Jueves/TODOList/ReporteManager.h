#pragma once
#include "TareaArchivo.h"
#include "PersonalArchivo.h"
class ReporteManager
{
  public:
    void porcentajeRealizacion();
    void personasSinTareasEnElMes();
  protected:
    int cantidadTareasAsignadasEnElMesYAnio(int mes, int anio, int id);
  private:
    TareaArchivo _repoTareas;
    PersonalArchivo _repoPersonal;
};
