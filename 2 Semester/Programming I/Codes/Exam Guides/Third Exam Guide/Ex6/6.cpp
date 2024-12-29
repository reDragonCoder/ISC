// Author: reDargonCoder

//You want to make a copy of a character file with the condition that they are only stored (in a
//new file) the lines that are in even position.

//LIBRARIES
#include <iostream>

using namespace std;

//PROTOTYPES
void fillNew(FILE*, FILE*);

//MAIN
int main(){
	FILE* allText=NULL;
	FILE* newFile=NULL;
	
	fillNew(allText, newFile);
	cout<<"Creating file...\n";
	cout<<"Check your files";
	
	return 0;
}

//IMPLEMENTATIONS
void fillNew(FILE* allText, FILE* newFile){
	allText=fopen("story.txt", "r");
	newFile=fopen("evenText.txt", "w");
	
	char line[2000];
	int pos=1;
	while(fgets(line, sizeof(line), allText)!=NULL){
		if(pos%2==0){
			fputs(line, newFile);
		}
		pos++;
	}
	
	fclose(allText);
	fclose(newFile);
}
