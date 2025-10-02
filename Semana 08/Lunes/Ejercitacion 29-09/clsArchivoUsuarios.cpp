#include <iostream>
#include <cstring>
#include "clsArchivoUsuarios.h"

using namespace std;

ArchivoUsuarios::ArchivoUsuarios(const char *n){
    strcpy(nombre, n);
}
int ArchivoUsuarios::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    Usuario obj;
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p)){
        cont++;
    }
    fclose(p);
    return cont;
}
int ArchivoUsuarios::buscarRegistro(int id){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    Usuario obj;
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
Usuario ArchivoUsuarios::leerRegistro(int pos){
    FILE *p = fopen(nombre, "rb");
    Usuario obj;
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
bool ArchivoUsuarios::grabarRegistro(Usuario obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoUsuarios::listar(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p == nullptr){
        return;
    }
    Usuario obj;
    while(fread(&obj, sizeof obj, 1, p)){
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    fclose(p);
}
