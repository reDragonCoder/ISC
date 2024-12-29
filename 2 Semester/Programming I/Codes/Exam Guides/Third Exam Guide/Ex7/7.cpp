// Author: reDargonCoder

//Take two text files and make a merge of the two into a new file, with the condition that
//the lines are interspersed.

//LIBRARIES
#include <iostream>

using namespace std;

//PROTOTYPES
void fillNew(FILE*, FILE*, FILE*);

//MAIN
int main(){
	FILE* text1=NULL;
	FILE* text2=NULL;
	FILE* newText=NULL;
	
	fillNew(text1, text2, newText);
	cout<<"Creating file...\n";
	cout<<"Check your files";
	
	return 0;
}

//IMPLEMENTATIONS
void fillNew(FILE* text1, FILE* text2, FILE* newText){
	text1=fopen("text1.txt", "r");
	text2=fopen("text2.txt", "r");
	newText=fopen("newText.txt", "w");
	
	if(text1==NULL || text2==NULL || newText==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	char line1[1000];
	char line2[1000];
	while(fgets(line1, sizeof(line1), text1) && fgets(line2, sizeof(line2), text2)){
		fputs(line1, newText);
		fputs(line2, newText);
	}
	while(fgets(line1, sizeof(line1), text1)){
		fputs(line1, newText);
	}
	while(fgets(line2, sizeof(line2), text2)){
		fputs(line2, newText);
	}
	
	fclose(text1);
	fclose(text2);
	fclose(newText);
}
