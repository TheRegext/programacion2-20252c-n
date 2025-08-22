#include <iostream>
#include <ctime>
using namespace std;

void ejercicio01()
{
  /***
  Se desea cargar 1.000 n£meros aleatorios enteros entre 1 y 100.000 y determinar:
    Cu l es el n£mero m s alto generado.
    Cu ntas veces se repiti¢ ese n£mero en el conjunto.

  ¨Qu‚ pasa si se quiere que se generen 1.000.000 de n£meros?
  */
 
  srand(time(0));
  const int CANTIDAD = 1000000;
  int *vec;

  vec = new int[CANTIDAD];

  for(int i=0; i<CANTIDAD; i++)
  {
    vec[i] = rand() % 100000 + 1;
  }

  int iMax = 0;
  for(int i=1; i<CANTIDAD; i++)
  {
    if(vec[i]>vec[iMax])
    {
      iMax = i;
    }
  }

  cout << "El numero mas grande es: " << vec[iMax] << endl;

  int cant=0;
  for(int i=1; i<CANTIDAD; i++)
  {
    if(vec[i] == vec[iMax])
    {
      cant++;
    }
  }

  cout << "Se repite " << cant << " veces." << endl;
  
  cout << "Cantidad: " << sizeof (int) * CANTIDAD << endl;

  delete [] vec;
}

int ejercicio02(){
  /**
  Un profesor desea cargar las notas de los alumnos de su curso y 
  quiere saber cu ntos de sus estudiantes obtuvieron una calificaci¢n
  mayor que el promedio general.
  
  El programa debe solicitar al usuario la cantidad de alumnos y 
  debe permitir cargar una calificaci¢n por cada uno de ellos.
  */
  
  int cantidadAlumno, sumaTodos, *notas;
  float promedio;
  
  cout << "Ingrese la cantidad de alumnos: ";
  cin >> cantidadAlumno;
  
  notas = new int[cantidadAlumno];
  
  if(notas == nullptr){
    cout << "No hay suficiente memoria "<<endl; 
    exit(1000);
  }
  
  for(int i=0; i<cantidadAlumno; i++){
    cout << "Ingrese nota del alumno #" << i+1 << ": ";
    cin >> notas[i];
  }
  
  sumaTodos = 0;
  
  for(int i=0; i<cantidadAlumno; i++){
    sumaTodos += notas[i];
  }
  
  promedio = (float)sumaTodos/cantidadAlumno;
  
  for(int i=0; i<cantidadAlumno; i++){
    if(notas[i]>promedio){
      cout << "El alumno #" << i+1 << " tiene mas que el promedio" << endl;    
    }
  }
  
  delete [] notas;

  return 0;
}

/***
Se est  llevando a cabo un evento donde es necesario registrar 
la asistencia de los participantes. Para ello, se te pide desarrollar un
 programa para almacenar la informaci¢n de asistencia.
 
El sistema debe ofrecer el siguiente men£:
- Crear asistentes: Solicita al usuario la cantidad total de asistentes esperados.
- Marcar asistencia: permite ingresar el n£mero de asistente (del 1 al N)
     y lo marca como asisti¢.
- Mostrar estado de asistencia: muestra la lista de asistentes, 
    indicando por cada uno si asisti¢ o no. El n£mero de asistente 
    debe mostrarse junto al estado:
      Ejemplo:
       Asistente 1: Asisti¢
       Asistente 2: No asisti¢
- Salir: finaliza el programa. 

*/

bool * crearAsistentes(int &cantidad){
  bool * asistentes;
  cout << "Ingrese la cantidad de asistentes: ";
  cin >> cantidad;
  
  asistentes = new bool[cantidad]{};
  
  if(asistentes == nullptr){
    cout << "No hay memoria suficiente..." << endl;
    exit(-1000);  
  }
  
  return asistentes;
}

void marcarAsistente(bool asistentes[], int cantidadAsistentes){
  int nAsistente;
  cout << "Ingrese numero de asistente: ";
  cin >> nAsistente;
  
  if(nAsistente <= cantidadAsistentes && cantidadAsistentes >= 1){
    asistentes[nAsistente-1] = true;
  }
  else{
    cout << "Asistente incorrecto!" << endl;  
  }
}

void mostrarAsistentes(bool asistentes[], int cantidadAsistentes){
  for(int i=0; i<cantidadAsistentes; i++){
    if(asistentes[i]){
      cout << "Asistente #" << i + 1 << ": Asistio" << endl;    
    }
    else{
      cout << "Asistente #" << i + 1 << ": No Asistio" << endl;    
    }
  }
}

int main(){
  
  int opcion, cantidadAsistentes;
  bool *asistentes = nullptr;
  
  
  do{
    cout << "1- Cargar" << endl;
    cout << "2- Marcar" << endl;
    cout << "3- Listar" << endl;
    cout << "0- Salir" << endl;
    
    cout << "Opcion: ";
    cin >> opcion;
    
    switch(opcion){
      case 1:
          /// liberar lo que tenia antes...
          if(asistentes != nullptr){
            delete [] asistentes;
          }
          
          asistentes = crearAsistentes(cantidadAsistentes);
        break;
      case 2:
        if(asistentes != nullptr){
          marcarAsistente(asistentes, cantidadAsistentes);
        }
        else{
          cout << "No hay asistentes..." << endl;        
        }
        
        break;
      case 3:
        mostrarAsistentes(asistentes, cantidadAsistentes);
        break;
      
      case 0:
        cout << "Gracias por usar mi APP..." << endl;
        if(asistentes != nullptr){
          delete [] asistentes;
        }
        break;
    }
  }while(opcion != 0);
  
  return 0;
}





