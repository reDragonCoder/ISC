// Author: reDargonCoder

//You have a file of integers. We wnat to develop a program that indicates the position of the maximum and
//that of the minimum of said list of integers.

//LIBRARIES
#include <iostream>

using namespace std;

//PROTOTYPES
void minPos(FILE*);
void maxPos(FILE*);

//MAIN
int main(){
	FILE* numbers=NULL;
	
	minPos(numbers);
	cout<<"\n";
	maxPos(numbers);
	
	return 0;
}

//IMPLEMENTATIONS
void minPos(FILE* numbers){
	numbers=fopen("numbers.txt", "r");
	
	if(numbers==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	int position, minPos, actualNum, min;
	char line[100];
	
	
	while(fgets(line, sizeof(line), numbers)!=NULL){
		if(sscanf(line, "%d", &actualNum)==1){ //sscanf reads data from a character string
			if(position==0 || actualNum<min){
				min=actualNum;
				position++;
				minPos=position;
			}else{
				position++;
			}
		}
	}
	
	fclose(numbers);
	
	if(position>0){
		cout<<"The position for the minimum number ["<<min<<"] is "<<minPos;
	}else{
		cout<<"There is not valid numbers in the file";
	}
}

void maxPos(FILE* numbers){
	numbers=fopen("numbers.txt", "r");
	
	if(numbers==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	int position=0, maxPos=0, actualNum=0, max=0;
	char line[100];
	
	
	while(fgets(line, sizeof(line), numbers)!=NULL){
		if(sscanf(line, "%d", &actualNum)==1){
			if(position==0 || actualNum>max){
				max=actualNum;
				position++;
				maxPos=position;
			}else{
				position++;
			}
		}
	}
	
	fclose(numbers);
	
	if(position>0){
		cout<<"The position for the maximum number ["<<max<<"] is "<<maxPos;
	}else{
		cout<<"There�s not valid numbers in the file";
	}
}
