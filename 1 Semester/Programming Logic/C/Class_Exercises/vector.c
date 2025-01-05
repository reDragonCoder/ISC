// Author: reDragonCoder
//areglos de valores numericos
//captura, despledago

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//CONSTANTES GLOBALES
const int SIZE = 10;

//MAIN
int main (){
    srand(time(NULL));//se inicializa despues del MAIN
    int vecA[SIZE], tamVec;
    int vecB[]={2,5,1,7,8}; //vector inicializado con datos
    int vecC[]={0,0,0,0,0,0,0,0,0,0}; //vector inicializado en 0's, estas haciendo lo que la computadora en el vecA
    
    //capturar el contenido de vecA
    for (int i=0; i<SIZE; i++) { //the cicle HAS to start on a 0
        printf("Values: ");
        scanf("%d", &vecA[i]);  //we need to establish the positions it will be reading ie. [i]
        printf("%d \t", vecA[i]);
    }
    printf("\n");
    //desplegar el contenido
    for (int i=0; i<5; i++) { //the cicle HAS to start on a 0 -- vecB has only 5 digits ie. i<5
        printf("%d \t", vecB[i]); //we need to establish the positions it will be reading ie. [i]
    }
    printf("\n");
    //lenar un vector con random num.
    for (int i=0; i<SIZE; i++) { //the cicle HAS to start on a 0
        vecC[i]=rand()%51;
        
    }
    printf("\n");
    
    //establecer el tamaño de un vector
    tamVec=sizeof(vecB)/sizeof(vecB[0]);//CESAR: en este caso es: vecB tiene 5 valores. Cada int vale 4 bytes. Por lo tanto sizeof(vecB)=20. Pero quremos los ELEMENTOS DE por lo tanto agregamos sizeof(vecB[0])=4 que nada mas nos da los bytes de UN elemento. Entonces tenemos 20/4=5 ELEMENTOS
    printf("%d ", tamVec);
    return 0;
}
