#ifndef CLSACCESO_H_INCLUDED
#define CLSACCESO_H_INCLUDED

#include "clsFecha.h"

class Acceso{
    private:
        int id;
        int idUsuario;
        int idJuego;
        Fecha fechaAcceso;
        int tiempoAcceso;
        bool estado;
    public:
        int getId();
        int getIdUsuario();
        int getIdJuego();
        Fecha getFechaAcceso();
        int getTiempoAcceso();
        void setId(int);
        void Cargar(int i=-1);
        void Mostrar();
};

#endif // CLSACCESO_H_INCLUDED
