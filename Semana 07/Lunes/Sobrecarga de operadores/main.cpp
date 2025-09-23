#include <iostream>
#include <cstring>
#include "clsMateria.h"
#include "clsFecha.h"
#include "clsAlumno.h"
#include "clsArchivoAlumnos.h"

using namespace std;

void agregarAlumno();
bool grabarRegistro(Alumno obj);
void listarAlumnos();
void agregarMateria();
bool grabarRegistro(Materia obj);
void listarMaterias();
void buscarAlumno();
void modificarAlumno();
void bajaLogicaAlumno();
void buscarPorApellido();

bool grabarRegistro(AlumnoNueva obj){
    FILE *p;
    p = fopen("Alumnos.nueva", "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

void recrearArchivoAlumnos(){
    ArchivoAlumnos arc;
    Alumno obj;
    AlumnoNueva aux;
    int cantReg = arc.contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = arc.leerRegistro(i);
        aux = obj;
        aux.setEstado(true);
        grabarRegistro(aux);
    }
}

int main(){
    Alumno obj, obj2;
    Fecha fecha(3, 3, 1989);
    obj = "Otra cosa";
    if(obj != "Nombre"){
        cout<<"LOS NOMBRES SON DISTINTOS"<<endl;
    }else{
        cout<<"LOS NOMBRES SON IGUALES"<<endl;
    }
    obj.Mostrar();
    return 0;
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
        cout<<"6 - BUSCAR POR APELLIDO"<<endl;
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
            case 6:
                buscarPorApellido();
                break;
            case 0:
                return 0;
        }
        system("pause");
    }
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
/**
LA SOBRECARGA DE OPERADORES CONSISTE EN AGREGARLE A MI CLASE UNO O VARIOS METODOS QUE PERMITAN
UTILIZAR LOS OPERADORES CON UN OBJETO DE MI CLASE COMO OCURRE CON LOS TIPOS DE DATOS PRIMITIVOS

HACER UNA SOBRECARGA DE OPERADOR QUE COMPARE EL DNI DEL ALUMNO CON UNO QUE SE RECIBE COMO
PARAMETRO
*/
void buscarPorApellido(){
    cout<<"INGRESE EL APELLIDO: ";
    char apellido[30];
    cin.ignore();
    cin.getline(apellido, 30);
    ArchivoAlumnos arc;
    Alumno obj;
    int cantReg = arc.contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = arc.leerRegistro(i);
        if(obj == apellido and obj.getEstado() == true){
            obj.Mostrar();
        }
    }
}
