// Author: reDragonCoder
//ACTIVITY: USING CLASSES FOR A PAYROLL 

//LIBRARIES
#include <iostream>

//NAMESPACE 
using namespace std;

//CLASSES
class Payroll{
    private:
        float whrs; //worked hours
        float ph; //pay per hour
    public:
        float calculateSalary(); //it's what the class can do
        Payroll(float whrs, float ph); //constructor with parameters
        ~Payroll(); //destructor
};

    //constructor with parameters
    Payroll::Payroll(float whrs, float ph){
        cout<<endl<<"I'm the costructor WITH PARAMETERS of the class"<<endl;
        this->whrs=whrs;
        this->ph=ph;
    }

    //destructor
    Payroll::~Payroll(){
        cout<<endl<<"I'm the class destructor"<<endl;
    }

    //method
    float Payroll::calculateSalary(){
        float baseSalary=6000, extraHrS=0;

        if(whrs>20){
            extraHrS=(whrs-20)*ph*3+10*ph*2+10*ph; 
        }else if(whrs>10){
            extraHrS=(whrs-10)*ph*2+10*ph;
        }else{
            extraHrS=whrs*ph;
        }

        baseSalary+=extraHrS;
        return baseSalary;
    }

//MAIN
int main(){
    //VARIABLES
    float whrs1=0, ph1=0;

    //static object #1
    Payroll ceoPayroll(50, 100);
    cout<<"---CEO---"<<endl;
    cout<<endl<<"The salary of the CEO is: $"<<ceoPayroll.calculateSalary()<<endl;

    cout<<endl<<"************************************"<<endl;

    //static object #2
    cout<<endl<<"Enter the worked hours by the CFO: ";
    cin>>whrs1;
    cout<<endl<<"Enter the pay per hour of the CFO: ";
    cin>>ph1;

    Payroll cfoPayroll(whrs1, ph1);
    cout<<"---CFO---"<<endl;
    cout<<endl<<"The salary of the CFO is: $"<<cfoPayroll.calculateSalary()<<endl;
    
    cout<<endl<<"************************************"<<endl;

    //dynamic object #1
    Payroll *cooPayroll;
    cooPayroll=new Payroll(40, 75);
    cout<<"---COO---"<<endl;
    cout<<endl<<"The salary of the COO is: $"<<cooPayroll->calculateSalary()<<endl;
    delete cooPayroll;

    cout<<endl<<"************************************"<<endl;

    //dynamic object #2
    cout<<endl<<"Enter the worked hours by the employee: ";
    cin>>whrs1;
    cout<<endl<<"Enter the pay per hour of the employee: ";
    cin>>ph1;

    Payroll *employeePayroll;
    employeePayroll=new Payroll(whrs1, ph1);
    cout<<"---Employee---"<<endl;
    cout<<endl<<"The salary of the employee is: $"<<employeePayroll->calculateSalary()<<endl;
    delete employeePayroll;

    return 0;
}
