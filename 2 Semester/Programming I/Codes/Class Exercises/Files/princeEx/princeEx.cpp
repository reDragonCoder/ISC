// Author: reDragonCoder
//Generar un archivo nuevo sin codificar
// a-4
// e-3
// i-1
// o=0

//LIBRARIES
#include <iostream>
#include <stdlib.h>

//NAMESPACE
using namespace std;

//PROTOTYPES
void decoded(FILE*, FILE*);

//MAIN
int main(){
    FILE *prince=NULL;
    FILE *auxiliar=NULL;
    decoded(prince, auxiliar);
	cout<<"Creating report..."<<endl;
	cout<<"Check your files";
    return 0;
}

//IMPLEMENTATIONS
void decoded(FILE* prince, FILE* auxiliar){
    char character, temp;
    auxiliar=fopen("auxiliar.txt", "w");
    prince=fopen("prince.txt", "r"); 
    if(auxiliar==NULL || prince==NULL){
        cout<<"ERROR TYPE: OPENING/CREATING FILE! \n";
        exit(1);
    }
    while(!feof(prince)){
        fscanf(prince, "%c",&character);
		switch(character){
			case '4':
				temp='a';
				fprintf(auxiliar, "%c", temp);
				break;
			case '3':
				temp='e';
				fprintf(auxiliar, "%c", temp);
				break;
			case '1':
				temp='i';
				fprintf(auxiliar, "%c", temp);
				break;
			case '0':
				temp='o';
				fprintf(auxiliar, "%c", temp);
				break;	
			default:
				fprintf(auxiliar, "%c", character);
				break;
															
		}	
    }
    fclose(auxiliar);
    fclose(prince);
}

