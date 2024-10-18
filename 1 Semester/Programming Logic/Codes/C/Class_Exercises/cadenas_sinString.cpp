// Author: reDragonCoder
//conjunto de valores, todos del mismo tipo, almacenados en posiciones contiguas de memoria

//Manejo de cadenas sin usar string.h
//copiar | comparar | longitud | invertir | unir
//strcpy | strcmp   | strlen   | strrev   | strcat

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>

//CONSTANTES GLOBALES
#define TAM 25

//MAIN
int main(){
	char nombre[TAM], carrera[TAM], materia[15], cad[TAM]={""}; //{""} para limpiar contenedor y evitar basura en la cadena (guarda vacio)
	char frase[]="ya casi es Navidad!", uni[]={"SISTEMAS"};
	int opc, tam1=0, tam2=0, cont=0;
	do{
		//system("cls");
		printf("MANEJO DE CADENAS\n");
		printf("Copiar ...... 1\n");
		printf("Comparar .... 2\n");
		printf("Longitud .... 3\n");
		printf("Invertir .... 4\n");
		printf("Unir ........ 5\n");
		printf("Salir ....... 6\n");
		printf("Selecciona una opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1: /*copiar cadenas - \0 significa fin de linea*/
					//mientras el valor del arreglo != '\0'
					for(int i=0; frase[i]!='\0';i++){
						cad[i]=frase[i];
					}
					printf("Cadena copiada: %s\n",cad);
					system("pause");
					break;
			case 2: //comparar cadenas
					printf("Nombre: ");
					fflush(stdin);
					scanf("%s",nombre);
					//obtener el tama�o de nombre
					for(int i=0; nombre[i]!='\0';i++){
						tam1++;
					}
					//obtener el tamanio de frase
					for(int i=0; frase[i]!='\0';i++){
						tam2++;
					}
					//comparar tamanios
					if (tam1==tam2){
						//si son iguales se comparan posicion por posicion
						for(int i=0; i<tam1; i++){
							if (nombre[i]==frase[i]){
								cont++;
							}
							else{
								break;
							}
						}//for i
						if (cont==tam1){
							printf("Cadenas iguales! \n");
						}	
						else{
							printf("Cadenas distintas!\n");	
						}
					}//if
					else{
						printf("Cadenas distintas!\n");	
					}
					break;
			case 3: //longitud de cadenas
					cont=0;
					printf("Introduce una cadena: ");
					fflush(stdin);
					gets(materia); 
					for(int i=0; materia[i]!='\0';i++){
						cont++;
					}
					printf("Longitud: %d\n",cont);
					break;
			case 4:	//invertir cadenas
					printf("Cadena a invertir: ");
					fflush(stdin);
					gets(carrera); 
					tam1=0;
					//obtener la longitud de la cadena
					for(int i=0; carrera[i]!='\0';i++){
						tam1++;
					}
					//recorrer cadena en forma inversa
					int j=0;
					char cadAux[TAM]={""};
					for(int i=tam1-1; i>=0; i--){
						cadAux[j]=carrera[i];
						j++;			
					}
					printf("Cadena invertida: %s\n",cadAux);
					break;
		/*	case 5: //unir cadenas
					
					break;*/
		}//switch
	}while(opc!=6);
}//main
