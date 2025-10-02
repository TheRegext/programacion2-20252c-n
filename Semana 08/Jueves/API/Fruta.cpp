#include "Fruta.h"


Fruta::Fruta() 
: _id(0), _nombre(""), _calorias(0), _familia(""), _azucar(0){

}

Fruta::Fruta(int id, std::string nombre, int calorias, std::string familia, float azucar)
{
  setID(id);
  setNombre(nombre);
  setCalorias(calorias);    
  setFamilia(familia);
  setAzucar(azucar);
}

Fruta::Fruta(nlohmann::json &data){
  setID(data["id"].get<int>());
  setNombre(data["name"].get<std::string>());
  setCalorias(data["nutritions"]["calories"].get<int>());
  setAzucar(data["nutritions"]["sugar"].get<float>());
  setFamilia(data["family"].get<std::string>());
}

void Fruta::setID(int id) {
    _id = id;
}

void Fruta::setNombre(std::string nombre) {
    _nombre = nombre;
}

void Fruta::setCalorias(int calorias) {
    _calorias = calorias;
}

void Fruta::setFamilia(std::string familia){
  _familia = familia;
}

int Fruta::getID() {
    return _id;
}

std::string Fruta::getNombre() {
    return _nombre;
}

int Fruta::getCalorias() {
    return _calorias;
}

std::string Fruta::getFamilia(){
  return _familia;
}


float Fruta::getAzucar(){
  return _azucar;
}

void Fruta::setAzucar( float azucar){
  _azucar = azucar;
}

std::string Fruta::toCSV(){
  return std::to_string(_id) + "," + _nombre + "," + std::to_string(_calorias) +","+_familia+","+std::to_string(_azucar); 
}
