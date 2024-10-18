// Author: reDragonCoder
/*BINARY FILES
extension .dat
they use the letter b with the opening mode

NOTE: fseek(archivo, posicion (per byte), lugar a moverse) [or SEEK_SET/SEEK_BEG, SEEK_CUR, SEEK_END] -> Only for binary files
NOTE: para saber cuantos renglones tiene el archivo, se divide el numero de bits totales del archivo entre los bits que vale cada renglón

fseek(binFile, 2*sizeof(Student), SEEK_END) -> se multiplica el tamaño de cada renglón por la posicion de renglon que quieres -1.
*/

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCT DECLARATION
struct Student{
	int id;
	char name[25];
	float gpa;
	bool status;
};

//PROTOTYPES
void addStudent(FILE *);
void showInfo(FILE *);
void deleteStudent(int,FILE *);
void general(FILE *); 
int getId(); 
int getIdPos(); 
bool searchID(int, FILE *);
bool searchPos(int, FILE *);
void menu();

//MAIN
int main(){
	menu();
}

//IMPLEMENTATIONS
void menu(){
	FILE *binFile=NULL;
	int opc, id;
	do{
		cout<<"\nTEXT FILE OPTIONS\n";
		cout<<"Add Student ..........1\n";
		cout<<"Show Information .....2\n";
		cout<<"Delete Student .......3\n";
		cout<<"Exit .................4\n";
		cout<<"Select an option: ";
		cin>>opc;
		switch(opc){
			case 1: 
				addStudent(binFile);
			break;
			case 2:
				showInfo(binFile);
			break;
			case 3:
				id=getId();
				if(searchID(id, binFile)){
					deleteStudent(id, binFile);
				}else{
					cout<<"Students does not exists\n\n";
				}
			break;
		}
	}while(opc!=4);
}

void showInfo(FILE *binFile){
	int opc, id, pos;
	do{
		cout<<"\nSHOW INFORMATION\n";
		cout<<"General ........1\n";
		cout<<"Id .............2\n";
		cout<<"Position .......3\n";
		cout<<"Back  ......... 4\n";
		cin>>opc;
		switch(opc){
			case 1: 
				general(binFile); 
			break;
			case 2: 
				id=getId();
				if(!searchID(id,binFile)){
					cout<< "Student does not exist\n";	
				}else{
					cout<<"Everything is ok\n";
				}
			break;
			case 3: 
				pos=getIdPos();
				if(!searchPos(pos-1,binFile)){
					cout<<"Invalid position!\n";
				}else{
					cout<<"Everything is ok\n";
				}
			break;
		}
	}while(opc!=4);
}

void addStudent(FILE *binFile){
	Student alumnito;
	cout<<"ADD STUDENTS\n";
	binFile=fopen("student.dat", "ab");
	if(binFile==NULL){
		cout<<"ERROR\n";
		exit(1);
	}
	//if everything if fine
	cout<<"ID: ";
	cin>>alumnito.id;
	if(!searchID(alumnito.id, binFile)){
		cout<<"Name: ";
		cin>>alumnito.name;
		cout<<"GPA: ";
		cin>>alumnito.gpa;
		alumnito.status=true;
		fwrite(&alumnito, sizeof(Student),1,binFile);
	}else{
		cout<<"Student already exists\n";
	}
	fclose(binFile);
}

bool searchID(int code, FILE *binFile){
	Student temp;
	bool found=false;
	binFile=fopen("student.dat", "rb");
	if(binFile==NULL){
		cout<<"ERROR\n";
		exit(1);
	}
	while(fread(&temp, sizeof(Student), 1, binFile)){
		if((temp.id==code) && (temp.status==true)){
			found=true;
			break;
		}	
	}
	fclose(binFile);
	return found;
}

int getId(){
	int code;
	cout<<"ID: ";
	cin>>code;
	return code;
}

int getIdPos(){
	int position;
	cout<<"Position: ";
	cin>>position;
	return position;
}

void general(FILE *binFile){
	Student alumnito;
	int fileSize=0;
	binFile=fopen("student.dat", "rb");
	if(binFile==NULL){
		cout<<"ERROR\n";
		exit(1);			
	}
	//it allocates the pointer to the final of the file to start counting
	fseek(binFile, 0L, SEEK_END); //L=long
	//it helps us to count all the bytes in the file
	fileSize=ftell(binFile)/sizeof(Student); //total records (per file)
	//it allocates the pointer to the start of the file
	fseek(binFile, 0L, SEEK_SET);
	for(int i=0; i<fileSize; i++){
		fread(&alumnito, sizeof(Student), 1, binFile);
		if(alumnito.status==true){
			cout<<"ID: "<<alumnito.id<<endl;
			cout<<"Name: "<<alumnito.name<<endl;
			cout<<"GPA: "<<alumnito.gpa<<endl;
			cout<<endl;
		}
	}
	fclose(binFile);
}

void deleteStudent(int code,FILE *binFile){
	Student alumnito;
	int fileSize, pos=-1;
	binFile=fopen("student.dat", "rb+");
	if(binFile==NULL){
		cout<<"ERROR\n";
		exit(1);			
	}
	//it allocates the pointer to the final of the file to start counting
	fseek(binFile, 0L, SEEK_END); //L=long
	//it helps us to count all the bytes in the file
	fileSize=ftell(binFile)/sizeof(Student); //total records (per file)
	//it allocates the pointer to the start of the file
	fseek(binFile, 0L, SEEK_SET);
	for(int i=0; i<fileSize; i++){
		fread(&alumnito, sizeof(Student), 1, binFile);
		if(alumnito.id==code){
			alumnito.status=false;
			pos=i;
			break;
		}
	}
	fseek(binFile, pos*sizeof(Student), SEEK_SET);
	fwrite(&alumnito, sizeof(Student), 1, binFile);
	cout<<"Deleted succesfully\n";
	fclose(binFile);
}

bool searchPos(int pos, FILE* binFile){
    Student temp;
    bool found=false;
    binFile=fopen("student.dat", "rb");
	if(binFile==NULL){
		cout<<"ERROR\n";
		exit(1);			
	}
    fseek(binFile,pos*sizeof(Student),SEEK_SET);
	if(fread(&temp,sizeof(Student), 1, binFile))
		found=true;
    fclose(binFile);
    return found;
}





