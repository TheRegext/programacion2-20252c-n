#include <iostream>
#include "Fecha.h"
#include "Tarea.h"
#include "TareaArchivo.h"
#include "TareaManager.h"
using namespace std;

int main()
{
  TareaManager tm;
  
  tm.cargarTarea();
  tm.listarTareas();
  
  
  ///Fecha f(2,5,1990);
  ///cout << f.toString() << endl;
  
  /*
  string texto; /// asignacion dinamica de memoria 
  texto = "Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt, neque porro quisquam est, qui dolorem ipsum, quia dolor sit, amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt, ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur?";
   cout << sizeof (texto) << endl;
   */
  
  /// Fecha f(11,9,2025);
  
  /*
  Tarea t(1, "hacer composicion", Fecha(11,9,2025), false);
  
  // cout << t.toString() << endl;
  
  if(ta.guardar(t)){
    cout << "Guardado exitosamente!" << endl;  
  }
  else{
    cout << "Ocurrio un error al guardar" << endl;  
  }*/
  
  return 0;
}
