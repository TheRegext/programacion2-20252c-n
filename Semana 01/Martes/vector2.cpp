#include <iostream>

using namespace std;

void cargarVector(int v[], int tam);
void mostrarVector(int v[], int tam);

///El nombre de un vector contiene la posición inicial del vector en la memoria
///Las variables que almacenan direcciones son punteros
///El nombre de un vector un PUNTERO CONSTANTE QUE CONTIENE LA DIRECCION DE INICIO DEL VECTOR
int main(){
    const int TAM=5;
    int vec[TAM], *pVec;
    pVec=vec;
    cout<<pVec<<endl,
    cout<<vec<<endl;
    cout<<&vec[0]<<endl;
    system("pause");
    cargarVector(pVec, TAM);
    mostrarVector(pVec,TAM);
    cout<<endl;
    cout<<"*&vec[1] "<<*&vec[1]<<endl;
	system("pause");
	return 0;

}

void cargarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=i+1;
    }
}

void mostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}
