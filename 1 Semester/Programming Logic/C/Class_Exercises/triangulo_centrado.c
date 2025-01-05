// Author: reDragonCoder
//Triangulo centrado

//LIBRERIAS
#include <stdio.h>

//MAIN
int main() {
    int totalRen;
    printf("Ingrese la altura del triangulo: ");
    scanf("%d", &totalRen);
    for(int ren=1; ren<=totalRen; ren++){
        for(int esp=totalRen-1; esp>=ren; esp--){
            printf(" ");
        }
        for(int ast=1; ast<=ren; ast++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
