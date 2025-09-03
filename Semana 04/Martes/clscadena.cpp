///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring> ///string.h

using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char* valorIni="nada"){
    ///lo vamos a usar para pedir memoria
    /// y asignar el valor recibido
        tam=strlen(valorIni)+1;
        p=new char[tam];
        if(p==nullptr) exit(1);
        strcpy(p,valorIni);
        p[tam-1]='\0';
    }
    void Cargar();
    void Mostrar();
    int getTam(){return tam;}
    ~Cadena(){
        ///lo vamos a usar para liberar la memoria
        delete []p;
    }
};

void Cadena::Mostrar(){
    cout<<p<<endl;
}

void Cadena::Cargar(){
    char aux[50];
    cin>>aux;
    ///cargar lo que tiene aux en p

}

int main(){
    Cadena palabra("Hola a todos!"), otraPalabra;

    ///palabra.Cargar();
    palabra.Mostrar();
    otraPalabra.Mostrar();
	system("pause");
	return 0;
}
