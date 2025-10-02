#ifndef CLSUSUARIO_H_INCLUDED
#define CLSUSUARIO_H_INCLUDED

#include "clsFecha.h"

class Usuario{
    private:
        int id;
        char nombre[30];
        Fecha fechaCreacion;
        int tipoCuenta;
        bool estado;
    public:
        void setId(int);
        void setNombre(const char *);
        void setFechaCreacion(Fecha);
        int getId();
        const char *getNombre();
        Fecha getFechaCreacion();
        int getTipoCuenta();
        bool getEstado();
        void Cargar(int i=-1);
        void Mostrar();
};

#endif // CLSUSUARIO_H_INCLUDED
