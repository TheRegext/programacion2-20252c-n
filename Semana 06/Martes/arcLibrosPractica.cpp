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

///MODIFICAR REGISTRO COMPLETO
///MODIFICAR ISBN DEL LIBRO
///BAJA LÓGICA


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
        int stock;
        bool estado;
    public:
        void Cargar();
        void Mostrar();

        ///gets
        int getISBN(){return ISBN;}
        Fecha getFechaPublicacion(){return fechaPublicacion;}
        bool getEstado(){return estado;}

        ///
        void setISBN(int isbn){ISBN=isbn;}
        void setFechaPublicacion(Fecha fe){fechaPublicacion=fe;}
        void setEstado(bool _estado){estado=_estado;}

};

void Libro::Cargar(){
    cout<<"NUMERO ISBN ";
    cin>>ISBN;
    cout<<"NOMBRE DEL LIBRO ";
    cin>>nombreLibro;
    cout<<"NOMBRE DEL AUTOR ";
    cin>>nombreAutor;
    cout<<"FECHA DE PUBLICACION "<<endl;
    fechaPublicacion.Cargar();
    cout<<"STOCK: "<<endl;
    cin>>stock;
    estado=true;
}

void Libro::Mostrar(){
    cout<<"NUMERO ISBN: "<<ISBN<<endl;
    cout<<"NOMBRE DEL LIBRO: "<<nombreLibro<<endl;
    cout<<"NOMBRE DEL AUTOR: "<<nombreAutor<<endl;
    cout<<"FECHA DE PUBLICACION: "<<endl;
    fechaPublicacion.Mostrar();
    cout<<"STOCK: "<<stock<<endl;
    cout<<"ESTADO: "<<estado<<endl;
}
////FIN CLASE



///PROTOTIPOS FUNCIONES GLOBALES
    int grabarRegistro(Libro reg);
    Libro leerRegistro();
    void leerRegistros();
    bool buscarLibro(int isbn);
    int buscarPosicionLibro(int isbn);
    int agregarRegistro(Libro reg);
    int contarRegistrosLibros();///si devuelve 0 es porque no tiene registros y existe; -1 si no existe
    Libro leerRegistroLibro(int posReg);
    bool bajaLogicaLibro (Libro reg);
    bool modificarRegistroLibro(Libro reg, int pos);

///FIN PROTOTIPOS



int main(){
    Libro reg;
    int opcion, isbn, pos;

    while(true){
        system("cls");

        cout<<"Seleccione opción del menu: "<<endl;
        cout<<"1. Agregar registro"<<endl;
        cout<<"2. Listar registros"<<endl;
        cout<<"3. Buscar registros"<<endl;
        cout<<"4. Contar registros"<<endl;
        cout<<"5. Modificar registro completo"<<endl;
        cout<<"6. Modificar ISBN únicamente"<<endl;
        cout<<"7. Baja lógica"<<endl;
        cout<<"0. Salir"<<endl;

        cin>>opcion;

        switch (opcion){
            case 1:
            if(agregarRegistro(reg)){
                cout<<"Registro grabado"<<endl;
            }
            break;
        case 2:
            leerRegistros();
            break;
        case 3:
                cout<<"Ingrese el ISBN del libro: ";
                cin>>isbn;
                buscarLibro(isbn);
                break;

        case 4: cout<<"Total de registros encontrados: "<<contarRegistrosLibros()<<endl;
                break;
        case 5: cout<<"Cargue los datos completos del registro:"<<endl;
                reg.Cargar();
                pos=buscarPosicionLibro(reg.getISBN());
                if(modificarRegistroLibro(reg,pos)){
                    cout<<"Libro modificado"<<endl;
                }
                else{
                    cout<<"No se pudo modificar"<<endl;
                }
                break;
        case 6: cout<<"Indique el ISBN del libro a modificar: "<<endl;
                cin>>isbn;
                cout<<"Ingrese el nuevo ISBN: ";
                cin>>isbn;
                reg=leerRegistroLibro(buscarPosicionLibro(isbn));
                reg.setISBN(isbn);
                pos=buscarPosicionLibro(isbn);
                if(modificarRegistroLibro(reg,pos)){
                    cout<<"Libro modificado"<<endl;
                }
                else{
                    cout<<"No se pudo modificar"<<endl;
                }
                break;
        case 7: cout<<"Indique el ISBN del libro a dar de baja: ";
                cin>>isbn;
                if(bajaLogicaLibro(reg)){
                    cout<<"Libro dado de baja."<<endl;
                }
                else{
                    cout<<"No se pudo dar de baja."<<endl;
                }
                break;
        case 0:
            return 0;
            break;
        default:
            cout<<"Opcion incorrecta!"<<endl;
        }
        system("pause");
        system("cls");
    }
	system("pause");
	return 0;

}

int grabarRegistro(Libro reg){
    FILE *pLibro;
    pLibro=fopen("libros.dat", "ab"); ///"wb" siempre se crea un archivo nuevo
                                      ///"ab" sirve para agregar registros en un archivo. Si el archivo no existe lo crea
    if(pLibro==nullptr) return -1;

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

bool buscarLibro(int isbn){
    FILE *pLibro;
    Libro reg;
    pLibro=fopen("libros.dat", "rb"); ///"rb" sirve s�lo para leer
    if(pLibro==nullptr) return false;

    while(fread(&reg, sizeof reg, 1, pLibro)==1){
        if(reg.getISBN()==isbn){
            reg.Mostrar();
            fclose(pLibro);
            return true;
        }
    }

    fclose(pLibro);
    return false;
}

int buscarPosicionLibro(int isbn){
    FILE *pLibro;
    int pos=0;
    Libro reg;
    pLibro=fopen("libros.dat", "rb"); ///"rb" sirve s�lo para leer
    if(pLibro==nullptr) return -1;

    while(fread(&reg, sizeof reg, 1, pLibro)==1){
        if(reg.getISBN()==isbn){
            fclose(pLibro);
            return pos;
        }
        pos++;
    }

    fclose(pLibro);
    return -2;
}

int agregarRegistro(Libro reg){
    FILE *pLibro;
    pLibro=fopen("libros.dat", "ab"); ///"wb" siempre se crea un archivo nuevo
                                      ///"ab" sirve para agregar registros en un archivo. Si el archivo no existe lo crea

    if(pLibro==nullptr) return -1;    /// devuelve -1 si no pudo pedir memoria

    //corroboro si el libro existe para poder agregar el registro o rechazar el proceso.
    if(!buscarLibro(reg.getISBN())){
        reg.Cargar();
        if(grabarRegistro(reg)==1){
            return 1;           // si pudo grabar retorna código 1
        }
    }
    fclose(pLibro);
    return -2;  //código -2 no pudo grabar por algún otro motivo
}

int contarRegistrosLibros(){
    FILE *pLibro;
    pLibro=fopen("libros.dat","rb");
    if(pLibro==nullptr){
        return -1;
    }
    /*
    fseek(puntero_file, cuánto_quiero_desplazar, desde_donde)

            0   SEEK_SET-> desde el principio del archivo
            1   SEEK_CUR-> posición actual del archivo
            2   SEEK_END-> eof (fin del archivo)

    fssek(p, 0, 0);-> el puntero al principio del archivo
    fseek(p, 0, 2),-> el puntero va al final del archivo
    fseek(p, sizeof(Libro), SEEK_CUR);-> SE ADELANTA UN REGISTRO
      */
    fseek(pLibro,0,2);/// permite manipular la posición del puntero en el archivo
    int cantBytes=ftell(pLibro);///me dice la cantidad de bytes que hay desde el principio del archivo a la posición actual
    int cantReg=cantBytes/sizeof(Libro);
    fclose(pLibro);
    return cantReg;
}

Libro leerRegistroLibro(int posReg){
    Libro reg;
    reg.setISBN(-1);
    FILE *pLibro;
    pLibro=fopen("libros.dat","rb");
    if(pLibro==nullptr){
        return reg;
    }
    fseek(pLibro, posReg*sizeof(Libro),0);///ubico el puntero al inicio del registro que quiero leer

    fread(&reg,sizeof(Libro),1, pLibro);///leo el registro

    fclose(pLibro);

    return reg;

}

///LÓGICAMENTE PASOS QUE UTILIZARÍAMOS PARA MODIFICAR UN CV, POR EJEMPLO
//1) ABRIMOS EL ARCHIVO
//2) VER DÓNDE QUEREMOS HACER EL CAMBIO (ENCONTRAR DONDE QUIERO HACER EL CAMBIO)
//3) MODIFICO
//4) GUARDARLO



bool modificarRegistroLibro(Libro reg, int pos){
    FILE *pLibro;
    pLibro=fopen("libros.dat","rb+");
    if(pLibro==nullptr){
        return -1;
    }

    fseek(pLibro, pos * sizeof reg, 0);
    bool escribio = fwrite(&reg, sizeof reg, 1, pLibro);
    fclose(pLibro);
    return escribio;
}

///LÓGICAMENTE PASOS PARA DAR UNA BAJA (NO PERDER CONSISTENCIA DE DATOS)
// BAJA LÓGICA, USAMOS UN ATRIBUTO BOOLEANO. LLAMADO ESTADO.



bool bajaLogicaLibro(Libro reg){
    bool resultado=false;
    int pos=buscarPosicionLibro(reg.getISBN());
    if(pos==-1 || pos==-2){
        return false;
    }

    ///leer el registro del archivo
    reg=leerRegistroLibro(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    resultado=modificarRegistroLibro(reg, pos);
    return resultado;
}
