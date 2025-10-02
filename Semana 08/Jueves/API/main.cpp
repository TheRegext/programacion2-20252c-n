#include <iostream>
#include "HttpClient.h"
#include "json.hpp"
#include "Fruta.h"
using namespace std;

int main()
{
  HttpClient cliente;
  string response;
  nlohmann::json data;
  // Fruta frutas[100];

  response = cliente.get("https://raw.githubusercontent.com/TheRegext/programacion2-20252c-n/refs/heads/main/Semana%2008/Jueves/frutas.json");
  data = nlohmann::json::parse(response);

  Fruta *frutas;
  frutas = new Fruta[data.size()];

  if(frutas == nullptr)
  {
    cout << "No se pudo asignar memoria" << endl;
    exit(-100);
  }

  for(int i=0; i<data.size(); i++)
  {
    frutas[i] = Fruta(data[i]);

    cout << frutas[i].toCSV() << endl;
    cout << "------" << endl;
  }

  


  delete [] frutas;

  return 0;
}
