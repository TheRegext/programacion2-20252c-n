#include <iostream>
#include <cstring>
#include "clsArchivoUsuarios.h"
#include "clsUsuario.h"
#include "clsArchivoJuegos.h"
#include "clsJuego.h"
#include "clsArchivoAccesos.h"
#include "clsAcceso.h"
#include "menus.h"

using namespace std;

/**
Sobre el sistema realizado se pide una serie de reportes. Los mismos
deben ser llamados desde una opción en el menú principal. Crear un submenú
para llamar a cada reporte.

-Informar la cantidad de usuarios de cada tipo.

-Informar el tipo de cuenta con mas cantidad de usuarios.

USUARIO:
-ID
-NOMBRE
-FECHA DE CREACION
-TIPO DE CUENTA

-Informar la cantidad de usuarios que hayan jugado al menos un juego
este año.

-Informar la categoría de juego con mas cantidad de juegos.

-Informar la cantidad total de minutos de acceso de cada juego.

-Listar los juegos sin accesos.

-Informar la cantidad de tiempo de acceso total que cada categoría de juego
tuvo este año.

-Listar los juegos que tengan una calificación (puntuación) mayor al promedio
entre todos los juegos.

-Crear un archivo nuevo con los usuarios que tengan juegos de categoría 3 con
el siguiente formato:
-ID de usuario, nombre y cantidad de juegos de categoría 3.
*/

void menuPrincipal(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - USUARIOS"<<endl;
        cout<<"2 - JUEGOS"<<endl;
        cout<<"3 - ACCESOS"<<endl;
        cout<<"4 - REPORTES"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuUsuarios();
                break;
            case 2:
                menuJuegos();
                break;
            case 3:
                menuAccesos();
                break;
            case 4:
                menuReportes();
                break;
            case 0:
                return;
        }
    }
}
void menuUsuarios(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU USUARIOS"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR USUARIO"<<endl;
        cout<<"2 - DAR DE BAJA USUARIO"<<endl;
        cout<<"3 - MODIFICAR USUARIO"<<endl;
        cout<<"4 - LISTAR USUARIOS"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarUsuario();
                break;
            case 2:
                bajaUsuario();
                break;
            case 3:
                modificarUsuario();
                break;
            case 4:
                listarUsuarios();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}
void menuJuegos(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU JUEGOS"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR JUEGO"<<endl;
        cout<<"2 - DAR DE BAJA JUEGO"<<endl;
        cout<<"3 - MODIFICAR JUEGO"<<endl;
        cout<<"4 - LISTAR JUEGOS"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarJuego();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                listarJuegos();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}
void menuAccesos(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU ACCESO"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR ACCESO"<<endl;
        cout<<"2 - DAR DE BAJA ACCESO"<<endl;
        cout<<"3 - MODIFICAR ACCESO"<<endl;
        cout<<"4 - LISTAR ACCESOS"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarAcceso();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return;
        }
        system("pause");
    }
}
void menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU REPORTES"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - CANTIDAD DE USUARIOS QUE JUGARON AL MENOS UN JUEGO ESTE AÑO"<<endl;
        cout<<"2 - CANTIDAD DE USUARIOS DE CADA TIPO"<<endl;
        cout<<"3 - "<<endl;
        cout<<"4 - "<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                punto1();
                break;
            case 2:
                punto2();
                break;
            case 3:
                punto3();
                break;
            case 4:
                break;
            case 0:
                return;
        }
        system("pause");
    }
}
void agregarUsuario(){
    ArchivoUsuarios arc;
    Usuario obj;
    int id;
    id = arc.contarRegistros() + 1;
    if(id == 0){
        id = 1;
    }
    obj.Cargar(id);
    arc.grabarRegistro(obj);
}

void bajaUsuario(){

}
void modificarUsuario(){

}
void listarUsuarios(){
    ArchivoUsuarios arc;
    arc.listar();
}
void agregarJuego(){
    ArchivoJuegos arc;
    Juego obj;
    int id;
    cout<<"INGRESE EL ID: ";
    cin>>id;
    int pos=arc.buscarRegistro(id);
    if(pos>=0){
        cout<<"YA EXISTE ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(id);
    arc.grabarRegistro(obj);
}
void agregarAcceso(){
    ArchivoAccesos arc;
    Acceso obj;
    int id = arc.contarRegistros();
    if(id == -1){
        id=0;
    }
    id++;
    obj.Cargar(id);
    arc.grabarRegistro(obj);
}
void listarJuegos(){
    ArchivoJuegos arc;
    arc.listar();
}
bool jugo2025(int id){
    ArchivoAccesos arc;
    Acceso obj;
    int cantReg = arc.contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = arc.leerRegistro(i);
        if(obj.getIdUsuario() == id and obj.getFechaAcceso().getAnio() == 2025){
            return true;
        }
    }
    return false;
}

void punto1(){
    ArchivoUsuarios arc;
    Usuario obj;
    int cont=0;
    int cantReg = arc.contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = arc.leerRegistro(i);
        if(jugo2025(obj.getId())){
            cont++;
        }
    }
    cout<<"LA CANTIDAD DE USUARIOS QUE JUGARON AL MENOS UN JUEGO EN 2025 ES: "<<cont<<endl;
}

void punto2(){
    ArchivoUsuarios arc;
    Usuario obj;
    int cantReg = arc.contarRegistros();
    int vCont[4]={};
    for(int i=0; i<cantReg; i++){
        obj = arc.leerRegistro(i);
        vCont[obj.getTipoCuenta() - 1]++;
    }
    for(int i=0; i<4; i++){
        cout<<"LA CANTIDAD DE USUARIOS CON TIPO DE CUENTA "<<i+1<<" ES: "<<vCont[i]<<endl;
    }
}

int buscarMayor(int *vCont, int tam){
    int posMax = 0;
    for(int i=1; i<tam; i++){
        if(vCont[i] > vCont[posMax]){
            posMax = i;
        }
    }
    return posMax;
}

void punto3(){
    ArchivoUsuarios arc;
    Usuario obj;
    int cantReg = arc.contarRegistros();
    int vCont[4]={};
    for(int i=0; i<cantReg; i++){
        obj = arc.leerRegistro(i);
        vCont[obj.getTipoCuenta() - 1]++;
    }
    int posMax = buscarMayor(vCont, 4);
    cout<<"EL TIPO DE CUENTA CON MAS USUARIOS ES: "<<posMax + 1<<endl;
}
