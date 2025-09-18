#include <iostream>
#include <cstring>
#include "clsArchivoCiudades.h"

using namespace std;

ArchivoCiudades::ArchivoCiudades(const char *n){
    strcpy(nombre, n);
}
int ArchivoCiudades::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);///PERMITE DESPLAZAR EL CURSOR A CUALQUIER PARTE DEL ARCHIVO
    int bytes = ftell(p);///NOS DEVUELVE LA CANTIDAD DE BYTES QUE ME DESPLACE EN EL ARCHIVO
    fclose(p);
    return bytes/sizeof(Ciudad);
}
Ciudad ArchivoCiudades::leerRegistro(int pos){///RECIBO UN 3
    FILE *p;
    p = fopen(nombre, "rb");
    Ciudad obj;
    if(p == nullptr){
        obj.setID(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    obj.setID(-2);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
bool ArchivoCiudades::grabarRegistro(Ciudad obj){
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
El método buscarRegistro recibe el legajo de un Ciudad, lo busca en el archivo y devuelve la
posición del mismo. En caso de no encontrarlo, devuelve -1.
*/
int ArchivoCiudades::buscarRegistro(int leg){
    int cantReg = contarRegistros();
    Ciudad obj;
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getID() == leg){
            return i;
        }
    }
    return -1;
}
void ArchivoCiudades::listarRegistros(){
    int cantReg = contarRegistros();
    Ciudad obj;
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        obj.mostrar();
        cout<<endl;
    }
}

bool ArchivoCiudades::modificarRegistro(Ciudad obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
