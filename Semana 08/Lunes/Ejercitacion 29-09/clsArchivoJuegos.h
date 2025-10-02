#ifndef CLSARCHIVOJUEGOS_H_INCLUDED
#define CLSARCHIVOJUEGOS_H_INCLUDED

#include "clsJuego.h"

class ArchivoJuegos{
    private:
        char nombre[30];
    public:
        ArchivoJuegos(const char *n = "Juegos.dat");
        int contarRegistros();
        int buscarRegistro(int);
        Juego leerRegistro(int);
        bool grabarRegistro(Juego);
        void listar();
};

#endif // CLSARCHIVOJUEGOS_H_INCLUDED
