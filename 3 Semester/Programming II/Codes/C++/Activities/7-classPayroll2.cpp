// Author: reDragonCoder
//GET & SET METHOD USING CLASSES

//LIBRARIES
#include<iostream>

//NAMESPACE
using namespace std;

//CLASSES
class Payroll{
    private:
        float hrs; //worked hours
        float ph; //pay per hour
    public:
        float calculateSalary();
        Payroll(float hrs, float ph); //constructor with parameters
        Payroll();

        //get method
        float getHrs();
        float getPh();

        //set method
        void setHrs(float hrs);
        void setPh(float ph);

        ~Payroll(); //destructor
}; //end of class

        
//get method
float Payroll::getHrs(){
    return this->hrs;
}
float Payroll::getPh(){
    return this->ph;
}

//set method
void Payroll::setHrs(float hrs){
    this->hrs=hrs;
}
void Payroll::setPh(float ph){
    this->ph=ph;
}

//empty constructor
Payroll::Payroll(){
    cout<<endl<<"I am the empty class constructor"<<endl;
}

//constructor with parameters
Payroll::Payroll(float hrs, float ph){
    cout<<endl<<"I am the class constructor with parameters"<<endl;
    this->hrs=hrs;
    this->ph=ph;
}

//destructor
Payroll::~Payroll(){
    cout<<endl<<"I am the class destructor"<<endl;
}

//method to calculate salary
float Payroll::calculateSalary(){
    float baseSalary=6000, extraHrS=0;

    if(hrs>20){
        extraHrS=(hrs-20)*ph*3+10*ph*2+10*ph; 
    }else if(hrs>10){
        extraHrS=(hrs-10)*ph*2+10*ph; 
    }else{
        extraHrS=hrs*ph;
    }

    baseSalary+=extraHrS;
    return baseSalary;
}
       
//MAIN
int main(){
    //variables
    float salary=0, hrs=0, ph=0;

    //TESTING
    cout<<endl<<"Testing empty constructor and get-set methods"<<endl;
    Payroll cesar;

    cesar.setHrs(45);
    cesar.setPh(120);

    salary=cesar.calculateSalary();
    cout<<endl<<"Cesar's total salary was: $"<<salary<<endl<<endl;

    Payroll fer(30,130);
    salary=fer.calculateSalary();
    cout<<endl<<"Fer's total salary was: $"<<salary<<endl<<endl;
    fer.setHrs(35);
    salary=fer.calculateSalary(); //it has to calulate again with the change
    cout<<endl<<"Fer's total salary was: $"<<salary<<endl<<endl;

    //printing data with get
    cout<<endl<<"Worked hours by Fer: "<<fer.getHrs();
    cout<<endl<<"Pay per hour for Fer: "<<fer.getPh();

    return 0;
}