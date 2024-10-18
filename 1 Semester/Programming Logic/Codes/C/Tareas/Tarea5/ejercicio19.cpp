// Author: reDragonCoder
/*Escribir un programa que lea en un array N números reales y determine el mayor, el menor y la media de los números leídos.*/

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float a[10]= {0,0,0,0,0,0,0,0,0,0};
    float bigger=0, minor=10, mean=0, sum=0;
    
    printf("Fill the array!\n");
    
    for (int i=0; i<10; i++) {
        printf("%d: ", i+1);
        scanf("%f", &a[i]);
        sum+=a[i];
    }
    
    for(int i=0; i<10; i++){
        if(a[i]>bigger){
            bigger=a[i];
        }
    }
    
    for(int i=0; i<10; i++){
        if(a[i]<minor){
            minor=a[i];
        }
    }
    
    mean=sum/10;
    
    printf("The biggest number in the array is: %0.2f\n", bigger);
    printf("The smallest number in the array is: %0.2f\n", minor);
    printf("The mean of the array is: %0.2f\n", mean);

    return 0;
}//main
