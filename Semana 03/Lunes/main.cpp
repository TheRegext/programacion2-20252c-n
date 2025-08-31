#include <iostream>
#include <cstring>
#include "clsMateria.h"

using namespace std;


void mostrarMaterias(Materia *v,  int tam){
    for(int i=0; i<tam; i++){
        v[i].Mostrar();
    }
}

void cargarMaterias(Materia *v, int tam){
    for(int i=0; i<tam; i++){
        v[i].Cargar();
    }
}
class Alumno{

};

int main(){
    Materia vecMateria[20];
    Materia pepito;
    Alumno pepita;
    pepito.Cargar();
    cout<<"SOY EL CONTENIDO DE PEPITO: "<<endl;
    pepito.Mostrar();
    cargarMaterias(vecMateria, 5);
    pepita=pepito;
    cout<<"======================"<<endl;
    cout<<"SOY EL CONTENIDO DEL VECTOR DE MATERIAS: "<<endl;
    mostrarMaterias(vecMateria,20);
    return 0;
}
