#include <iostream>
#include "clsContador.h"
using namespace std;

int main()
{
    Contador cont(10);
    while(cont >= 5){
        cout<<cont.getValorActual()<<endl;
        cont--;
    }
    return 0;
}

/**
Desarrollar un sistema de gestión para registrar los usuarios, los juegos y los juegos jugados por los usuarios.

Para los usuarios se registra:
-ID, Nombre, fecha de creación de la cuenta, tipo de cuenta (1 a 4).

Para los juegos:
-ID, Nombre, fecha de lanzamiento, puntuación, categoría (1 a 20), desarrolladora.

Para los accesos se registra:
-ID de acceso, ID de usuario, ID de juego, fecha del acceso, duración del acceso (tiempo jugado en minutos).

Crear un menú principal con distintos submenues para cada archivo. En cada submenu debo poder agregar, listar,
modificar (un campo cualquiera) y dar de baja los registros del archivo correspondiente.

MENU PRINCIPAL:
1-USUARIOS
2-JUEGOS
3-ACCESOS
0-SALIR

MENU USUARIOS
1-AGREGAR USUARIO
2-DAR DE BAJA USUARIO
3-MODIFICAR USUARIO
4-LISTAR USUARIOS
0-VOLVER AL MENU PRINCIPAL

Utilizar clases de datos y clases de archivos. Opcional: utilizar clases manager.
*/

//void cargarCadena(char *cad, int tam){
//    string texto;
//    if(cin.peek() = "\n"){
//        cin.ignore();
//    }
//    getline(cin, texto);
//    strncpy(cad, texto.c_str(), tam);
//}
