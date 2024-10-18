 // Author: reDragonCoder
 //EJERCICIO 7. Cinco personas quieren conocer el total que pagaran por viajar a la ciudad de 
 //Mérida, dos de ellas viajarán en camión de primera y las otras tres en uno de segunda, el 
 //camión de segunda cobra el 30% menos que el de primera.  

//LIBRERIAS
 #include <stdio.h>

 //MAIN
 int main(){
    //Variables
    float precio_primera, precio_segunda=0, total=0;

    //Pedir datos al usuario
    printf("Ingrese el precio del camion de primera: ");
    scanf("%f", &precio_primera);

    //Calculos
    precio_segunda=precio_primera*0.70;
    total=(precio_primera*2)+(precio_segunda*3);

    //Mostrar total
    printf("El total es de: $%.2f", total);

    return 0;
 }