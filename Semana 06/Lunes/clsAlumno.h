#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED

#include "clsDomicilio.h"
#include "clsFecha.h"

/**
COMPOSICION: ES UN MECANISMO DE DISEÑO DE CLASES QUE NOS PERMITE USAR UN OBJETO DE UNA CLASE
COMO PROPIEDAD DE OTRA DISTINTA.
APLICA CUANDO UNA CLASE "TIENE" COMO PROPIEDAD UN OBJETO DE OTRA CLASE.
*/

//class AlumnoNueva{
//    private:
//        int legajo;
//        char nombre[30];
//        char apellido[30];
//        int dni;
//        Domicilio domicilio;
//        char telefono[15];
//        Fecha fechaNacimiento;
//        Fecha fechaInscripcion;
//        bool estado;
//    public:
//        Alumno();
//        void setLegajo(int l);
//        void setNombre(const char *);
//        void setApellido(const char *);
//        void setDni(int);
//        void setTelefono(const char *);
//        void setFechaNacimiento(Fecha);
//        void setDomicilio(Domicilio);
//        void setEstado(bool);
//};

class Alumno{
    private:
        int legajo;
        char nombre[30];
        char apellido[30];
        int dni;
        Domicilio domicilio;
        char telefono[15];
        Fecha fechaNacimiento;
        Fecha fechaInscripcion;
        bool estado;
    public:
        Alumno();
        void setLegajo(int);
        void setNombre(const char *);
        void setApellido(const char *);
        void setDni(int);
        void setTelefono(const char *);
        void setFechaNacimiento(Fecha);
        void setDomicilio(Domicilio);
        void setEstado(bool);
        ///sets para fecha de inscripcion;
        int getLegajo();
        const char *getNombre();
        const char *getApellido();
        int getDni();
        const char *getTelefono();
        Fecha getFechaNacimiento();
        Domicilio getDomicilio();
        bool getEstado();
        ///gets para fecha de inscripcion
        void Cargar(int leg=-1);
        void Mostrar();
        ~Alumno();
        /**
        TIENE EL MISMO NOMBRE QUE LA CLASE
        NO DEVUELVE NADA, NI SIQUIERA VOID
        NO PUEDE RECIBIR PARAMETROS
        SE EJECUTA DE FORMA AUTOMATICA AL SALIR DEL AMBITO DONDE
        FUE DECLARADO MI OBJETO
        */
};


#endif // CLSALUMNO_H_INCLUDED
