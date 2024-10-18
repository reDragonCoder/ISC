// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <string.h>

//NAMESPACE
using namespace std;

//PROTOTYPES
void showTeachersInfo(FILE*, char*);
void showStudents(FILE*, int);
void menu();

//MAIN
int main(){
	menu();
	return 0;
}

//IMPLEMENTATIONS
void menu(){
    FILE *f=NULL;
    char *ced=new char[10];
    int opt=0, parallel=0;
    do{
    	cout<<endl;
        cout<<"         MENU         "<<endl;
        cout<<"Find a professor.....1\n";
        cout<<"Find a student.......2\n";
        cout<<"Exit.................3\n";
        cin>>opt;
        switch(opt){
            case 1:
            	cout<<"Enter the id number you are searching for: "<<endl;
				cin>>ced;
				showTeachersInfo(f, ced);
            break;
            case 2:
            	cout<<"Enter the parallel number you are searching for: "<<endl;
            	cin>>parallel;
            	showStudents(f, parallel);
            break;
            case 3:
            	cout<<"Goodbye!";
            	exit(1);
            break;
        }
    }while(opt!=3);
}

void showTeachersInfo(FILE *f, char *ced){
	char tempCed[11]; 
	int cedNumber, inputCed, nameSize, surnameSize, j=0, k=0;
	char notImportant[50]={""}, name[50]={""}, surname[50]={""}, auxName[50]={""}, auxSurname[50]={""};
	f=fopen("teachers.txt", "r");
	if(f==NULL){
		cout<<"ERROR TYPE: OPENING FILE!";
		exit(1);
	}
	while(!feof(f)){
		fgets(tempCed,11,f);
		cedNumber=atoi(tempCed); //atoi=ASCII to integer
		inputCed=atoi(ced);
		if(cedNumber!=0 && cedNumber==inputCed){	
			fscanf(f, "%s%s%s", notImportant, name, surname);
			surnameSize=strlen(surname);
			for(int i=0; i<surnameSize; i++){
				auxSurname[j]=surname[i];
				j++;
			}
			auxSurname[j]=',';
			j++;
			auxSurname[j]='\0';
			nameSize=strlen(name);
			for(int i=0; i<nameSize; i++){
				if(name[i]!=','){
					auxName[k]=name[i];
					k++;
				}
			}
			name[k]='\0';
			cout<<auxSurname<<" "<<auxName<<endl;
		}
	}
	fclose(f);
}

void showStudents(FILE*f, int parallel){
	int num;
	int nameSize, surnameSize, j=0, k=0;
	char notImportant[50]={""}, name[50]={""}, surname[50]={""}, auxName[50]={""}, auxSurname[50]={""};
	f=fopen("students.txt", "r");
	if(f==NULL){
		cout<<"ERROR TYPE: OPENING FILE!";
		exit(1);
	}
	while(!feof(f)){
		fscanf(f, "%s%s%s%d", notImportant, name, surname, &num);
		if(num==parallel){
			surnameSize=strlen(surname);
			for(int i=0; i<surnameSize; i++){
				if(surname[i]!=','){
					auxSurname[j]=surname[i];
					j++;
				}
			}
			auxSurname[j]=',';
			j++;
			auxSurname[j]='\0';
			nameSize=strlen(name);
			for(int i=0; i<nameSize; i++){
				if(name[i]!=','){
					auxName[k]=name[i];
					k++;
				}
			}
			name[k]='\0';
			cout<<auxSurname<<" "<<auxName<<endl;
			for(int i=0; i<nameSize; i++){
				auxName[i]=' ';
			}
			for(int i=0; i<surnameSize; i++){
				auxSurname[i]=' ';
			}
			k=0;
			j=0;
		}
	}
	fclose(f);
}






