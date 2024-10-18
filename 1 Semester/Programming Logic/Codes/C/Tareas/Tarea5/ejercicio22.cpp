// Author: reDragonCoder
//22. Escribir un programa que dada una matriz de dos dimensiones obtenga cuál es la 
//    columna que tiene la mayor media.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int matriz[3][3], media[3], max_media = 0, max_media_col = 0;
    //pedir datos al usuario
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Ingrese un numero: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    //calcular las medias
    for(int i=0; i<3; i++){
        media[i]=0;
        for(int j=0; j<3; j++){
            media[i]+=matriz[j][i];
        }
        media[i]/=3;
        if(media[i]>max_media){
            max_media=media[i];
            max_media_col=i;
        }
    }
    printf("\n");
    //mostrar la matriz
    printf("Matriz: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //mostrar cual es la columna con la mayor media
    printf("La columna con la mayor media es la columna %d", max_media_col+1);

    return 0;
}
