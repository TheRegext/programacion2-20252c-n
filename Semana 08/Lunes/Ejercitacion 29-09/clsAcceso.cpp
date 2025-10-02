#include <iostream>
#include <cstring>
#include "clsAcceso.h"

using namespace std;

int Acceso::getId(){
    return id;
}
int Acceso::getIdUsuario(){
    return idUsuario;
}
int Acceso::getIdJuego(){
    return idJuego;
}
Fecha Acceso::getFechaAcceso(){
    return fechaAcceso;
}
int Acceso::getTiempoAcceso(){
    return tiempoAcceso;
}
void Acceso::setId(int i){
    id=i;
}
void Acceso::Cargar(int i){
    if(i==-1){
        cout<<"INGRESE EL ID: ";
        cin>>id;
    }else{
        id=i;
        cout<<"SE ASIGNO EL ID: "<<id<<endl;
    }
    cout<<"INGRESE EL ID DEL USUARIO: ";
    cin>>idUsuario;
    cout<<"INGRESE EL ID DEL JUEGO: ";
    cin>>idJuego;
    cout<<"INGRESE LA FECHA DE ACCESO: ";
    fechaAcceso.Cargar();
    cout<<"INGRESE EL TIEMPO JUGADO: ";
    cin>>tiempoAcceso;
}
void Acceso::Mostrar(){
    cout<<"ID: "<<id<<endl;
    cout<<"ID DEL USUARIO: "<<idUsuario<<endl;
    cout<<"ID DEL JUEGO: "<<idJuego<<endl;
    cout<<"FECHA DE ACCESO: ";
    fechaAcceso.Mostrar();
    cout<<"INGRESE EL TIEMPO JUGADO: "<<tiempoAcceso<<endl;
}
