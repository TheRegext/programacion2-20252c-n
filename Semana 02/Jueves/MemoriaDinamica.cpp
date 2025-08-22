#include <iostream>
using namespace std;

int* cargarVector(){
   int *v = new int[5];
   for(int i=0 ; i<5; i++){
      v[i] = i + 1;
   }
   
   return v;
}
   
void mostrarVector(int v[]){
   for(int i=0 ; i<5; i++){
      cout << v[i] << endl;
   }
}

int main() {
   int *v;
   
   v = cargarVector();
   mostrarVector(v);
	
	return 0;
}

