#ifndef CLSDOMICILIO_H_INCLUDED
#define CLSDOMICILIO_H_INCLUDED

/**
¿QUE NECESITO PARA EL DOMICILIO DEL ALUMNO?
CALLE
ALTURA
CODIGO POSTAL
LOCALIDAD
PARTIDO
PROVINCIA
*/

class Domicilio{
    private:
        char calle[50];
        int altura;
        char codigoPostal[6];
        char localidad[30];
        char partido[30];
        char provincia[30];
    public:
        ///SETTERS Y GETTERS
        void Cargar();
        void Mostrar();
};

#endif // CLSDOMICILIO_H_INCLUDED
