#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "menus.h"

using namespace std;


/**
Realizar un sistema de gestión para registrar usuarios,
juegos y juegos jugados por usuarios.

Para los usuarios se registra:
- ID, Nombre, fecha de creación de la cuenta, tipo de cuenta (1 a 4).

Para los juegos:
-ID, Nombre, fecha de lanzamiento, puntuación, categoria (1 a 20),
desarrolladora

Para los accesos se registra:
-ID de acceso, ID de usuario, ID de juego, fecha del acceso,
duracion del acceso (en minutos).

Crear un menu principal con distintos submenues para cada
archivo. En cada submenu debo poder agregar, listar, modificar
y dar de baja los registros.
*/


int main()
{
    setlocale(LC_ALL, "spanish");
    menuPrincipal();
    return 0;
}
