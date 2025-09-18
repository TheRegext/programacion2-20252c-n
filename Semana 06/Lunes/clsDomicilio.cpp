#include <iostream>
#include "clsDomicilio.h"

using namespace std;

///HACER SETTERS Y GETTERS

void Domicilio::Cargar(){
    cout<<"INGRESE LA CALLE: ";
    cin>>calle;
    cout<<"INGRESE LA ALTURA: ";
    cin>>altura;
    cout<<"INGRESE EL CODIGO POSTAL: ";
    cin>>codigoPostal;
    cout<<"INGRESE LA LOCALIDAD: ";
    cin>>localidad;
    cout<<"INGRESE EL PARTIDO: ";
    cin>>partido;
    cout<<"INGRESE LA PROVINCIA: ";
    cin>>provincia;
}

void Domicilio::Mostrar(){
    cout<<"CALLE: "<<calle<<endl;
    cout<<"ALTURA: "<<altura<<endl;
    cout<<"CODIGO POSTAL: "<<codigoPostal<<endl;
    cout<<"LOCALIDAD: "<<localidad<<endl;
    cout<<"PARTIDO: "<<partido<<endl;
    cout<<"PROVINCIA: "<<provincia<<endl;
}
