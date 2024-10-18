// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>
#include <windows.h>

//MAIN
int main(){
   int n;
   printf("Enter 1 to do a beep \n");
   scanf("%d", &n);
   //beep (cambio de color)
   do{
      Beep(300,1000); 
      Sleep(.5);

      Beep(200,800); //cambiar valores para cambiar sonido
      Sleep(.5);

   }while(n==8);
   return 0;
}