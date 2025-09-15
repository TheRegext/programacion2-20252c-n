#include <iostream>
#include <cstring>
#include "clsArchivoPaises.h"

using namespace std;

ArchivoPaises::ArchivoPaises(const char *n){
    strcpy(nombre, n);
}
int ArchivoPaises::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);///PERMITE DESPLAZAR EL CURSOR A CUALQUIER PARTE DEL ARCHIVO
    int bytes = ftell(p);///NOS DEVUELVE LA CANTIDAD DE BYTES QUE ME DESPLACE EN EL ARCHIVO
    fclose(p);
    return bytes/sizeof(Pais);
}
Pais ArchivoPaises::leerRegistro(int pos){///RECIBO UN 3
    FILE *p;
    p = fopen(nombre, "rb");
    Pais obj;
    if(p == nullptr){
        obj.setCodigo("S/C");
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    obj.setCodigo("S/C");
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
bool ArchivoPaises::grabarRegistro(Pais obj){
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
El método buscarRegistro recibe el legajo de un Pais, lo busca en el archivo y devuelve la
posición del mismo. En caso de no encontrarlo, devuelve -1.
*/
int ArchivoPaises::buscarRegistro(const char *c){
    int cantReg = contarRegistros();
    Pais obj;
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(strcmp(obj.getCodigo(),c)==0){
            return i;
        }
    }
    return -1;
}
void ArchivoPaises::listarRegistros(){
    int cantReg = contarRegistros();
    Pais obj;
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        obj.mostrar();
        cout<<endl;
    }
}

bool ArchivoPaises::modificarRegistro(Pais obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
