///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

///Encapsulamiento: las variables sólo pueden ser accedidas dentro de la propia clase
///Clase: es un molde donde se define las propiedades y el comportamiento que tendrán
///los objetos de esa clase
///Objetos: son variables de una clase. Una instancia de una clase.
///Los objetos tienen un estado, que es el valor de sus propiedades en un determinado
///momento


class Fecha{
    private:/// lo que se pone en la parte privada solo es accesible DENTRO DE LA CLASE
        int dia, mes, anio;///encapsuladas las variables de la clase, o propiedades
    public:/// es accesible DENTRO y FUERA DE LA CLASE.
        ///métodos o funciones de la clase. Determinan el comportamiento
        void Mostrar();
        void Cargar();
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        ///sets
        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }

        void setMes(int d){
            if(d>=1 && d<=12) mes=d;
            else mes=-1;
        }

        void setAnio(int d){
            if(d>0) anio=d;
            else anio=-1;
        }
        bool fechaOK(){
            if(dia!=-1 && mes!=-1 && anio!=-1) return true;
            return false;
        }
};

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

void Fecha::Cargar(){
    int _dia, _mes,_anio;
    cout<<"DIA ";
    cin>>_dia;
    setDia(_dia);

    cout<<"MES ";
    cin>>_mes;
    setMes(_mes);

    cout<<"ANIO ";
    cin>>_anio;
    setAnio(_anio);
}

///Funciones globales: son funciones que están declaradas y desarrolladas fuera de
/// toda clase

///Métodos: son funciones que pertenecen a una clase en particular.

int main(){
    Fecha reg, obj;
    reg.Cargar();
    int valor;
    /*cout<<"INGRESAR EL DIA ";
    cin>>valor;
    reg.setDia(valor);
    cout<<"INGRESAR EL MES ";
    cin>>valor;
    reg.setMes(valor);
    cout<<"INGRESAR EL ANIO ";
    cin>>valor;
    reg.setAnio(valor);*/
    //reg.Mostrar();
    cout<<"DIA "<<reg.getDia()<<endl;
    cout<<"DIA "<<reg.getMes()<<endl;
    cout<<"DIA "<<reg.getAnio()<<endl;

    //obj=reg;
    //obj.Mostrar();
    if(reg.fechaOK())reg.Mostrar();
    else cout<<"LA FECHA CONTIENE VALORES INCORRECTOS"<<endl;
	system("pause");
	return 0;

}
