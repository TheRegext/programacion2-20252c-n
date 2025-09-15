#ifndef CLSARCHIVOALUMNOS_H_INCLUDED
#define CLSARCHIVOPAISES_H_INCLUDED

#include "Pais.h"

class ArchivoPaises{
    private:
        char nombre[40];
    public:
        ArchivoPaises(const char *n="paises.dat");
        int contarRegistros();
        Pais leerRegistro(int);
        bool grabarRegistro(Pais);
        bool modificarRegistro(Pais, int);
        int buscarRegistro(const char *c);
        void listarRegistros();
};

#endif // CLSARCHIVOALUMNOS_H_INCLUDED
