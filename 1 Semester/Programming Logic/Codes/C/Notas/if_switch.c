// Author: reDragonCoder

//-----------------------------------------------------------------------
//If
#include <stdio.h>
int main(){
//    if (/* condition */)
//   {
        /* code */
//    }
}

//Si tenemos por ejemplo:
#include <stdio.h>
int main(){
    int hrsTrab, pago;
    if(hrsTrab<25){
        pago=(9.5*hrsTrab);
    }
    else{
        pago=(9.8*hrsTrab)/2;
    }
    return 0;
}

//podemos usar un operador ternario ?:
#include <stdio.h>
int main(){
    int hrsTrab, pago;
    pago=(hrsTrab<35)?(9.5*hrsTrab):(9.8*hrsTrab)/2;
    return 0;
}
          //condicion   verdadero     falso

//NOTA: el operador ternario solo funciona con una expresion o accion

//----------------------------------------------------------------------------
//Switch
#include <stdio.h>
int main(){
//    switch (expression){
//    case /* constant-expression */:
        /* code */
//        break;
    
//    default:
//        break;
//    }
//    return 0
}
