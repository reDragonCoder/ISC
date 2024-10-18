// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std; 

//STRUCT DECLARATIONS
struct Schedule{
	int hh, mm, ss;
};

//PROTOTYPES
void menu();
Schedule getSchedule(); 		           //mex=getSchedule(); 
void showStandard(Schedule);	          //showStandar(mex);
void showMilitary(Schedule);	         //showMilitary(mex);
Schedule cloneSchedule(Schedule);       //newSchedule=cloneSchedule(current)


//MAIN
int main(){
	//CALLBACK
	menu();

	return 0;
}

//IMPLEMENTATIONS
void menu(){
	int opt;
	Schedule mex={0,0,0}, current, newSchedule;  //initialize the mex variable of schedule type
	do{
		cout<<"Schedule Options " << endl;
		cout<<"Get schedule .... 1\n";
		cout<<"Show standard ... 2\n";
		cout<<"Show military ... 3\n";
        cout<<"Clone schedule... 4\n";
		cout<<"Exit ............ 5\n";
		cout<<"Select one option: ";
		cin>>opt;
		switch(opt){
			case 1: 
                mex=getSchedule(); 
            break;
			case 2: 
                showStandard(mex); 
            break;
			case 3: 
                showMilitary(mex); 
            break;
            case 4:
                current=getSchedule();
                newSchedule=cloneSchedule(current);
                showStandard(newSchedule);
            break;
		}
	}while(opt!=5);
}

Schedule getSchedule(){
	Schedule aux;
	cout<<"Capture "<< endl;
	cout<<"Hour: ";
	cin>>aux.hh;
	cout<<"Minutes: ";
	cin>>aux.mm;
	cout<<"Seconds: ";
	cin>>aux.ss;
	return aux;
}

void showStandard(Schedule mex){  //09:05:23
	cout<< "Standard Format \n";
	cout  
	<< ((mex.hh==0||mex.hh==12) ? 12 : mex.hh %12)
	<< (mex.mm<10 ? ":0" : ":") << mex.mm
	<< (mex.ss<10 ? ":0" : ":") << mex.ss
	<< (mex.hh < 12 ? " am\n" : " pm\n");	
}

void showMilitary(Schedule mex){
    cout<<"Military Schedule"<<endl;
    cout<<(mex.hh<10 ? "0": "")<<mex.hh
        <<(mex.mm<10 ? "0": "")<<mex.mm<<endl;
}

Schedule cloneSchedule(Schedule current){
    Schedule another;
    another.hh=current.hh;
    another.mm=current.mm;
    another.ss=current.ss;
    //another=current;
    return another;
}


