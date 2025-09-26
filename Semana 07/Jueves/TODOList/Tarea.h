#pragma once
#include "Fecha.h"

class Tarea
{
  public:
    Tarea();
    Tarea(int id, std::string descripcion, Fecha fecha, int idPersonal, bool completado);
    
    void setID(int id);
    int getID();
    
    void setDescripcion(std::string descripcion);
    std::string getDescripcion();
    
    void setFecha(Fecha fecha);
    Fecha getFecha();
    
    void setCompletado(bool completado);
    bool getCompletado();
    
    void setEliminado(bool eliminado);
    bool getEliminado();
    
    void setIDPersonal(int idPersonal);
    int getIDPersonal();
    
    std::string toString();

  private:
    int _id;
    Fecha _fecha;
    bool _completado;
    /// std::string _descripcion; /// very mal!
    char _descripcion[300];
    bool _eliminado;
    int _IDPersonal;
};
