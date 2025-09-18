#include <iostream>
#include <string>
#include "Tarea.h"
#include "TareaManager.h"
using namespace std;

std::string cargarCadena(){
  std::string texto;
  if(std::cin.peek() == '\n'){
    std::cin.ignore();
  }
  std::getline(std::cin, texto);
  return texto;
}

TareaManager::TareaManager(){

}

void TareaManager::cargarTarea(){
  
  int id, duracionMinutos;
  bool finalizada;
  string descripcion;
  
  id = _repo.getNuevoID();
  cout << "Tarea #" << id << endl;
  
  cout << "Ingrese la descripcion de la tarea: ";
  descripcion = cargarCadena();
  
  cout << "Estado (1=s¡, 0=no): ";
  cin >> finalizada;
  
  Tarea tarea(id, descripcion, Fecha(11,9,2025), finalizada);
  
  if (_repo.guardar(tarea))
  {
    cout << "Tarea guardada exitosamente." << endl;
  }
  else
  {
    cout << "Error al guardar la tarea." << endl;
  }

}
void TareaManager::listarTareas(){
  int cantidad = _repo.getCantidadRegistros();
  
  for (int i = 0; i < cantidad; i++)
  {
    Tarea tarea = _repo.leer(i);
    mostrarTarea(tarea);
    cout << "------------------------" << endl;
  }
}

void TareaManager::mostrarTarea(Tarea tarea){
  cout << "ID: " << tarea.getID() << endl;
  cout << "Descripcion: " << tarea.getDescripcion() << endl;
  cout << "Fecha: " << tarea.getFecha().toString() << endl;
  cout << "Finalizada: " << (tarea.getCompletado() ? "S¡" : "No") << endl;
}
