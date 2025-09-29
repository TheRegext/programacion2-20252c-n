#ifndef CLSJUEGO_H_INCLUDED
#define CLSJUEGO_H_INCLUDED

#include "clsFecha.h"

class Juego{
    private:
        int id;
        char nombre[30];
        Fecha fechaLanzamiento;
        float calificacion;
        int categoria;
        char desarrolladora[30];
        bool estado;
    public:
        int getId();
        int getCategoria();
        void setId(int);
        void Cargar(int i=-1);
        void Mostrar();
};

#endif // CLSJUEGO_H_INCLUDED
