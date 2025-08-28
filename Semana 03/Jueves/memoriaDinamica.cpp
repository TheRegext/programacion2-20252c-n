#include <iostream>
using namespace std;

int main(){

   int **mat = nullptr;
   int filas, columnas;

   cout << "Cantidad de filas: ";
   cin >> filas;

   cout << "Cantidad de columnas: ";
   cin >> columnas;

   mat = new int*[filas];

   if (mat == nullptr){
      return 1;
   }

   for(int i=0; i<filas; i++){
      mat[i] = new int[columnas] {};

      if (mat[i] == nullptr){
         return 1;
      }
   }

   for(int i=0; i<filas; i++){
      for(int j=0; j<columnas; j++){
         cout << mat[i][j] << " ";
      }
      cout << endl;
   }

   // Liberación
   for(int i=0; i<filas; i++){
      delete [] mat[i];
   }

   delete []mat;

	return 0;
}
