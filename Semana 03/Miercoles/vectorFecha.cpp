///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;
///Para la clase Fecha
///Agregar un método de nombre compararFechas(), que reciba un objeto Fecha
///y devuelva true si son iguales y false si son distintos
///Agregar un método de nombre mostrarConLetras() que muestre el mes con la palabra
/// que corresponda (1 -> ENERO; 2->FEBRERO)


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
///fin clase Fecha

///Funciones globales prototipo
void cargarFechas(Fecha *v, int cant);
void mostrarFechas(Fecha *v, int cant);


int main(){
    Fecha vFechas[5];
    cargarFechas(vFechas, 5);
    mostrarFechas(vFechas, 5);
	system("pause");
	return 0;

}



void cargarFechas(Fecha *v, int cant){
    int i;
    for(i=0;i<cant;i++) v[i].Cargar();
}

void mostrarFechas(Fecha *v, int cant){
    int i;
    for(i=0;i<cant;i++){
      v[i].Mostrar();
      cout<<endl;
    }

}

