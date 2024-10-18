// Author: reDragonCoder
//Reporte que indique: 
// -Total de signos (?)
// -Total de letras (a-z, A-Z)
// -Total de caracteres (todo)
// -Total de espacios

//LIBRARIES
#include <iostream>
#include <stdlib.h>

//NAMESPACE
using namespace std;

//PROTOTYPES
void report();
void totalQuestionMarks(FILE*, FILE*);
void totalLetters(FILE*, FILE*);
void totalCharacters(FILE*, FILE*);
void totalSpaces(FILE*, FILE*);

//MAIN
int main(){
    report();
    return 0;
}

//IMPLEMENTATIONS
void report(){
	FILE *birthday=NULL;
	FILE *report=NULL;
	totalQuestionMarks(birthday, report);
	totalLetters(birthday, report);
	totalCharacters(birthday, report);
	totalSpaces(birthday, report);
	cout<<"Creating report..."<<endl;
	cout<<"Check your files";
}

void totalQuestionMarks(FILE* birthday, FILE* report){
    int totalQ=0;
    char questionMark;
    report=fopen("report.txt", "w");
    birthday=fopen("birthday.txt", "r"); 
    if(birthday==NULL || report==NULL){
        cout<<"ERROR TYPE: OPENING/CREATING FILE! \n";
        exit(1);
    }
    while(!feof(birthday)){
        fscanf(birthday, "%c",&questionMark);
        if(questionMark=='?'){
            totalQ++;
        }
        
    }
    fprintf(report, "The total question marks in the text is: %d \n", totalQ);
    fclose(birthday);
    fclose(report);
}

void totalLetters(FILE* birthday, FILE* report){
	int totalL=0;
	char letter;
	report=fopen("report.txt", "a");
	birthday=fopen("birthday.txt", "r");
	if(birthday==NULL || report==NULL){
		cout<<"EROR TYPE: OPENING/CREATING FILE! \n";
		exit(1);
	}
	while(!feof(birthday)){
		fscanf(birthday, "%c", &letter);
		if(letter>64 && letter<91){
			totalL++;
		}else if((letter>96 && letter<123)){
			totalL++;
		}
	}
	fprintf(report, "The total letters in the text is: %d \n", totalL);
    fclose(birthday);
    fclose (report);
}

void totalCharacters(FILE* birthday, FILE* report){
	int totalC=0;
	char character;
	report=fopen("report.txt", "a");
	birthday=fopen("birthday.txt", "r");
	if(birthday==NULL || report==NULL){
		cout<<"EROR TYPE: OPENING/CREATING FILE! \n";
		exit(1);
	}
	while(!feof(birthday)){
		fscanf(birthday, "%c", &character);
		if(character!=' '){
			totalC++;
		}
	}
	fprintf(report, "The total characters in the text is: %d \n", totalC);
    fclose(birthday);
    fclose (report);
}

void totalSpaces(FILE* birthday, FILE* report){
	int totalS=0;
	char space;
	report=fopen("report.txt", "a");
	birthday=fopen("birthday.txt", "r");
	if(birthday==NULL || report==NULL){
		cout<<"EROR TYPE: OPENING/CREATING FILE! \n";
		exit(1);
	}
	while(!feof(birthday)){
		fscanf(birthday, "%c", &space);
		if(isspace(space)){
			totalS++;
		}
	}
	fprintf(report, "The total spaces in the text is: %d \n", totalS);
    fclose(birthday);
    fclose (report);
}
