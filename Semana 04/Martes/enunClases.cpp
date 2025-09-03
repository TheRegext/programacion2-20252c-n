///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;





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
        Fecha fechaPublicacion; ///composición: cuando una clase tiene como propiedad un objeto de otra clase
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


class Prestamo{
    private:
        int ISBN;///representa al libro
        int IdSocio;
        Fecha fechaPrestamo;
        Fecha fechaDevolucion;
    public:

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


int main(){
    Libro reg;
    //reg.Cargar();
    //reg.Mostrar();
    cout<<reg.getFechaPublicacion().getDia()<<endl;
    Fecha aux;
    reg.setFechaPublicacion(aux);
    reg.Mostrar();

	system("pause");
	return 0;

}
