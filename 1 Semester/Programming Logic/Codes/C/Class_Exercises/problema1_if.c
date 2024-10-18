// Author: reDragonCoder
//PROBLEMA 1:  en una estación de servicio, la medida del volumen de gasolina
//almacenado en su tanque cilíndrico subterráneo (de 100 metros de profundidad) se obtiene al medir la
//distancia desde la parte superior del tanque a la superficie de la gasolina (la profundidad visible).
//El transporte del combustible almacenado en el tanque se hace por medio de camiones cisterna, cada uno con
//capacidad de 100 pies cúbicos. Solicite los datos necesarios al encargado de la gasolinera, para determinar:
//El volumen actual (en metros cúbicos) de combustible dentro del tanque.
//Cantidad de camiones cisterna que serían necesarios para lograr transportar el volumen calculado en el literal
//anterior hacia otra gasolinera. Recuerde que debe validar el ingreso de cada dato solicitado.

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    //Variables
    int no_camiones=0;
    float volumen, distancia=0, diametro_tanq=0, radio=0, altura=0 ;

    //Procedimiento
    printf("Ingrese la distancia desde arriba del taque hasta la superficie: : ");
    scanf("%f", &distancia);

    if(distancia>0 && distancia<=100){
        altura = 100 - distancia;
        printf("Ingrese el diametro del tanque: ");
        scanf("%f", &diametro_tanq);
        if(diametro_tanq>0){
            radio = diametro_tanq/2;
            volumen = ((3.14159*(pow(radio, 2))*altura));
            no_camiones = (volumen * 35.315)/100;
            printf("El volumen sera de: %.3f m3\n", volumen);
            printf("El numero de camiones que se necesitaran es: %d \n", no_camiones);
        }
        else {
            printf("Ingrese un numero valido de diametro");
        }
    }
    else{
        printf("Ingrese un numero valido de distancia");
    }
    return 0;
} //Main