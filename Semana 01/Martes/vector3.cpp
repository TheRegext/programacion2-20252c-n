#include <iostream>

using namespace std;

void cargarVector(int v[], int tam);
void mostrarVector(int v[], int tam);

///El nombre de un vector contiene la posición inicial del vector en la memoria
///Las variables que almacenan direcciones son punteros
///El nombre de un vector un PUNTERO CONSTANTE QUE CONTIENE LA DIRECCION DE INICIO DEL VECTOR

/// & operador de dirección: si lo pongo delante de un nombre de variable me da la dirección

/// * operador de indirección: si lo pongo delante de un puntero me da lo que contiene la
/// dirección que almacena el puntero

int main(){
    const int TAM=5;
    int vec[TAM];
    cargarVector(vec, TAM);
    mostrarVector(vec,TAM);
	cout<<endl;
	system("pause");
	return 0;

}

void cargarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        *(v+i)=i+1;
    }
}

void mostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<*(v+i)<<"\t";
    }
}

/*
ARITMETICA DE PUNTEROS: si a una dirección se le suma un valor entero, esa dirección
se incrementa una cantidad de bytes equivalente al tamaño del tipo de datos multiplicado
por el número

	v=&v[0]

	(v+1)=&v[0]+1 -> &v[1]

	(v+2)=&v[2]

	(v+N)=&v[N]

	*(v+N)=*&v[N]

	*(v+N)=v[N]

*/
