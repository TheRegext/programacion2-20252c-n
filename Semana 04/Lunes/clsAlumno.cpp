#include <iostream>
#include <cstring>
#include "clsAlumno.h"

using namespace std;

Alumno::Alumno(){
    legajo = 0;
    strcpy(nombre, "S/N");
    strcpy(apellido, "S/A");
    dni = 0;
    strcpy(telefono, "00000000");
    ///valores para la fecha de inscripcion
}

void Alumno::setLegajo(int l){
    legajo = l;
}
void Alumno::setNombre(const char *n){
    strcpy(nombre, n);
}
void Alumno::setApellido(const char *a){
    strcpy(apellido, a);
}
void Alumno::setDni(int d){
    dni = d;
}
void Alumno::setTelefono(const char *t){
    strcpy(telefono, t);
}
void Alumno::setFechaNacimiento(Fecha fN){
    fechaNacimiento = fN;
}
void Alumno::setDomicilio(Domicilio d){
    domicilio = d;
}
int Alumno::getLegajo(){
    return legajo;
}
const char *Alumno::getNombre(){
    return nombre;
}
const char *Alumno::getApellido(){
    return apellido;
}
int Alumno::getDni(){
    return dni;
}
const char *Alumno::getTelefono(){
    return telefono;
}
Fecha Alumno::getFechaNacimiento(){
    return fechaNacimiento;
}
Domicilio Alumno::getDomicilio(){
    return domicilio;
}
void Alumno::Cargar(){
    cout<<"INGRESE EL LEGAJO: ";
    cin>>legajo;
    cout<<"INGRESE EL NOMBRE: ";
    cin.ignore();
    cin.getline(nombre, 30);
    cout<<"INGRESE EL APELLIDO: ";
    cin.getline(apellido, 30);
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    cout<<"INGRESE EL TELEFONO: ";
    cin>>telefono;
    cout<<"INGRESE LA FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"INGRESE EL DOMICILIO DEL ALUMNO: "<<endl;
    domicilio.Cargar();
//    cin>>diaNacimiento;
//    cout<<"INGRESE EL MES DE NACIMIENTO: ";
//    cin>>mesNacimiento;
//    cout<<"INGRESE EL ANIO DE NACIMIENTO: ";
//    cin>>anioNacimiento;
    ///pedir la fecha de inscripcion
}
void Alumno::Mostrar(){
    cout<<"LEGAJO: "<<legajo<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"TELEFONO: "<<telefono<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    cout<<fechaNacimiento.getDia()<<"/"<<fechaNacimiento.getMes()<<"/"<<fechaNacimiento.getAnio();
    cout<<endl;
    cout<<"DOMICILIO DEL ALUMNO: "<<endl;
    domicilio.Mostrar();
    ///mostrar la fecha de inscripcion
}

Alumno::~Alumno(){
    cout<<"FIN DE LA VIDA DEL OBJETO, SE EJECUTA EL DESTRUCTOR DEL ALUMNO: "<<nombre<<endl;
}
