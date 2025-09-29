#ifndef CLSARCHIVOACCESOS_H_INCLUDED
#define CLSARCHIVOACCESOS_H_INCLUDED

#include "clsAcceso.h"

class ArchivoAccesos{
    private:
        char nombre[30];
    public:
        ArchivoAccesos(const char *n = "Accesos.dat");
        int contarRegistros();
        int buscarRegistro(int);
        Acceso leerRegistro(int);
        bool grabarRegistro(Acceso);
        void listar();
};

#endif // CLSARCHIVOACCESOS_H_INCLUDED
