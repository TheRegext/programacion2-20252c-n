#pragma once
#include <string>

class Personal
{
  public:
    Personal();
    Personal(int id, std::string nombre);
    
    void setID(int id);
    int getID();
    
    void setNombre(std::string nombre);
    std::string getNombre();

  protected:

  private:
    int _id;
    char _nombre[100];
};
