// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <windows.h>

//MAIN
int main(){
   int n;
   printf("Enter 1 to do a beep \n");
   scanf("%d", &n);
   //beep (cambio de color)
   do{
      Beep(450,750); //cambiar valores para cambiar sonido
      Sleep(100);

      Beep(500,750); 
      Sleep(100);
 
      Beep(550,750); 
      Sleep(100);

      Beep(600,750); 
      Sleep(100);
 
      Beep(650,750);
      Sleep(100);

      Beep(700,750);
      Sleep(100);

   }while(n==8);
   return 0;
}