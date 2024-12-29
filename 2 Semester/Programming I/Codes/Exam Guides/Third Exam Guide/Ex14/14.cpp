// Author: reDargonCoder

//Design a program that, given a text file, asks the user for a word and counts the number
//of the same ones that are in the file.

//LIBRARIES
#include <iostream>
#include <string.h>

using namespace std;

//PROTOTYPES
void countWords(FILE*);

//MAIN
int main(){
	FILE* story=NULL;
	countWords(story);
	return 0;
}

//IMPLEMENTATIONS
void countWords(FILE* story){
	story=fopen("story.txt", "r");
	if(story==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	int counter;
	char word[100];
	char searchedWord[100];
	
	cout<<"Enter the word you want to search for in the text: ";
	fflush(stdin);
	gets(searchedWord);
	
	while(fscanf(story, "%s", word)==1){
		if(strcmp(searchedWord, word)==0){
			counter++;
		}
	}
	
	cout<<"The searched word appears "<<counter<<" times in the text";
	
	fclose(story);
}
