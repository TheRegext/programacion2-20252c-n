#ifndef CLSCONTADOR_H_INCLUDED
#define CLSCONTADOR_H_INCLUDED

/**
DESARROLLAR UNA CLASE Contador QUE TENGA LAS SIGUIENTES PROPIEDADES Y METODOS:
-PROPIEDADES: valorActual, valorInicial.
-METODOS QUE PERMITAN:
-ESTABLECER UN VALOR INICIAL AL MOMENTO DE DECLARAR UN OBJETO Contador.
-INCREMENTAR EL VALOR EN UNA CANTIDAD QUE SE RECIBE COMO PARAMETRO.
-DECREMENTAR EL VALOR EN UNA CANTIDAD QUE SE RECIBE COMO PARAMETRO.
-INCREMENTAR EN 1 EL VALOR DEL CONTADOR.
-DECREMENTAR EN 1 EL VALOR DEL CONTADOR.
-REINICIAR EL VALOR DEL CONTADOR AL VALOR INICIAL.
-DEVOLVER EL VALOR ACTUAL DE MI CONTADOR.

NO PERMITIR QUE EL VALOR DE CONTADOR PASE A NEGATIVO.
PENSAR QUE SOBRECARGAS DE OPERADORES PODEMOS REALIZAR PARA FACILITAR EL USO DE NUESTRO OBJETO.
*/

class Contador{
    private:
        int valorInicial;
        int valorActual;
    public:
        Contador(int val = 0);
        void operator+=(int);
        void operator-=(int);
        void operator++(int);
        void operator--(int);
        bool operator==(int);
        bool operator<=(int);
        bool operator>=(int);
        bool operator!=(int);
        void reiniciar();
        int getValorActual();
};

#endif // CLSCONTADOR_H_INCLUDED
