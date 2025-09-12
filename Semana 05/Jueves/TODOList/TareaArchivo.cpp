#include "TareaArchivo.h"
TareaArchivo::TareaArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {

}

bool TareaArchivo::guardar(Tarea registro){
  FILE *pFile;
  bool result;
  
  pFile = fopen(_nombreArchivo.c_str(), "ab");
  
  if(pFile == nullptr){
    return false;  
  }
  
  result = fwrite(&registro, sizeof(Tarea), 1, pFile);
  
  fclose(pFile);
  
  return result;
}

Tarea TareaArchivo::leer(int pos){
  FILE *pFile;
  bool result;
  Tarea registro;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    registro.setID(-1);
    return registro;  
  }
  
  /**
    SEEK_SET - se desplaza desde el inicio
    SEEK_CUR - se desplaza desde la posicion actual
    SEEK_END - se desplaza desde el final
  */
  
  /// posiciona el cursor en inicio del registro
  fseek(pFile, pos * sizeof(Tarea) , SEEK_SET);
  
  result = fread(&registro, sizeof(Tarea), 1, pFile);
  
  fclose(pFile);
  
  return registro;
  

}

int TareaArchivo::getCantidadRegistros(){
  FILE *pFile;
  bool result;
  int cantidad;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    return 0; 
  }
  
  /// posiciona el cursor en el final del archivo 
  fseek(pFile, 0, SEEK_END);
  /// ftell da el bite donde esta el cursor actualmente 
  cantidad = ftell(pFile) / sizeof(Tarea);
  
  fclose(pFile);
  
  return cantidad;
}

int TareaArchivo::getNuevoID(){
 //return getCantidadRegistros() + 1;
 
 if(getCantidadRegistros() == 0){
  return 1; 
 }
 
 return leer(getCantidadRegistros() - 1).getID() + 1;
}


