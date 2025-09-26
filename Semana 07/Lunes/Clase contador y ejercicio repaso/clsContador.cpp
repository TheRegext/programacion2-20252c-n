#include <iostream>
#include "clsContador.h"

using namespace std;

Contador::Contador(int val){
    if(val>=0){
        valorInicial = val;
        valorActual = val;
    }else{
        valorInicial = 0;
        valorActual = 0;
    }
}
void Contador::operator+=(int val){
    valorActual += val;
}
void Contador::operator-=(int val){
    if(val <= valorActual){
        valorActual -= val;
    }
}
void Contador::operator++(int){
    valorActual++;
}
void Contador::operator--(int){
    if(valorActual > 0)valorActual--;
}
bool Contador::operator==(int val){
    if(valorActual == val){
        return true;
    }
    return false;
}
bool Contador::operator<=(int val){
    if(valorActual <= val){
        return true;
    }
    return false;
}
bool Contador::operator>=(int val){
    if(valorActual >= val){
        return true;
    }
    return false;
}
bool Contador::operator!=(int val){
    if(valorActual != val){
        return true;
    }
    return false;
}
void Contador::reiniciar(){
    valorActual = valorInicial;
}
int Contador::getValorActual(){
    return valorActual;
}
