///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;


///Agregar un menú con las opciones:
///*AGREGAR REGISTRO
///*LISTAR REGISTROS
///*SALIR

///EL PROGRAMA NO DEBE ADMITIR QUE SE INGRESEN LIBROS CON UN ISBN QUE YA EXISTE


class Fecha{
private:
    int dia,mes,anio;
public:
    Fecha(){
        dia=2;
        mes=9;
        anio=2025;
    }
    void Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }
    void Mostrar(){
        cout<<"DIA "<<dia<<endl;
        cout<<"MES "<<mes<<endl;
        cout<<"ANIO "<<anio<<endl;
    }
    int getDia(){return dia;}

};

///La clase TIENE (como propiedad) un objeto de OTRA clase

class Libro{
    private:
        int ISBN;
        char nombreLibro[40];
        char nombreAutor[40];
        Fecha fechaPublicacion; ///composici�n: cuando una clase tiene como propiedad un objeto de otra clase
        int sotck;
    public:
        void Cargar();
        void Mostrar();

        ///gets
        int getISBN(){return ISBN;}
        Fecha getFechaPublicacion(){return fechaPublicacion;}

        ///
        void setISBN(int isbn){ISBN=isbn;}
        void setFechaPublicacion(Fecha fe){fechaPublicacion=fe;}

};




void Libro::Cargar(){
    cout<<"NUMERO ISBN ";
    cin>>ISBN;
    cout<<"NOMBRE DEL LIBRO ";
    cin>>nombreLibro;
    cout<<"FECHA DE PUBLICACION "<<endl;
    fechaPublicacion.Cargar();
}

void Libro::Mostrar(){
    cout<<"NUMERO ISBN "<<ISBN<<endl;
    cout<<"NOMBRE DEL LIBRO "<<nombreLibro<<endl;
    cout<<"FECHA DE PUBLICACION "<<endl;
    fechaPublicacion.Mostrar();
}

////FIN CLASE
///PROTOTIPOS FUNCIONES GLOBALES
bool agregarRegistro(Libro reg);
Libro leerRegistro();
void leerRegistros();
///FIN PROTOTIPOS
int main(){
    Libro reg;
    reg.Cargar();    
    
    agregarRegistro(reg);
    reg=leerRegistro();
	///reg.Mostrar();
	//leerRegistros();

	system("pause");
	return 0;

}


bool agregarRegistro(Libro reg){
    FILE *pLibro;
    pLibro=fopen("libros.dat", "ab"); ///"wb" siempre se crea un archivo nuevo
                                      ///"ab" sirve para agregar registros en un archivo. Si el archivo no existe lo crea
    if(pLibro==nullptr) return false;
    int escribio=fwrite(&reg, sizeof reg, 1, pLibro);
    fclose(pLibro);
    return escribio;
}

Libro leerRegistro(){
    FILE *pLibro;
    Libro reg;
    pLibro=fopen("libros.dat", "rb"); ///"rb" sirve s�lo para leer
    if(pLibro==nullptr) return reg;
    fread(&reg, sizeof reg, 1, pLibro);
    fclose(pLibro);
    return reg;
}

void leerRegistros(){
    FILE *pLibro;
    Libro reg;
    pLibro=fopen("libros.dat", "rb"); ///"rb" sirve s�lo para leer
    if(pLibro==nullptr) return;

   while(fread(&reg, sizeof reg, 1, pLibro)==1){
        reg.Mostrar();
        cout<<endl;
   }

    fclose(pLibro);
}

