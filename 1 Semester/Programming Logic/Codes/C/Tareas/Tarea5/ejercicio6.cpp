// Author: reDragonCoder
//6. Escribir un programa que muestre un true si una cadena de caracteres capturada por el
//   teclado es simétrica (un palíndromo). Por ejemplo, "DABALEARROZALAZORRAELABAD" es un palíndromo.

//LIBRERIAS
#include <stdio.h>
#include <string.h> 
#include <ctype.h> //isspace
#include <stdbool.h>

//MAIN
int main(){
	//declarar variables
	 char frase[30]={""}, fraseAux[30]={""}, auxiliar[30]={""};
	 int tam1=0, j=0;
     bool ban=false;
	 //pedir una frase al usuario
	printf("Ingrese una frase (solo mayusculas o solo minusculas): ");
	scanf("%s", frase); 
	//guardar el tamaño de la frase ingresada en la variable tam1
	tam1=strlen(frase);
	//guardar todos los caracteres de la frase en la variable fraseAux, eliminando los espacios
	for(int i=0;i<tam1;i++){
		if(!isspace(frase[i])){ 
			fraseAux[j]=frase[i];
			j++;
		}
	}
	//copiar a la variable auxiliar el contenido de fraseAux
	strcpy(auxiliar,fraseAux);
	//invertir fraseAux
	strrev(fraseAux);
	//evaluar si la frase original y la frase invertida son iguales
	if(strcmp(auxiliar,fraseAux)==0){
        ban=true;
		//mostrar 1 si son iguales 
		printf("%d = true", ban);
	} 
    else {
		//mostrar 0 si son diferentes
		printf("%d = false", ban);
	}
	return 0;
}
