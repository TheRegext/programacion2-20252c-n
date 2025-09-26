#include <iostream>
#include <string>
#include "utils.h"
#include "Tarea.h"
#include "ReporteManager.h"
using namespace std;


void ReporteManager::porcentajeRealizacion(){
  int cantidadTareas, total;
  int cantidadRealizada, cantidadSinRealizar;
  Tarea *vTareas;
  
  cantidadTareas = _repoTareas.getCantidadRegistros();
  
  if(cantidadTareas == 0){
    cout << "No hay tareas cargadas" << endl;
    return;  
  }
  
  vTareas = new Tarea[cantidadTareas];
  
  if(vTareas == nullptr){
    cout << "No se puede asignar memoria..."<<endl;
    return;
  }
  
  _repoTareas.leerTodos(vTareas, cantidadTareas);
  
  cantidadRealizada = cantidadSinRealizar = 0;
  
  for(int i=0; i<cantidadTareas; i++){
    if(vTareas[i].getEliminado()){
      continue; /// se saltea la ejecucion y avanza a la siguiente iteracion del ciclo    
    }
      
    if(vTareas[i].getCompletado()){
      cantidadRealizada++;    
    }
    else{
      cantidadSinRealizar++;    
    }
  }
  
  total = cantidadRealizada + cantidadSinRealizar;
  if(total != 0){
    cout << "El porcentaje de tareas realizadas son: " << ((float)cantidadRealizada/total*100) << endl;
    cout << "El porcentaje de tareas no realizadas son: " << ((float)cantidadSinRealizar/total*100) << endl;
  }
  else{
    cout << "No hay tareas cargadas... " << endl;  
  }
  
  delete [] vTareas;
}

void ReporteManager::personasSinTareasEnElMes(){
  int mes, anio;
  int cantidadPersonal;
  
  cout << "Ingrese anio: ";
  cin >> anio;
  
  cout << "Ingrese mes: ";
  cin >> mes;
  
  cantidadPersonal = _repoPersonal.getCantidadRegistros();
  
  for(int i=0; i<cantidadPersonal; i++){
    Personal personal = _repoPersonal.leer(i);
    
    if(cantidadTareasAsignadasEnElMesYAnio(mes, anio, personal.getID()) == 0){
      cout << personal.getNombre() << endl;  
    }
  }
}

int ReporteManager::cantidadTareasAsignadasEnElMesYAnio(int mes, int anio, int id){
  int cantidad=0;
  
  int cantidadTareas = _repoTareas.getCantidadRegistros();
  
  for(int i=0; i<cantidadTareas; i++){
    Tarea tarea = _repoTareas.leer(i);
    
    if(!tarea.getEliminado()
       && tarea.getFecha().getMes() == mes 
       && tarea.getFecha().getAnio() == anio 
       && tarea.getIDPersonal() == id){
         cantidad++;
       }
  }
  
  return cantidad;
}



