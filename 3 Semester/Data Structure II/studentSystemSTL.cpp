// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

//NAMESPACE
using namespace std;

//CLASSES
class Student{
    private:
        int id;
        char name[50];
        char domicile[100];
        float gpa;
        int absences;

    public:
        Student(){
            this->id=0;
            strcpy(this->name, "");
            strcpy(this->domicile, "");
            this->gpa=0.0;
            this->absences=0;
        }

        Student(int id, char *name, char *domicile, float gpa, int absences){
            this->id=id;
            strcpy(this->name, name);
            strcpy(this->domicile, domicile);
            this->gpa=gpa;
            this->absences=absences;
        }

        ~Student(){}

        int getId(){
            return this->id;
        }

        const char *getName(){
            return this->name;
        }

        const char *getDomicile(){
            return this->domicile;
        }

        float getGPA(){
            return this->gpa;
        }

        int getAbsences(){
            return this->absences;
        }

        void setId(int id){
            this->id=id;
        }

        void setName(const char *name){
            strcpy(this->name, name);
        }

        void setDomicile(const char *domicile){
            strcpy(this->domicile, domicile);
        }

        void setGPA(float gpa){
            this->gpa=gpa;
        }

        void setAbsences(int absences){
            this->absences=absences;
        }
};

class System{
    private:
        vector<Student> group;
        fstream file;

    public:
        bool openBinaryFile(const char *fileName){
            file.open(fileName, ios::binary | ios::out | ios::in);
            return file.is_open();
        }

        void closeFile(){
            file.close();
        }

        void updateFile(){
            file.seekp(0, ios::beg);
            for(const Student &student:group){
                file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
            }
            cout<<"File updated successfully"<<endl;
        }

        void loadStudentsFromFile(){
            file.seekg(0, ios::beg);
            Student tempStudent;

            while(file.read(reinterpret_cast<char*>(&tempStudent), sizeof(Student))){
                group.push_back(tempStudent);
            }
        }

        void createShell(const char *fileName){
            file.open(fileName, ios::binary | ios::out);
            Student blank;
            for(int i=0; i<10; i++){
                file.write((char*)(&blank), sizeof(Student));   
            }
            file.close();
        }

        int captureId(){
            int id;
            do{
                cout<<endl<<"Enter the student id: ";
                cin.ignore();
                cin>>id;
                if(id<1 || id>10)
                    cout<<endl<<"ERROR, id's only from 1 to 10";
            }while(id<1 || id>10);
            return id;
        }

        void add(){
            Student newStudent;
            int id, absences;
            char name[50], domicile[100];
            float gpa;

            cout<<endl<<"Data log"<<endl;
            id=captureId();
            newStudent.setId(id);
            cin.ignore();

            cout<<"Give me the student's name: ";
            cin.getline(name, 50);
            newStudent.setName(name);

            cout<<"Give me the student's domicile: ";
            cin.getline(domicile, 100);
            newStudent.setDomicile(domicile);

            cout<<"Give me the student's GPA: ";
            cin>>gpa;
            newStudent.setGPA(gpa);

            cout<<"Give me the student's number of absences: ";
            cin>>absences;
            newStudent.setAbsences(absences);

            group.push_back(newStudent);

            updateFile();

            cout<<endl<<"Student added successfully"<<endl<<endl;
        }

        void deletion(){
            int id;
            char ans;
            
            cout<<endl<<"Which student do you want to delete?"<<endl;
            id=captureId();
            cout<<endl<<"Id: "<<id;

            auto it=find_if(group.begin(), group.end(), [id](Student &student){
                return student.getId()==id;
            });

            if(it!=group.end()){
                cout<<endl<<endl<<"Student data...\n";
                cout<<"Name: "<<it->getName()<<endl;
                cout<<"Domicile: "<<it->getDomicile()<<endl;
                cout<<"GPA: "<<it->getGPA()<<endl;
                cout<<"Absences: "<<it->getAbsences()<<endl;
                cout<<"Do you want to procees with the deletion? y/n: ";
                cin>>ans;
                ans=tolower(ans);
                if(ans=='y'){
                    group.erase(it);
                    updateFile();
                    cout<<endl<<"Student deleted successfully"<<endl<<endl;
                }else{
                    cout<<"Canceling operation..."<<endl;
                }
            }else{
                cout<<"Student not found!"<<endl;
            }
        }

        void modify(){
            Student modifiedStudent;
            int id, absences;
            char name[50], domicile[100], ans;
            float gpa;

            cout<<endl<<"Which student do you want to modify?"<<endl;
            id=captureId();
            cout<<endl<<"Id: "<<id;

            auto it=find_if(group.begin(), group.end(), [id](Student &student){
                return student.getId()==id;
            });
            
            if(it!=group.end()){
                cout<<endl<<endl<<"Student data...\n";
                cout<<"Name: "<<it->getName()<<endl;
                cout<<"GPA: "<<it->getGPA()<<endl;
                cout<<"Do you want to modify the GPA? y/n: ";
                cin>>ans;
                if(ans=='y'){
                    cout<<"Enter the new GPA: ";
                    cin.ignore();
                    cin>>gpa;
                    it->setGPA(gpa);
                    cout<<"GPA modified successfully"<<endl<<endl;
                }
                cout<<"Absences: "<<it->getAbsences()<<endl;
                cout<<"Do you want to modify the number of absences? y/n: ";
                cin>>ans;
                if(ans=='y'){
                    cout<<"Enter the new number of absences: ";
                    cin.ignore();
                    cin>>absences;
                    it->setAbsences(absences);
                    cout<<"Absences modified successfully"<<endl<<endl;
                }
                updateFile();
            }else{
                cout<<"Student not found!"<<endl;
            }

        }

        void showStudents(){
            if(group.empty()){
                cout<<"No student avilable"<<endl;
                return;
            }

            sort(group.begin(), group.end(), [](Student &a, Student &b){
                return a.getId()<b.getId();
            });

            cout<<endl<<"---- List of all students ---"<<endl;

            for(Student &student:group){
                if(student.getId()!=0 && student.getName()!=""){
                    cout<<endl<<endl<<"Student data...\n";
                    cout<<"ID: "<<student.getId()<<endl;
                    cout<<"Name: "<<student.getName()<<endl;
                    cout<<"Domicile: "<<student.getDomicile()<<endl;
                    cout<<"GPA: "<<student.getGPA()<<endl;
                    cout<<"Absences: "<<student.getAbsences()<<endl;
                    cout<<endl;
                }
            }
        }

        void report(){
            if(group.empty()){
                cout<<"No student avilable"<<endl;
                return;
            }

            sort(group.begin(), group.end(), [](Student &a, Student &b){
                if(a.getGPA()!=b.getGPA()){
                    return a.getGPA()>b.getGPA();
                }
                return a.getAbsences()<b.getAbsences();
            });

            ofstream outFile("students_report.txt");

            if(!outFile.is_open()){
                cout<<"ERROR: the file cannot be open!"<<endl;
                return;
            }

            outFile<<"Student Report\n";
            outFile<<"--------------------------------------------------------\n";
            outFile<<left<<setw(20)<<"Name" 
                    <<setw(15)<<"Domicile" 
                    <<setw(10)<<"GPA" 
                    <<setw(10)<<"Absences"<<endl;
            outFile <<"--------------------------------------------------------\n";
            for(Student &student:group){
                if(student.getId()!=0 && student.getName()!="") {
                outFile<<left<<setw(20)<<student.getName()
                    <<setw(15)<<student.getDomicile()
                    <<setw(10)<<fixed<<setprecision(2)<<student.getGPA() 
                    <<setw(10)<<student.getAbsences()<<endl;
        }
            }
            outFile.close();
            cout<<endl<<"Report created successfully!"<<endl;
        }
};

//FUNCTIONS
int menu(){
    int op;
	cout<<endl<<endl;
		
	cout<<endl<<"------------- STUDENT SYSTEM -------------\n";
	cout<<endl<<"1. Add a student";
	cout<<endl<<"2. Delete a student";
	cout<<endl<<"3. Modify student information";
	cout<<endl<<"4. Show all students";
	cout<<endl<<"5. Create a report";
	cout<<endl<<"6. Exit";
	cout<<endl<<"Which option?: ";
	cin>>op;
	return op;
}

//MAIN
int main(){
	int op;
	char fileName[]="studentDB.dat";
	System system;
	    
	system.createShell(fileName);

    if(system.openBinaryFile(fileName)){ 
        system.loadStudentsFromFile();
		do{
		    op=menu();
		    
		    switch(op){
		    	case 1: system.add();
		    	        break;
		    	case 2: system.deletion();
				        break;  
				case 3: system.modify();	        
		    	        break; 
				case 4: system.showStudents();	        
		    	        break; 
				case 5: system.report();	        
		    	        break; 
				case 6: cout<<endl<<"Goodbye user!";
				        break;
				default: cout<<endl<<"Error in the option";				     	        
			}
    	}while(op!=6);
    	system.closeFile();
    }else
	   cout<<endl<<"File cannot be open";		
    return 0;
}