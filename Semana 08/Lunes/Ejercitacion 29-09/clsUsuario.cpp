#include <iostream>
#include <cstring>
#include "clsUsuario.h"
#include "cargarCadena.h"

using namespace std;

void Usuario::setId(int i){
    id = i;
}
void Usuario::setNombre(const char *n){
    strcpy(nombre, n);
}
void Usuario::setFechaCreacion(Fecha fC){
    fechaCreacion = fC;
}
int Usuario::getId(){
    return id;
}
const char *Usuario::getNombre(){
    return nombre;
}
Fecha Usuario::getFechaCreacion(){
    return fechaCreacion;
}
int Usuario::getTipoCuenta(){
    return tipoCuenta;
}
bool Usuario::getEstado(){
    return estado;
}
void Usuario::Cargar(int i){
    if(i==-1){
        cout<<"INGRESE EL ID: ";
        cin>>id;
    }else{
        id=i;
        cout<<"SE ASIGNO EL ID: "<<id<<endl;
    }
    cout<<"INGRESE EL NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"INGRESE LA FECHA DE CREACION: ";
    fechaCreacion.Cargar();
    cout<<"INGRESE EL TIPO DE CUENTA: ";
    cin>>tipoCuenta;
    estado = true;
}
void Usuario::Mostrar(){
    cout<<"ID: "<<id<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"FECHA DE CREACION: ";
    fechaCreacion.Mostrar();
    cout<<"TIPO DE CUENTA: "<<tipoCuenta<<endl;
}
