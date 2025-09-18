#include <iostream>
#include <cstring>
#include "clsMateria.h"

using namespace std;

void Materia::Cargar(){
    cout<<"INGRESE EL CODIGO: ";
    cin>>codigo;
    cout<<"INGRESE EL NOMBRE: ";
    cin>>nombre;
    cout<<"INGRESE LA CANTIDAD DE ALUMNOS: ";
    cin>>cantidadAlumnos;
    setCantidadAlumnos(cantidadAlumnos);
    cout<<"INGRESE LA CANTIDAD DE DOCENTES: ";
    cin>>cantidadDocentes;
}

void Materia::Mostrar(){
    cout<<"CODIGO: "<<codigo<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"CANTIDAD ALUMNOS: "<<cantidadAlumnos<<endl;
    cout<<"CANTIDAD DOCENTES: "<<cantidadDocentes<<endl;
}

void Materia::setCodigo(int c){
    codigo = c;
}
void Materia::setNombre(const char *n){
    strcpy(nombre, n);
}
void Materia::setCantidadAlumnos(int cA){
    if(cA >= 0 and cA < 1000){
        cantidadAlumnos = cA;
    }else{
        cantidadAlumnos = 0;
    }
}

void Materia::setCantidadDocentes(int cD){
    cantidadDocentes = cD;
}

int Materia::getCodigo(){
    return codigo;
}
const char *Materia::getNombre(){
    return nombre;
}
int Materia::getCantidadAlumnos(){
    return cantidadAlumnos;
}
int Materia::getCantidadDocentes(){
    return cantidadDocentes;
}
