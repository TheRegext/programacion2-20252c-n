#pragma once

class Animal
{
  public:
    Animal();
    Animal(int edad);

    int getEdad();
    void setEdad(int edad);

  protected:
    /// toda funcionalidad que querramos que sus hijos puedan utilizar
    
  private:
    int _edad;
};

/*
class Menu{
private:
  string menu[50];
  int cantidadItem;
  
protected:
  void agregarItem(string i);
  void mostrarLinea();
  
public:
  int mostrarMenu();
};

class MenuCliente: public Munu{
  agregarItem();
  
  MunuCliente(){
    agregarItem("1- Cargar cliente");
    agregarItem("2- Mostrar cliente");
    mostrarLinea();
    agregarItem("0- Salir");
  }
};

MenuCliente m;

m.mostrarMenu();


*/

