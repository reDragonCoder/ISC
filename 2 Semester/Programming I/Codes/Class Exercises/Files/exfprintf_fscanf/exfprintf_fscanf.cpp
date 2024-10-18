// Author: reDragonCoder
//fprintf - fscanf

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//FUNCTION PROTOTYPES
void capture(FILE *);
void search(FILE *, int);
void dropOut(FILE *, FILE*, int);
float gpa(FILE *);
void menu();

//MAIN
int main(){
	menu();
}

//FUNCTION IMPLEMENTATIONS
void menu(){
	FILE *file=NULL;
	FILE *temp=NULL;
	int opc=0, id=0;
	do{
		cout<<endl;
		cout<<"TEXT FILE OPTIONS\n";
		cout<<"Capture ..............1\n";
		cout<<"Search ...............2\n";
		cout<<"GPA ..................3\n";
		cout<<"Drop outs.............4 \n";
		cout<<"Exit..................5\n";
		cout<<"Your option: ";
		cin>>opc;
		switch(opc){
			case 1: 
                capture(file);
            break;
			case 2: 
				cout<<"Enter the ID you are searching for: ";
				cin>>id;
				search(file, id);
            break;
			case 3: 
				cout<<"Groupal gpa: "<<gpa(file)<<endl;
            break;
			case 4:
				cout<<"Enter the ID you want to erase: ";
				cin>>id;
				dropOut(file, temp, id);
				cout<<"Deleted succesfully"<<endl;
			break;
		}
	}while(opc!=5);
}

void capture(FILE *file){
    int id;
    float gpa;
    char *name=new char[15];
	bool answ=false;
    //open file
    file=fopen("students.txt", "a");
    if(file==NULL){
        cout<<"Error type: The file cannot open";
        exit(1); //end the execution
    }
	do{
		cout<<"ID: ";
		cin>>id;
		cout<<"Name: ";
		cin>>name;
		cout<<"GPA: ";
		cin>>gpa;
		//write in the file
		fprintf(file, "%d\t%s\t%f\n", id, name, gpa);
		cout<<"Do you want to capture another one? y=1/n=0: ";
		cin>>answ;
	}while(answ); //while(answ==true) is the same as while(answ)
	fclose(file);
	delete name;
}

void search(FILE *file, int data){
	int id;
	float gpa;
	char *name=new char[15];
	bool flag=false;
	file=fopen("students.txt", "r");
	if(file==NULL){
		cout<<"Error type: The file cannot open";
        exit(1); //end the execution
	}
	while(!feof(file)){
		fscanf(file, "%d%s%f", &id, name, &gpa);
		if(data==id){
			cout<<"--Student Data--\n";
			cout<<"Name: "<<name<<endl;
			cout<<"GPA: "<<gpa<<endl;
			flag=true;
			break;
		}
	}
	if(!flag){
		cout<<"The ID does not exists! \n";
	}
	fclose(file);
	delete name;
}

float gpa(FILE *file){
	int id, total=0;
    float gpa, add=0;
    char *name=new char[15];
    //open file
    file=fopen("students.txt", "r"); //r=read
    if(file==NULL){
        cout<<"Error type: The file cannot open";
        exit(1); //end the execution
    }
	rewind(file); //for not repeting the last student
	while(fscanf(file, "%d %s %f", &id, name, &gpa)!=EOF){ //for not repeting the last student (EOF=End Of File)
		cout<<id<<"\t"<<name<<endl;
		add+=gpa;
		total++;
	}
	fclose(file);
	delete name;
	return add/total;
}

void dropOut(FILE *file, FILE *temp, int data){ //POR QUE NO SE BORRA DE STUDENT Y NO SE IMPRIME EN TEMP
	int id;
	float gpa;
	char *name=new char[15];
	file=fopen("students.txt", "r"); //original
	temp=fopen("temporal.txt", "a"); //temporal
	if(file==NULL || temp==NULL){
		cout<<"Error type: file(s) troubles";
		exit(1);
	}
	rewind(file);
	while(fscanf(file, "%d %s %f", &id, name, &gpa)!=EOF){
		if(id!=data){
			fprintf(temp,"%d\t%s\t%f\n", id, name, gpa);
			
		}
	}
	fclose(file);
	fclose(temp);
	delete name;
}
