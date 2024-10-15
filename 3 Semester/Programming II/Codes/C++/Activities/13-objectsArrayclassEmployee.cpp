// Author: reDragonCoder
//OBJECT'S ARRAY - CLASS EMPLOYEE

//LIBRARIES
#include <iostream>

//CONSTANT DECLARATIONS
#define SIZE 4

//NAMESPACE
using namespace std;

//CLASSES
class Employee{
    private:
        string name;
        float salary;
        char category; //a, b, c
        int senority;
    public:
        //implicit argument's constructor
        Employee(string name="Uknown", float salary=0, char category='x', int seniority=0){
            cout<<endl<<"I'm the constructor with implicit arguments"<<endl;
            this->name=name;
            this->salary=salary;
            this->category=category;
            this->senority=senority;
        }

        //copy constructor
        Employee(const Employee &obj){
            cout<<endl<<"I'm the copy constructor"<<endl;
            this->name=obj.name;
            this->salary=obj.salary;
            this->category=obj.category;
            this->senority=obj.senority;
        }

        //destructor
        ~Employee(){
            cout<<endl<<"I'm the class destructor"<<endl;
        }

        //set methods
        void setName(string name){
            this->name=name;
        }
        void setSalary(float salary){
            this->salary=salary;
        }
        void setCategory(char category){
            this->category=category;
        }
        void setSeniority(int seniority){
            this->senority=seniority;
        }

        //get methods
        string getName(){
            return this->name;
        }
        float getSalary(){
            return this->salary;
        }
        char getCategory(){
            return this->category;
        }
        int getSeniority(){
            return this->senority;
        }
};

//MAIN
int main(){
    Employee team[SIZE];
    string name, tempN;
    float salary, highestS=0, tempS;
    char category, x, tempC;
    int seniority, position=0, tempSe=0;

    //filling array
    cout<<endl<<"FILLING THE ARRAY"<<endl;
    for(int i=0; i<SIZE; i++){
        cout<<endl<<"Employee "<<i+1<<endl;
        cout<<"Name: ";
        fflush(stdin);
        getline(cin, name);
        team[i].setName(name);
        cout<<"Salary: $";
        cin>>salary;
        team[i].setSalary(salary);
        cout<<"Category (a, b or c): ";
        cin>>category;
        team[i].setCategory(category);
        cout<<"Seniority: ";
        cin>>seniority;
        team[i].setSeniority(seniority);
    }

    cout<<endl<<"*****************************************"<<endl;

    //printing array data
    cout<<endl<<"PRINTING THE ARRAY"<<endl;
    for(int i=0; i<SIZE; i++){
        cout<<endl<<"Employee "<<i+1<<endl;
        cout<<"Name: "<<team[i].getName()<<endl;
        cout<<"Salary: $"<<team[i].getSalary()<<endl;
        cout<<"Category: "<<team[i].getCategory()<<endl;
        cout<<"Seniority: "<<team[i].getSeniority()<<endl;
    }

    cout<<endl<<"*****************************************"<<endl;

   //printing highest salary & employee name
   cout<<endl<<"PRINTING THE HIGHEST SALARY & EMPLOYEE NAME"<<endl;
    highestS=team[0].getSalary();
    for(int i=0; i<SIZE; i++){
        if(team[i].getSalary()>highestS){
            highestS=team[i].getSalary();
            position=i;
        }
    }
    cout<<"The highest salary belongs to "<<team[position].getName()<<" and it is $"<<team[position].getSalary()<<endl;

    cout<<endl<<"*****************************************"<<endl;

    //printing x category employees
    cout<<endl<<"PRINTING THE X CATEGORY EMPLOYEES"<<endl;
    cout<<"Enter the desired category (a, b or c): ";
    cin>>x;
    for(int i=0; i<SIZE; i++){
        if(team[i].getCategory()==x){
            cout<<endl<<"Name: "<<team[i].getName()<<endl;
            cout<<"Salary: $"<<team[i].getSalary()<<endl;
            cout<<"Seniority: "<<team[i].getSeniority()<<endl;
        }
    }

    cout<<endl<<"*****************************************"<<endl;

    //sorting the array by senority (higher to lower) and printing it
    cout<<endl<<"PRINTING THE SORTED ARRAY BY SENIORITY"<<endl;
    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i-1; j++){
            if(team[i].getSeniority()<team[i+1].getSeniority()){
                tempN=team[i].getName();
                tempS=team[i].getSalary();
                tempC=team[i].getCategory();
                tempSe=team[i].getSeniority();
                team[i].setName(team[i+1].getName());
                team[i].setSalary(team[i+1].getSalary());
                team[i].setCategory(team[i+1].getCategory());
                team[i].setSeniority(team[i+1].getSeniority());
                team[i+1].setName(tempN);
                team[i+1].setSalary(tempS);
                team[i+1].setCategory(tempC);
                team[i+1].setSeniority(tempSe);
            }
        }
    }
    for(int i=0; i<SIZE; i++){
        cout<<endl<<"Employee "<<i+1<<endl;
        cout<<"Name: "<<team[i].getName()<<endl;
        cout<<"Salary: $"<<team[i].getSalary()<<endl;
        cout<<"Category: "<<team[i].getCategory()<<endl;
        cout<<"Seniority: "<<team[i].getSeniority()<<endl;
    }

    cout<<endl<<"*****************************************"<<endl;

    //testing the copy constructor of the class
    cout<<endl<<"TESTING THE COPY CONSTRUCTOR OF THE CLASS"<<endl;
    Employee **teamCopy;
    teamCopy=new Employee*[SIZE];
    for(int i=0; i<SIZE; i++){
        teamCopy[i]=new Employee(team[i]);
    }
    for(int i=0; i<SIZE; i++){
        cout<<endl<<"Employee "<<i+1<<endl;
        cout<<"Name: "<<teamCopy[i]->getName()<<endl;
        cout<<"Salary: $"<<teamCopy[i]->getSalary()<<endl;
        cout<<"Category: "<<teamCopy[i]->getCategory()<<endl;
        cout<<"Seniority: "<<teamCopy[i]->getSeniority()<<endl;
    }

    return 0;
}


