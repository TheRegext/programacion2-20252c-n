#ifndef CLSARCHIVOALUMNOS_H_INCLUDED
#define CLSARCHIVOCIUDADES_H_INCLUDED

#include "ciudad.h"

class ArchivoCiudades{
    private:
        char nombre[40];
    public:
        ArchivoCiudades(const char *n="Ciudades.dat");
        int contarRegistros();
        Ciudad leerRegistro(int);
        bool grabarRegistro(Ciudad);
        bool modificarRegistro(Ciudad, int);
        int buscarRegistro(int);
        void listarRegistros();
};

#endif // CLSARCHIVOALUMNOS_H_INCLUDED
