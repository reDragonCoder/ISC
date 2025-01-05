// Author: reDragonCoder
//operadores de direccion & e indireccion

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    //VARIABLES
    int id=123, *ptrId=NULL; //las variables que tienen asterisco solo almacenan direcciones de memoria (pointer/puntero)
    float prom=9.9;
    char name[]={"sistemas"};

    ptrId=&id; //declaracion para guardar una direccion de memoria de tipo int en este caso
    cout<<"ptrId: "<<ptrId<<endl; //la direccion de memoria que tiene guardada ptrId
    cout<<"*ptrId: "<<*ptrId<<endl; //lo que tiene guardado (el dato) ptrId
    cout<<"&ptrId: "<<&ptrId<<endl<<endl; //direccion donde está creada la variable ptrId, no la que tiene guardada

    cout<<"id: "<<id<<endl;
    cout<<"&id: "<<&id<<endl<<endl;

    cout<<"prom: "<<prom<<endl;
    cout<<"&prom: "<<&prom<<endl<<endl;

    cout<<"name: "<<name<<endl;
    cout<<"&name: "<<&name<<endl<<endl;

    return 0;
}