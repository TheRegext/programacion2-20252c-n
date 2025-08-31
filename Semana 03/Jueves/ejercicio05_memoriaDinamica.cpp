/**
 5)
 Hacer una función que reciba un vector de enteros y su tamaño
 y luego muestre el vector ordenado de forma ascendente,
 tener en cuenta que el vector enviado como argumento no debe ser modificado.
*/
#include <iostream>
using namespace std;

void mostrar(int vec[], int tamanio){
   int i;
   for(i=0; i<tamanio; i++){
      cout << vec[i] << " ";
   }
   cout << endl;
}

void ordenar(int vec[], int tamanio){
   int i, j, minPosicion;

   for(i = 0; i < tamanio - 1; i++){

      minPosicion = i;

      for (j = i + 1; j < tamanio; j++){
         if (vec[j] < vec[minPosicion]){
            minPosicion = j;
         }
      }

      int aux;
      aux = vec[i];
      vec[i] = vec[minPosicion];
      vec[minPosicion] = aux;
   }
}

void copiar(int destino[], int origen[], int tamanio){
   int i;
   for (i=0; i<tamanio; i++){
      destino[i] = origen[i];
   }
}

void mostrarOrdenado(int vec[], int tamanio){
   int *auxiliar = nullptr;

   auxiliar = new int [tamanio];
   if (auxiliar == nullptr){
      exit(1);
   }

   copiar(auxiliar, vec, tamanio);
   ordenar(auxiliar, tamanio);
   mostrar(auxiliar, tamanio);

   delete []auxiliar;
}

int main(){

   int vec[6] = {10, 50, 6, -3, 88, 14};

   mostrarOrdenado(vec, 6); // -3, 6, 10, 14, 50, 88

   mostrar(vec, 6); // 10, 50, 6, -3, 88, 14

	return 0;
}
