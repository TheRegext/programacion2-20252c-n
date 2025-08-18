#include <iostream>

using namespace std;

void asignarValor(int *v, int num=0, int tam=10);
void mostrarVector(int *v, int tam=10);
int *pedirMemoria(int &tam){
    ///PIDO MEMORIA
    int *p=nullptr;
    cout<<"INGRESE LA CANTIDAD DE ELEMENTOS PARA EL VECTOR: ";
    cin>>tam;
    if(tam <= 0){
        cout<<"EL VALOR INGRESADO NO ES VALIDO";
        return nullptr;
    }
    p = new int[tam];
    return p;
}

/**
REALIZAR UN PROGRAMA QUE LE SOLICITE AL USUARIO LA CANTIDAD DE ELEMENTOS
PARA UN VECTOR, QUE PERMITAN INGRESAR VALORES A LAS POSICIONES DEL MISMO Y LUEGO
MOSTRARLO.

REALIZAR UN PROGRAMA QUE HAGA LO MISMO QUE EL ANTERIOR, PERO QUE ESTE SEPARADO EN
FUNCIONES QUE SE LLAMEN DESDE UN MENU.
LAS OPCIONES DEL MENU DEBEN SER:
-SOLICITAR TAMAÑO DEL VECTOR.
-CARGAR VALORES EN EL VECTOR.
-MOSTRAR VECTOR.
BONUS: NO PERMITIR VOLVER A SOLICITAR EL TAMAÑO DEL VECTOR SI YA LE FUE ASIGNADA MEMORIA.

*/


int main()
{
    int tam=12, tam2=4;
    int *pVec=nullptr;
    int *pVec2 = nullptr;
    int *pVec = (int*)malloc(sizeof (int) * tam);
    free(pVec);
    return 0;
    pVec=pedirMemoria(tam);
    ///CHEQUEO QUE SE HAYA PODIDO RESERVAR ESA MEMORIA
    if(pVec == nullptr){
        cout<<"NO SE PUDO RESERVAR LA MEMORIA PEDIDA"<<endl;
        return 404;
    }
    ///USO LA MEMORIA
    asignarValor(pVec, 15, tam);
    mostrarVector(pVec, tam);
    ///DEVUELVO LA MEMORIA
    delete[] pVec;
    pVec = nullptr;
    ///YA NO PUEDO USAR LA MEMORIA QUE PEDI, PORQUE NO ME PERTENECE
    return 0;
}

void asignarValor(int *v, int num, int tam){
    for(int i=0; i<tam; i++){
        v[i]=num;
    }
}

void mostrarVector(int *v, int tam){
    for(int i=0; i<tam; i++){
        cout<<v[i]<<"\t";
    }
}
