#include <iostream>

using namespace std;

#include "Fecha.h"
#include "Libro.h"
#include "ArchivoLibro.h"
#include "funciones_globales.h"

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


bool bajaLibro(){
    ArchivoLibros archi;
    int _ISBN;
    cout<<"INGRESAR EL ISBN DEL LIBRO A BORRAR ";
    cin>>_ISBN;
    int pos=archi.buscarRegistro(_ISBN);
    if(pos==-1){
         cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
         return false;
    }
    if(pos==-2){
            cout<<"NO EXISTE UN REGISTRO CON ESE ISBN"<<endl;
            return false;
    }
    return archi.bajaLogica(pos);
}

bool modificarStock(){
    int _stock, _ISBN;
    ArchivoLibros archi;
    Libro reg;
    cout<<"INGRESAR EL ISBN DEL LIBRO A MODIFICAR ";
    cin>>_ISBN;
    int pos=archi.buscarRegistro(_ISBN);
    if(pos<0){
        return false;
    }
    reg=archi.leerRegistro(pos);
    cout<<"INGRESE EL LA CANTIDAD A AGREGAR EN EL STOCK ";
    cin>>_stock;
    reg.setStock(_stock+reg.getStock());
    return archi.modificarRegistro(reg, pos);




    return true;
}

bool listarLibros(){
    ArchivoLibros archi;
    if(archi.contarRegistros()==0)return false;
    archi.listarRegistros();
    return true;
}

bool altaLibro(){
    Libro reg;
    ArchivoLibros archi;
    reg.Cargar();///OJO!!! está sin validar
    if(archi.agregarRegistro(reg)>0) return true;
    return false;
}

