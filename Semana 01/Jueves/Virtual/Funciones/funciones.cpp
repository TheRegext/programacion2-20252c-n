#include <iostream>
#include "funciones.h"
using namespace std;

void linea (int cantidad, char simbolo){
  for(int i=0; i<cantidad; i++){
    cout << simbolo;
  }
  cout << endl;
}


int pedirNumero(string mensaje){
  int n;
  cout << mensaje;
  cin >> n;
  
  return n;  
}


void mostrarRecaudacion(bool huboVentaMes[12], float recaudacionDiaria[12][31]){
  
  for(int mes=0; mes < 12; mes++)
  {
    if(huboVentaMes[mes] == true){
      cout << "Mes #" << mes + 1 << endl;
      for(int dia=0; dia<31; dia++)
      {
        if(recaudacionDiaria[mes][dia] != 0)
        {
          cout << "Dia #" << dia+1 << ": $" << recaudacionDiaria[mes][dia] << endl;
        }
      }
      cout << endl;
    }
  }

}

