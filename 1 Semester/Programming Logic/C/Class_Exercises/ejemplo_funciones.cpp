// Author: reDragonCoder
//Manejo de cadenas con funciones de string.h
//copiar | comparar | longitud | invertir | unir
//strcpy | strcmp   | strlen   | strrev   | strcat

//LIBRERIAS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CONSTANTES GLOBALES
#define TAM 25

//Prototipo de funciones - es la declaracion
void comparar();   //tipoDato nombreFuncion();
void copiar();
void longitud();
void reversa();
void unir();
void menu();

//MAIN
int main(){
	menu();
}

/*IMPLEMENTACION DE LAS FUNCIONES
tipoDato nombreFuncion(){} */
void menu(){
	int opc;
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
			case 1: /*copiar cadenas  nombre="pepe";  INCORRECTO!*/
					copiar(); break;
			case 2: //comparar cadenas
					comparar();  //nombreFuncion();
					break;
			case 3: //longitud de cadenas
					longitud(); break;
			case 4:	//invertir cadenas
					reversa(); break;
			case 5: //unir cadenas
					unir(); break;
		}//switch
	}while(opc!=6);
}

void comparar(){
	char carrera[TAM], materia[15];
	printf("Carrera: ");
	fflush(stdin);
	gets(carrera);
	printf("Materia: ");
	fflush(stdin);
	gets(materia);
	if (strcmp(carrera,materia)==0){
		printf("Cadenas iguales\n");
	}else{
		printf("Cadenas distintas\n");
	}
}

void copiar(){
	char nombre[TAM];
	strcpy(nombre,"pregunten pregunten!");
	printf("Nombre: %s \n",nombre);	
}
void longitud(){
	char cad[TAM];
	int tam;
	printf("Introduce una cadena: ");
	fflush(stdin);
	gets(cad);   //cin>>cad;
	tam = strlen(cad);  
	printf("Tamanio de la cadena: %d\n",tam);
}

void reversa(){
	char uni[]={"SISTEMAS"};
	strrev(uni);
	printf("Cadena invertida: %s\n",uni);
}
void unir(){
	char nombre[TAM], materia[15], cad[TAM];
	strcpy(cad,"");//limipiar una variable char antes de usarla
	strcat(cad,nombre); //pegar el nombre en cad
	strcat(cad,"-"); //pega un guion
	strcat(cad,materia); //pegar la materia
	printf("Union de cadenas: %s",cad);
}





