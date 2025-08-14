#pragma once
#include <string>

/// parametros por omision
void linea (int cantidad, char simbolo='-');
int pedirNumero(std::string mensaje = "Ingrese numero: ");
void mostrarRecaudacion(bool huboVentaMes[12], float recaudacionDiaria[12][31]);
