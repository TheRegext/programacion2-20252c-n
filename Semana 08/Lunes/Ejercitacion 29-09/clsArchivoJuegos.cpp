#include <iostream>
#include <cstring>
#include "clsArchivoJuegos.h"

using namespace std;

ArchivoJuegos::ArchivoJuegos(const char *n){
    strcpy(nombre, n);
}
int ArchivoJuegos::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    Juego obj;
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p)){
        cont++;
    }
    fclose(p);
    return cont;
}
int ArchivoJuegos::buscarRegistro(int id){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    Juego obj;
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
Juego ArchivoJuegos::leerRegistro(int pos){
    FILE *p = fopen(nombre, "rb");
    Juego obj;
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
bool ArchivoJuegos::grabarRegistro(Juego obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoJuegos::listar(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p == nullptr){
        return;
    }
    Juego obj;
    while(fread(&obj, sizeof obj, 1, p)){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(p);
}
