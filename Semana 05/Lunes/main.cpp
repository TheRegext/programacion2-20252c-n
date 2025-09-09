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

/**
-HACER UNA FUNCION QUE ME PERTIMA AGREGAR UN REGISTRO DE ALUMNO EN MI ARCHIVO.
    -HACER TODAS LAS FUNCIONES QUE CONSIDERE NECESARIAS.
-HACER UNA FUNCION QUE ME LISTE TODOS LOS REGISTROS DE MI ARCHIVO.
-HACER UN MENU CON LAS SIGUIENTES OPCIONES:
    -AGREGAR UN ALUMNO AL ARCHIVO.
    -LISTAR TODOS LOS ALUMNOS.
*/

void agregarAlumno();
bool grabarRegistro(Alumno obj);
void listarAlumnos();
void agregarMateria();
bool grabarRegistro(Materia obj);
void listarMaterias();

int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - AGREGAR UN ALUMNO"<<endl;
        cout<<"2 - LISTAR LOS ALUMNOS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"======================"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                //agregarAlumno();
                agregarMateria();
                break;
            case 2:
                //listarAlumnos();
                listarMaterias();
                break;
            case 0:
                return 0;
        }
        system("pause");
    }
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

void agregarAlumno(){
    Alumno obj;
    obj.Cargar();
    grabarRegistro(obj);
}

void agregarMateria(){
    Materia obj;
    obj.Cargar();
    grabarRegistro(obj);
}

bool grabarRegistro(Alumno obj){
    FILE *p;
    p = fopen("Alumnos.dat", "ab");
    /**
        rb: abre un archivo en modo de lectura. NO crea archivos.
        ab: abre un archivo en modo de escritura. Si no existe el archivo, lo crea.
        wb: abre un archivo en modo de escritura. SIEMPRE crea un archivo vacío.
    */
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    /**
    COPIA LA INFORMACION QUE ESTA EN MI OBJETO EN LA MEMORIA RAM Y LA LLEVA AL ARCHIVO.
    PARAMETROS fwrite:
    -LA DIRECCION DE MEMORIA (RAM) DONDE ESTA LA INFORMACION QUE QUIERO GRABAR EN MI ARCHIVO.
    -LA CANTIDAD DE BYTES DE MI REGISTRO.
    -LA CANTIDAD DE REGISTROS QUE QUIERO GUARDAR EN MI ARCHIVO.
    -EL VINCULO ENTRE MI PROGRAMA Y EL ARCHIVO (puntero FILE sobre el que hice el fopen).
    */
    fclose(p);
    return escribio;
}

bool grabarRegistro(Materia obj){
    FILE *p;
    p = fopen("Materias.dat", "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

void listarAlumnos(){
    FILE *p;
    p = fopen("Alumnos.dat", "rb");
    if(p == nullptr){
        return;
    }
    Alumno obj;
    while(fread(&obj, sizeof obj, 1, p) == 1){
    /**
    EL fread DESPLAZA UN CURSOR A MEDIDA QUE VA LEYENDO. UNA VEZ QUE LLEGA AL END OF FILE
    (eof), YA NO PUEDE SEGUIR LEYENDO.
    EL fread LEE INFORMACION DE MI ARCHIVO Y LA CARGA EN MEMORIA RAM (EN UN OBJETO DEL
    TIPO QUE SEA MI REGISTRO). DEVUELVE LA CANTIDAD DE REGISTROS QUE PUDO LEER CORRECTAMENTE.
    PARAMETROS fread:
    -DIRECCION DE MEMORIA (RAM) DONDE COPIAR LA INFORMACION DESDE EL ARCHIVO (DISCO).
    -CANTIDAD DE BYTES QUE TIENE UN REGISTRO.
    -CANTIDAD DE REGISTROS QUE QUIERO LEER.
    -VINCULO ENTRE MI PROGRAMA Y EL ARCHIVO (puntero FILE sobre el que hice el fopen).
    */
        obj.Mostrar();
        cout<<"================="<<endl;
    }
    fclose(p);
}

void listarMaterias(){
    FILE *p;
    p = fopen("Materias.dat", "rb");
    if(p == nullptr){
        return;
    }
    Materia obj;
    while(fread(&obj, sizeof obj, 1, p) == 1){
        obj.Mostrar();
        cout<<"================="<<endl;
    }
    fclose(p);
}
