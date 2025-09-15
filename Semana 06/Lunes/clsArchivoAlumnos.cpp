#include <iostream>
#include <cstring>
#include "clsArchivoAlumnos.h"

using namespace std;

ArchivoAlumnos::ArchivoAlumnos(const char *n){
    strcpy(nombre, n);
}
int ArchivoAlumnos::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);///PERMITE DESPLAZAR EL CURSOR A CUALQUIER PARTE DEL ARCHIVO
    int bytes = ftell(p);///NOS DEVUELVE LA CANTIDAD DE BYTES QUE ME DESPLACE EN EL ARCHIVO
    fclose(p);
    return bytes/sizeof(Alumno);
}
Alumno ArchivoAlumnos::leerRegistro(int pos){///RECIBO UN 3
    FILE *p;
    p = fopen(nombre, "rb");
    Alumno obj;
    if(p == nullptr){
        obj.setLegajo(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    obj.setLegajo(-2);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
bool ArchivoAlumnos::grabarRegistro(Alumno obj){
    FILE *p;
    p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
/**
El método buscarRegistro recibe el legajo de un alumno, lo busca en el archivo y devuelve la
posición del mismo. En caso de no encontrarlo, devuelve -1.
*/
int ArchivoAlumnos::buscarRegistro(int leg){
    int cantReg = contarRegistros();
    Alumno obj;
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getLegajo() == leg){
            return i;
        }
    }
    return -1;
}
void ArchivoAlumnos::listarRegistros(){
    int cantReg = contarRegistros();
    Alumno obj;
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
}

bool ArchivoAlumnos::modificarRegistro(Alumno obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
