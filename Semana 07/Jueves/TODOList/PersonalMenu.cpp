#include <iostream>
#include "PersonalMenu.h"
using namespace std;

PersonalMenu::PersonalMenu(){
  _cantidadOpciones = 4;
}

void PersonalMenu::mostrar(){
  int opcion;
  
  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}


void PersonalMenu::mostrarOpciones(){
  cout << "--- MENU PERSONAL ---" << endl;
  cout << "1 - CREAR PERSONAL" << endl;
  cout << "2 - MOSTRAR PERSONAL" << endl;
  cout << "3 - ELEMINAR PERSONAL " << endl;
  cout << "4 - MODIFICAR PERSONAL " << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void PersonalMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _personalManager.cargar();
  break;
  case 2:
    _personalManager.mostrar();
  break;
  case 3:
    
  break;
  case 4:
    
  break;
  }
}


int PersonalMenu::seleccionOpcion(){
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
