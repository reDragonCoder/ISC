// Author: reDragonCoder
/*Kitty es amiga de Garfield y ha decidido enviarle un mensaje de amor, el cual consiste
 en enviar una frase y un numero n.*/
//I live in a world where Garfield gets a romantic relationship before me

//LIBRERIAS
#include <stdio.h>
#include <string.h>
#include <ctype.h>//isspace
#include <iostream>
#include <conio.h>//kbhit

//NAMESPACE
using namespace std;

//CONSTANTES GLOBALES
const int SIZE = 25;

//MAIN
int main(){
    char phrase[SIZE]=" ", auxPhrase[SIZE]=" ";
    int n=0, length1=0, j=0;
    
    //get phrase
    printf("Please introduce the phrase that you would like to send to Garfield: ");
    fflush(stdin);
    cin.getline(phrase, SIZE);//gets(phrase)
    printf("How may times would you like for the phrase to be repeated?: ");
    scanf("%d", &n);
    
    length1=0;
    //get lenght of 'phrase'
    length1=strlen(phrase);
    printf("%d \n", length1);

    
    //take out spaces
    for (int i=0; i<length1; i++) {
        if ((!isspace(phrase[i]))) {
            auxPhrase[j]=phrase[i];
            j++;
        }//if not space
    }
    
    //Print the phrase repeatedly, the amount of times asked
    while (!kbhit()) {
        for(int j=0; j<n; j++){
            for(int a=0; a<n; a++){
                printf("%s", auxPhrase);
            }
            printf("\n");
        }
    }
    
    printf("\n");
    
    return 0;
}//main
