#ifndef CLSARCHIVOALUMNOS_H_INCLUDED
#define CLSARCHIVOALUMNOS_H_INCLUDED

#include "clsAlumno.h"

class ArchivoAlumnos{
    private:
        char nombre[40];
    public:
        ArchivoAlumnos(const char *n="Alumnos.dat");
        int contarRegistros();
        Alumno leerRegistro(int);
        bool grabarRegistro(Alumno);
        bool modificarRegistro(Alumno, int);
        int buscarRegistro(int);
        void listarRegistros();
};

#endif // CLSARCHIVOALUMNOS_H_INCLUDED
