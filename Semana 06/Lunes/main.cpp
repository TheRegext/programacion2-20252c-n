#include <iostream>
#include <cstring>
#include "clsMateria.h"
#include "clsFecha.h"
#include "clsAlumno.h"
#include "clsArchivoAlumnos.h"

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

/**
LA MODIFICACION CONSISTE EN SOLICITAR QUE REGISTRO DESEA MODIFICARSE (USANDO SU CAMPO CLAVE),
LEER ESE REGISTRO DEL ARCHIVO (SI ES QUE EXISTE), SOLICITAR LA INFORMACION NUEVA PARA EL
REGISTRO, MODIFICAR LA INFORMACION DEL REGISTRO LEIDO Y VOLVER A ESCRIBIRLO EN LA POSICION
QUE OCUPA EN EL ARCHIVO.
*/

/**
LA ELIMINACION TIENE DOS TIPOS:
-BAJA FISICA:
    CONSISTE EN LA ELIMINACION DE LA INFORMACION DEL REGISTRO EN EL ARCHIVO. NO QUEDA NADA
    DE ESE REGISTRO.
-BAJA LOGICA:
    CONSISTE EN EL CAMBIO DE ESTADO DE UNA PROPIEDAD (NORMALMENTE bool), DEL REGISTRO A
    ELIMINAR. EL SISTEMA DEBE IGNORAR A LOS REGISTROS QUE TENGAN EL CAMPO ESTADO EN "false".
*/

void agregarAlumno();
bool grabarRegistro(Alumno obj);
void listarAlumnos();
void agregarMateria();
bool grabarRegistro(Materia obj);
void listarMaterias();
void buscarAlumno();
void modificarAlumno();
void bajaLogicaAlumno();

//bool grabarRegistro(AlumnoNueva obj){
//    FILE *p;
//    p = fopen("Alumnos.nueva", "ab");
//    if(p == nullptr){
//        return false;
//    }
//    bool escribio = fwrite(&obj, sizeof obj, 1, p);
//    fclose(p);
//    return escribio;
//}
//
//void recrearArchivoAlumnos(){
//    ArchivoAlumnos arc;
//    Alumno obj;
//    AlumnoNueva aux;
//    int cantReg = arc.contarRegistros();
//    for(int i=0; i<cantReg; i++){
//        obj = arc.leerRegistro(i);
//        aux.setLegajo(obj.getLegajo());
//        aux.setNombre(obj.getNombre());
//        aux.setApellido(obj.getApellido());
//        aux.setDni(obj.getDni());
//        aux.setTelefono(obj.getTelefono());
//        aux.setFechaNacimiento(obj.getFechaNacimiento());
//        aux.setDomicilio(obj.getDomicilio());
//        aux.setEstado(true);
//        grabarRegistro(aux);
//    }
//}

int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - AGREGAR UN ALUMNO"<<endl;
        cout<<"2 - LISTAR LOS ALUMNOS"<<endl;
        cout<<"3 - BUSCAR ALUMNO POR LEGAJO"<<endl;
        cout<<"4 - MODIFICAR TELEFONO DEL ALUMNO"<<endl;
        cout<<"5 - DAR DE BAJA LOGICA A UN ALUMNO"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"======================"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarAlumno();
                //agregarMateria();
                break;
            case 2:
                listarAlumnos();
                //listarMaterias();
                break;
            case 3:
                buscarAlumno();
                break;
            case 4:
                modificarAlumno();
                break;
            case 5:
                bajaLogicaAlumno();
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

void bajaLogicaAlumno(){
    cout<<"INGRESE EL LEGAJO DEL ALUMNO A DAR DE BAJA: ";
    int legajo;
    cin>>legajo;
    ArchivoAlumnos arc;
    int pos = arc.buscarRegistro(legajo);
    if(pos < 0){
        cout<<"NO EXISTE EL LEGAJO EN EL ARCHIVO"<<endl;
        return;
    }
    Alumno obj;
    obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}

void modificarAlumno(){
    cout<<"INGRESE EL LEGAJO DEL ALUMNO A MODIFICAR: ";
    int legajo;
    cin>>legajo;
    ArchivoAlumnos arc;
    int pos = arc.buscarRegistro(legajo);
    if(pos < 0){
        cout<<"EL LEGAJO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Alumno obj;
    obj = arc.leerRegistro(pos);
    char telefono[15];
    cout<<"INGRESE EL NUEVO NUMERO DE TELEFONO: ";
    cin>>telefono;
    obj.setTelefono(telefono);
    arc.modificarRegistro(obj, pos);
    /**
    -PEDIR LEGAJO.
    -PEDIR TELEFONO NUEVO.
    -MODIFICAR EL REGISTRO EXISTENTE.
        -CARGAR EN MEMORIA EL REGISTRO EXISTENTE.
        -MODIFICAR LA INFORMACION DE ESE REGISTRO (SOLO LO QUE ME INTERESA CAMBIAR).
        -SOBREESCRIBIR EL REGISTRO ORIGINAL EN MI ARCHIVO.
    */
}

void buscarAlumno(){
    cout<<"INGRESE EL LEGAJO A BUSCAR: ";
    int legajo;
    cin>>legajo;
    ArchivoAlumnos arc;
    int pos = arc.buscarRegistro(legajo);
    if(pos < 0){
        cout<<"EL LEGAJO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Alumno obj;
    obj = arc.leerRegistro(pos);
    obj.Mostrar();
}

void agregarAlumno(){
    Alumno obj;
    int legajo;
    cout<<"INGRESE EL LEGAJO: ";
    cin>>legajo;
    ArchivoAlumnos arc;
    int pos = arc.buscarRegistro(legajo);
    if(pos >= 0){
        cout<<"EL LEGAJO INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(legajo);
    arc.grabarRegistro(obj);
}

void agregarMateria(){
    Materia obj;
    obj.Cargar();
    grabarRegistro(obj);
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
    ArchivoAlumnos arc;
    arc.listarRegistros();
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
