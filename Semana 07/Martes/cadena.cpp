///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>///
# include<cstring>
///Hacer una clase de nombre Cadena para almacenar palabras,
///que ajuste su tama�o a la cantidad de caracteres estrictamente necesarios
///Para la clase Cadena agregar una sobrecarga del operador == que reciba como par�metro un valor entero, y sea verdero si el valor de tam es igual al n�mero recibido
///Sobrecargar el operador == que reciba como par�metro un string y que sea verdadero si el string y el objeto cadena son iguales
///Sobrecargar el operador de asignaci�n recibiendo como par�metro un string


using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char *texto="NADA"){
        tam=strlen(texto)+1;
        p=new char[tam];
        if(p==nullptr)exit(1);
        strcpy(p,texto);
        p[tam-1]='\0';
    }
    void Mostrar(){
        cout<<p<<endl;
    }
    int getTamanio(){return tam;}
    const char *getP(){return p;}
    Cadena & operator=(const Cadena &obj);
    bool operator==(Cadena &obj);
    char operator[](int pos);


    ~Cadena(){
        delete []p;
    }
};
///desarrollo de m�todos
///sobrecargas
bool Cadena::operator==(Cadena &obj){
    if(strcmp(p, obj.p)==0)return true;
    return false;
}

Cadena & Cadena::operator=(const Cadena &obj){
    delete p;
    tam=obj.tam;
    p=new char[tam];
    if(p==NULL) return *this;
    strcpy(p,obj.p);
    return *this;
}

char Cadena::operator[](int pos){
    if(pos>=0 && pos<tam) return p[pos];
    return '\0';
}
bool Cadena::operator==(Cadena aux){
     if(strcmp(p, aux.p)==0) return true;
     return false;

 }

 void Cadena::operator=(const string &aux){
     delete []p;
     tam=aux.size();
     p=new char[tam];
     if(p==nullptr)exit(1);
     strcpy(p, aux.c_str());
 }
 bool Cadena::operator==(string aux){
     if (strcmp(p, aux.c_str()) == 0) return true;
     return false;
 }

 bool Cadena::operator==(int _tam){
     //if(tam == _tam+1) return true;
     if(tam-1 == _tam) return true;
     return false;
 }

/*
void Cadena::operator=(const Cadena &obj){
    delete p;
    tam=obj.tam;
    p=new char[tam];
    if(p==NULL) return *this;
    strcpy(p,obj.p);
}

void Cadena::operator=(const char *pal){ ///hacer!!!!
    delete p;
    tam=obj.tam;
    p=new char[tam];
    if(p==NULL) return *this;
    strcpy(p,obj.p);
}



*/


///fin m�todos




int main(){
    Cadena palabra("HOLA!"), otra("CHAU!"), frase;
    palabra.Mostrar();

    cout<<palabra[2]<<endl;
    /*otra.Mostrar();

    frase=palabra=otra;

    palabra.Mostrar();
    otra.Mostrar();


   if(palabra==otra){
        cout<<"SON IGUALES "<<endl;
    }
    else{
        cout<<"SON DISTINTOS "<<endl;
    }*/
    cout<<endl;
	system("pause");
	return 0;
}
