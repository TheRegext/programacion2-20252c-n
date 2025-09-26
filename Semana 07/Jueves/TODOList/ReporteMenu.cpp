#include <iostream>
#include "ReporteMenu.h"
using namespace std;

ReporteMenu::ReporteMenu(){
  _cantidadOpciones = 2;
}
void ReporteMenu::mostrar(){
  int opcion;
  
  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}

void ReporteMenu::mostrarOpciones(){
  cout << "--- MENU REPORTES ---" << endl;
  cout << "1- PORCENTAJE DE REALIZACION "<<endl;
  cout << "2- PERSONAS SIN TAREAS EN EL MES"<<endl;
  
  cout << "0- Salir "<<endl;
}

int ReporteMenu::seleccionOpcion(){
  int opcion;
  mostrarOpciones();
  cout << "---------------" << endl;
  cout << "Opcion: ";
  cin >> opcion;
  
  while(opcion < 0 || opcion > _cantidadOpciones){
    cout << "Opcion incorrecta..."<<endl;
    cout << "Opcion: ";
    cin >> opcion;
  }
  return opcion;
}
void ReporteMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _reporteManager.porcentajeRealizacion();
  break;  
  case 2:
    _reporteManager.personasSinTareasEnElMes();
  break;  

  }
}
