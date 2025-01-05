// Author: reDragonCoder
//Operadores *, &, aritmética de punteros

//LIBRARIES
#include <iostream>

//GLOBAL CONSTANTS
#define TAM 6

//NAMESPACE
using namespace std;

//MAIN
int main(){
    int vec[]={3,4,6,2,7,8}, *ptr=NULL;

    //desplegar el contenido del vector
    for(int i=0; i<TAM; i++){
        cout<<vec[i]<<"\t";
    }

    //ptr=vec; //apuntar al vector
    ptr=&vec[0]; //es lo mismo que la de arriba
}


/*Puntero- toda variable que se declara con un * (asterisco). Solo pueden
almacenar direcciones de memoria. Ejemplo:
int edad<=15, id=456;
int *ptr=edad //indica que el ptr apunta a la dir de memoria de edad

ptr=&id; //cambiar de direccion a ptr

Los punteros solo pueden almacenar direcciones de variables que sean del mismo tipo

*/