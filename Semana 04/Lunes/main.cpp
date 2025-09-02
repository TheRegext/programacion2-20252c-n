#include <iostream>
#include <cstring>
#include "clsMateria.h"
#include "clsFecha.h"
#include "clsAlumno.h"

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

/**
AGREGARLE A LA CLASE Alumno UNA PROPIEDAD PARA ALMACENAR EL DOMICILIO DEL MISMO.
PENSAR QUE VALORES CORRESPONDERIA ALMACENAR PARA DICHA PROPIEDAD.
*/

int main(){
    Alumno obj;
    obj.Mostrar();
    obj.Cargar();
    obj.Mostrar();
    return 0;
    Materia vecMateria[20];
    Materia pepito;
    pepito.Cargar();
    cout<<"SOY EL CONTENIDO DE PEPITO: "<<endl;
    pepito.Mostrar();
    cargarMaterias(vecMateria, 5);
    cout<<"======================"<<endl;
    cout<<"SOY EL CONTENIDO DEL VECTOR DE MATERIAS: "<<endl;
    mostrarMaterias(vecMateria,20);
    return 0;
}
