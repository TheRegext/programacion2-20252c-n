#include <iostream>
#include <string>
#include "utils.h"
#include "Tarea.h"
#include "TareaManager.h"
using namespace std;


TareaManager::TareaManager()
{

}

void TareaManager::cargarTarea()
{

  int id, duracionMinutos;
  bool finalizada;
  string descripcion;
  int idPersonal;

  id = _repo.getNuevoID();
  cout << "Tarea #" << id << endl;

  cout << "Ingrese la descripcion de la tarea: ";
  descripcion = cargarCadena();
  
  cout << "Ingrese id del personal (0 sin asignar): ";
  cin >> idPersonal;
  
  if(idPersonal != 0){
    int posPersonal = _repoPersonal.buscarID(idPersonal) ;
  
    if(posPersonal == -1){
      cout << "El id personal no existe..." << endl;
      return;  
    }
  
    cout << "El personal asignado es: " << _repoPersonal.leer(posPersonal).getNombre() << endl;
  }
  else{
    cout << "No hay personal asignado."<<endl;  
  }
    

  cout << "Estado (1=s¡, 0=no): ";
  cin >> finalizada;
  

  Tarea tarea(id, descripcion, Fecha(11,9,2025), idPersonal, finalizada);

  if (_repo.guardar(tarea))
  {
    cout << "Tarea guardada exitosamente." << endl;
  }
  else
  {
    cout << "Error al guardar la tarea." << endl;
  }

}
void TareaManager::listarTareas()
{
  int cantidad = _repo.getCantidadRegistros();

  for (int i = 0; i < cantidad; i++)
  {
    Tarea tarea = _repo.leer(i);
    mostrarTarea(tarea);
    cout << "------------------------" << endl;
  }
}

void TareaManager::mostrarTarea(Tarea tarea)
{
  cout << "ID: " << tarea.getID() << endl;
  cout << "Descripcion: " << tarea.getDescripcion() << endl;
  cout << "Fecha: " << tarea.getFecha().toString() << endl;
  cout << "Personal: ";
  
  if(tarea.getIDPersonal() == 0){
    cout << "Sin personal asignado.";  
  }
  else{
    int pos = _repoPersonal.buscarID(tarea.getIDPersonal());
    if(pos != -1){
      cout << _repoPersonal.leer(pos).getNombre();    
    }
    else{
      cout << "No se encuentra el id (#"<<tarea.getIDPersonal()<<")";
    }
  }
  
  cout << endl;
  cout << "Finalizada: " << (tarea.getCompletado() ? "S¡" : "No") << endl;
  cout << "Eliminado: " << (tarea.getEliminado() ? "S¡" : "No") << endl;
}


void TareaManager::marcarTarea()
{
  int id, pos;
  char completado;
  Tarea tarea;

  cout << "---- MARCAR TAREA ----" << endl;
  cout << "Ingrese id de la tarea: ";
  cin >> id;

  pos = _repo.buscarID(id);

  if(pos == -1)
  {
    cout << "La tarea no se encuentra en el archivo!" << endl;
    return ;
  }

  tarea = _repo.leer(pos);

  cout << "Informacion de la tarea: "<<endl;

  mostrarTarea(tarea);

  cout << endl << "Esta completa? S/N:";
  cin >> completado;

  if(completado == 's' || completado == 'S')
  {
    tarea.setCompletado(true);
  }
  else
  {
    tarea.setCompletado(false);
  }

  if(_repo.guardar(pos, tarea))
  {
    cout << "La tarea fue actualizada correctamente "<<endl;
  }
  else
  {
    cout << "Ocurrio un erro en la actualizacion de la tarea"  << endl;
  }
}

void TareaManager::eliminarTarea(){
  int id, pos;
  Tarea tarea;
  char eliminado;

  cout << "---- ELIMINAR TAREA ----" << endl;
  cout << "Ingrese id de la tarea: ";
  cin >> id;

  pos = _repo.buscarID(id);

  if(pos == -1)
  {
    cout << "La tarea no se encuentra en el archivo!" << endl;
    return ;
  }

  tarea = _repo.leer(pos);

  cout << "Informacion de la tarea: "<<endl;

  mostrarTarea(tarea);

  cout << endl << "Quiere eliminarla S/N:";
  cin >> eliminado;

  if(eliminado== 's' || eliminado == 'S')
  {
    if(_repo.eliminar(pos))
    {
      cout << "La tarea fue eliminada correctamente "<<endl;
    }
    else
    {
      cout << "Ocurrio un erro en la eliminacion de la tarea"  << endl;
    }
  }
}


void TareaManager::mostrarTareaOrdenada()
{
  int cantidad = _repo.getCantidadRegistros();
  Tarea *tareas;
  
  tareas = new Tarea[cantidad];
 
  _repo.leerTodos(tareas, cantidad);
  
  for(int i=0; i<cantidad-1; i++){
    bool intercambio = false;
    for(int j=0; j<cantidad - 1 - i; j++){
      if(tareas[j].getDescripcion() > tareas[j+1].getDescripcion()){
        Tarea aux = tareas[j];
        tareas[j] = tareas[j+1];
        tareas[j+1] = aux;
        intercambio = true;
      }
    }  
    
    if(!intercambio){
      break;    
    }
  }
  

  for (int i = 0; i < cantidad; i++)
  {
    mostrarTarea(tareas[i]);
    cout << "------------------------" << endl;
  }
  
  delete [] tareas;
}
