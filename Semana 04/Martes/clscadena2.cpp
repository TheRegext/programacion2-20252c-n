///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring> ///string.h

using namespace std;

///Agregar los siguientes métodos
    /// aMayusculas()-> que ponga todos los caracteres en mayúsculas
    /// aMinusculas()-> que ponga todos los caracteres en minúsculas
    /// primeraMayuscula()-> que ponga la primera letra en mayúscula
    /// int buscarCaracter(char aBuscar) que devuelva la posición de la  primera aparicion del
    /// caracter aBuscar en la cadena. Si no lo encuentra que devuelva -1
    /// agregarCaracter(char letra)-> que agrega un caracter al final del objeto Cadena


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

    Cadena(int tam){
    ///lo vamos a usar para pedir memoria
    /// y asignar el valor recibido
        this->tam=tam;
        p=new char[this->tam];
        if(p==nullptr) exit(1);
        p[(this->tam)-1]='\0';
    }
    void Cargar();
    void Mostrar();

    int getTam(){return this->tam;}
    ~Cadena(){
        ///lo vamos a usar para liberar la memoria
        delete []p;
        cout<<"DESTRUCTOR FUNCIONANDO "<<this<<endl;
    }
    const char *getP(){
        return p;
    }

    void setP(const char *cad){
        delete []p;
        tam=strlen(cad) + 1;
        p=new char[tam];
        if(p==nullptr) exit(1);
        strcpy(p,cad);
        p[tam-1]='\0';
    }
};

/// this es un puntero (oculto) que contiene la dirección del objeto que llama al método
///Sólo existe dentro de la clase. Puede hacerse visible en caso que sea necesario.
void Cadena::Mostrar(){
    cout<<p<<endl;
}

void Cadena::Cargar(){
    char aux[50];
    cin>>aux;
    ///cargar lo que tiene aux en p
    tam=strlen(aux) + 1;
    ///
    delete []p;

    p= new char[tam];
    if(p==nullptr) exit(1);
    strcpy(p,aux);
    p[tam-1]='\0';

}



int main(){
    Cadena palabra("Hola a todos!"), otraPalabra;

    ///palabra.Cargar();
    cout<<"INGRESAR UNA PALABRA ";
    char vPalabra[30];
    cin>>vPalabra;
    palabra.setP(vPalabra);
    palabra.Mostrar();
   // otraPalabra.Cargar();
   // otraPalabra.Mostrar();
   //cout<<&palabra<<" DIRECCION DE palabra"<<endl;
   //cout<<&otraPalabra<<" DIRECCION DE otraPalabra"<<endl;
	system("pause");
	return 0;
}
