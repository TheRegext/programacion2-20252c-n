#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "clsJuego.h"

using namespace std;

int Juego::getId(){
    return id;
}
int Juego::getCategoria(){
    return categoria;
}
void Juego::setId(int i){
    id=i;
}
void Juego::Cargar(int i){
    if(i==-1){
        cout<<"INGRESE EL ID: ";
        cin>>id;
    }else{
        id=i;
    }
    cout<<"INGRESE EL NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"INGRESE LA FECHA DE LANZAMIENTO: ";
    fechaLanzamiento.Cargar();
    cout<<"INGRESE LA CALIFICACION: ";
    cin>>calificacion;
    cout<<"INGRESE LA CATEGORIA: ";
    cin>>categoria;
    cout<<"INGRESE LA DESARROLLADORA: ";
    cargarCadena(desarrolladora, 29);
}
void Juego::Mostrar(){
    cout<<"ID: "<<id<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"FECHA DE LANZAMIENTO: ";
    fechaLanzamiento.Mostrar();
    cout<<"CALIFICACION: "<<calificacion<<endl;
    cout<<"INGRESE LA CATEGORIA: "<<categoria<<endl;
    cout<<"INGRESE LA DESARROLLADORA: "<<desarrolladora<<endl;
}
