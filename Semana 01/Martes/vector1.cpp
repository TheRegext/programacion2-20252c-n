#include <iostream>

using namespace std;

void cargarVector(int v[], int tam);
void mostrarVector(int v[], int &tam);

int main(){
    const int TAM=5; ///primer elemento , y el último el 4
    int vec[TAM], cant, &otraRef=cant;
    /*cout<<sizeof cant<<endl;
    cout<<sizeof vec<<endl;
    cout<<sizeof(char)<<endl;

    long int var;
    cout<<sizeof var<<endl;
    short int var2;
    cout<<sizeof var2<<endl;*/
    cargarVector(vec, TAM);
    cant=5;
    cout<<"DIRECCION DE cant "<<&cant<<endl;
    system("pause");
    cout<<endl;
    mostrarVector(vec,cant);

    cout<<cant<<endl;
	system("pause");
	return 0;

}

void cargarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=i+1;
    }
}

void mostrarVector(int v[], int &tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
    tam=14;
    cout<<"DIRECCION DE tam "<<&tam<<endl;
}
