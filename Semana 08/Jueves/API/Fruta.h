#pragma once
#include <string>
#include "json.hpp"

class Fruta{
public:
  Fruta();
  Fruta(int id, std::string nombre, int calorias, std::string familia, float azucar);
  Fruta(nlohmann::json &json);
    
  void setID(int id);
  void setNombre(std::string nombre);
  void setCalorias(int calorias);
  void setFamilia(std::string familia);
  
  int getID();
  std::string getNombre();
  int getCalorias();
  std::string getFamilia();
  
  float getAzucar();
  void setAzucar( float azucar);
  
  std::string toCSV();
  
private:
  int _id;
  std::string _nombre;
  int _calorias;
  float _azucar;
  std::string _familia;
};
