#ifndef CLSARCHIVOUSUARIOS_H_INCLUDED
#define CLSARCHIVOUSUARIOS_H_INCLUDED

#include "clsUsuario.h"

class ArchivoUsuarios{
    private:
        char nombre[30];
    public:
        ArchivoUsuarios(const char *n = "Usuarios.dat");
        int contarRegistros();
        int buscarRegistro(int);
        Usuario leerRegistro(int);
        bool grabarRegistro(Usuario);
        void listar();
};

#endif // CLSARCHIVOUSUARIOS_H_INCLUDED
