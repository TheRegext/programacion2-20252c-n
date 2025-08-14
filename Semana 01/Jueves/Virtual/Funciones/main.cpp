#include <iostream>
#include "funciones.h"
using namespace std;

void mostrar(int n)
{
  cout << n << endl;
}

void mostrarR(int &n)
{
  cout << n << endl;
}

void mostrarD(int *n)
{
  cout << n << endl;
}

int sumar(int n, int m, int o)
{
  return n + m + o;
}

int sumar(int n, int m)
{
  return n + m;
}

float sumar(float n, float m)
{
  return n + m;
}

int main()
{
  /***
    un local realiza ventas durante todo el a¤o
    por cada venta se ingresa:
      numeroVenta
      dia
      mes
      monto

    el fin de la carga de datos se hace con un numero de venta igual a 0
    - Se pide mostrar para cada dia y mes, la recaudacion.
  */


  int numeroVenta, dia, mes;
  float monto;

  float recaudacionDiaria[12][31]= {};
  bool huboVentaMes[12] = {};

  cout << "Ingrese numero de venta: ";
  cin >> numeroVenta;

  while(numeroVenta != 0)
  {
    cout << "Ingrese mes: " ;
    cin >> mes;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese monto: ";
    cin >> monto;

    recaudacionDiaria[mes-1][dia-1] += monto;
    huboVentaMes[mes-1] = true;


    cout << "Ingrese numero de venta: ";
    cin >> numeroVenta;
  }


  mostrarRecaudacion(huboVentaMes, recaudacionDiaria);




  /*
  int vec[12]={1,2,3,5,6};

  for(int i=0; i<12; i++){
    cout << vec[i] << endl;
  }

  ////  matriz
  int mat[5][3]={
                  {3,5,6},
                  {1,1,1}
                };

  mat[4][2] = 15;

  for(int f=0; f<5; f++){
    for(int c=0; c<3; c++){
      cout << mat[f][c] <<  " ";
    }
    cout << endl;
  }
  */
  /*
    cout << "La suma es: " << sumar(2.5f, 5.5f) << endl;
    cout << "La suma es: " << sumar(2, 5) << endl;
    cout << "La suma es: " << sumar(2, 5, 5) << endl;
  */
  /*
  linea(40, '*');
  int legajo = pedirNumero("Ingrese Legajo: ");
  int numero= pedirNumero();
  int edad= pedirNumero("Ingrese edad: ");
  linea(10);
  cout << "El legajo es: " << legajo << endl;
  */
  return 0;
}
