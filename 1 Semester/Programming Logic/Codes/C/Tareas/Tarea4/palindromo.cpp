// Author: reDragonCoder
//Verificar si una frase es un palindromo
//palindormo: palabra que se le al derecho y al revés

//LIBRERIAS
#include <stdio.h>
#include <string.h> // strlen, strcmp
#include <ctype.h> //isspace

//CONSTANTES GLOBALES
const int TAM = 20;

//MAIN
int main(){
	 char frase[TAM]={""}, fraseAux[TAM]={""}, auxiliar[TAM]={""};
	 int tam1=0, j=0;
	
	//capturar la frase
	printf("Frase: ");
	gets(frase); 
	
	//obtener tamaño de la frase
	tam1=strlen(frase);
	for(int i=0;i<tam1;i++){
		if (!isspace(frase[i])){ //isspace solo funciona caracter por caracter
			fraseAux[j]=frase[i];
			j++;
		}
	}
	printf("%s \n",fraseAux);
	
	//copiar contenido de la fraseAux a auxiliar
	strcpy(auxiliar,fraseAux);
	strrev(fraseAux);
	
	//comparar si las cadenas son iguales
	if(strcmp(auxiliar,fraseAux)==0){
		printf("La frase %s es un palindromo!",frase);
	} else {
		printf("La frase %s no es un palindromo!",frase);
	}
	
	return 0;
}
