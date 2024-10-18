// Author: reDragonCoder
/*Escribir un programa a la que se le de como entrada dos arrays de enteros ordenados de forma creciente, y muestre como salida un array ordenado de forma creciente formado por los elementos de las entradas y sin incluir los elementos repetidos.*/

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    
    int a[6]= {1,2,3,5,6,7};
    int b[7]= {2,4,6,8,10,12,14};
    int c[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
    int temp, f=6, same=0;
    
    //evaluate if there are any duplicates
    for(int i=0; i<7; i++){
        for(int j=i+1; j<6; j++){
            if(b[i]==a[j]){
                a[j]=20;//if so push one of the duplicates to the end so they can be cut out :)!
                same++;
            }
        }
    }
   
    for (int i=0; i<6; i++) {
        c[i]=a[i];//add the first array into the aux array
    }//sum
    
    for (int i=0; i<7; i++) {
        c[f]=b[i];//add the second array into the aux array
        f++;
    }//sum
    
   //order the array
    for(int i=0; i<13; i++){
        for(int j=i+1; j<13; j++){
            if(c[i]>c[j]){
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    
    
    temp=13-same;//establich how many numbers are being cut out
    printf("The combination of both arrays is: ");
    for(int i=0; i<temp; i++){
        printf("%d ",c[i]);
    }
    printf("\n");
    return 0;
}//main
