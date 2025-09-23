///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

///SOBRECARGA DE OPERADORES:
///EN C++ ES POSIBLE AGREGARLE NUEVA FUNCIONALIDAD A LOS OPERADORES DEL LENGUAJE, MEDIANTE EL MECANISMO
/// DE LA SOBRECARGA DE OPERADORES.

///Agregar una sobrecarga para el operador != que devuelva verdadero si ambos objetos son ditintos

using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
         Fecha(int d=0, int m=0, int a=0);

         void Cargar();
         void Mostrar(void);
        ///sets
         void setDia(int dia){
             if(dia>=1 &&dia<=31)this->dia=dia;
             else this->dia=0;
             }
        void setMes(const int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///SOBRECARGAS
        bool operator==(Fecha obj);
        bool operator==(string mes);

        ///DESTRUCTOR
        ~Fecha(){

        }

};
 ///fin de la definición de la clase

///desarrollo de los métodos
void Fecha::Cargar(){
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
         }

void Fecha::Mostrar(){
             cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
         }

Fecha::Fecha(const int d,const int m,const int a){
            dia=d;
            mes=m;
            anio=a;
}

///Sobrecargas
bool Fecha::operator==(Fecha obj){
    if(dia!=obj.dia)    return false;
    if(mes!=obj.mes)    return false;
    if(anio!=obj.anio)    return false;
    return true;
}

bool Fecha::operator==(string mesBuscado){
    string meses[12]={"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "NOVIEMBRE","DICIEMBRE"};
    if(mesBuscado==meses[mes-1]) return true;
    return false;
}

/*
bool Fecha::operator==(const char *mesBuscado){
    string meses[12]={"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "NOVIEMBRE","DICIEMBRE"};
    if(strcmp(mesBuscado, meses[mes-1].c_str())==0) return true;
    return false;
}
*/
/// fin desarrollo de los métodos de Fecha


int main(){
    Fecha aux(1,2,3), otra(1,2,3);

    aux.Mostrar();
	cout<<endl;
	otra.Mostrar();
	cout<<endl;
	/*if(aux==otra){
    //if(aux.operator==(otra)){
        cout<<"SON IGUALES "<<endl;
	}
	else{
        cout<<"SON DISTINTOS "<<endl;
	}*/
	if(aux=="FEBRERO"){
        cout<<"VIVAN LAS VACACIONES! "<<endl;
	}



	system("pause");
	return 0;
}

/*operadores que se pueden sobrecargar
Operadores Unarios:

++ --
Operadores Binarios:

+      +=      -      -=
*      *=      /      /=
%      %=      ^      ^=
&      &=      |      |=
=      ==      !      !=
<      <=      >      >=
&&     ||      ()     []
*/

