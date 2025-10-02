#include <iostream>
#include <cstring>
#include "clsArchivoAccesos.h"

using namespace std;

ArchivoAccesos::ArchivoAccesos(const char *n){
    strcpy(nombre, n);
}
int ArchivoAccesos::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    Acceso obj;
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p)){
        cont++;
    }
    fclose(p);
    return cont;
}
int ArchivoAccesos::buscarRegistro(int id){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    Acceso obj;
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p)){
        if(obj.getId() == id){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -2;
}
Acceso ArchivoAccesos::leerRegistro(int pos){
    FILE *p = fopen(nombre, "rb");
    Acceso obj;
    obj.setId(-1);
    if(p == nullptr){
        return obj;
    }
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p)){
        if(cont == pos){
            fclose(p);
            return obj;
        }
        cont++;
    }
    fclose(p);
    obj.setId(-2);
    return obj;
}
bool ArchivoAccesos::grabarRegistro(Acceso obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoAccesos::listar(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p == nullptr){
        return;
    }
    Acceso obj;
    while(fread(&obj, sizeof obj, 1, p)){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(p);
}
