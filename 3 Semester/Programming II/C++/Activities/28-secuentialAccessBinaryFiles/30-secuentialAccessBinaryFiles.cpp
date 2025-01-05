// Author: reDragonCoder
//BINARY FILES WITH SEQUENTIAL ACCESS IN OOP (Classes)

//LIBRARIES
#include <iostream>
#include <cstring>
#include <fstream>

//NAMESPACE
using namespace std;

//CLASS
class Clients{
	private:
		int account;
	    char name[50];
	    float amount;
			    
	    fstream file; 
	     
	public:
		Clients(){}
		 
	    Clients(int account, char *name, float amount){
	     	this->account=account;
		    strcpy(this->name, name);
	     	this->amount=amount;
		} 
		 
		~Clients(){}

        bool openWriteMode(char *fileName){
         	bool flag=true;
         	file.open(fileName,ios::binary|ios::out|ios::app); 
    		if(!file) 
    			flag=false;
    		return flag;	   
		}	
		 
		bool openLectureMode(char *fileName){
         	bool flag=true;
         	file.open(fileName,ios::binary|ios::in);
    		if(!file) 
    			flag=false;
    		return flag;	   
		}	
		 
		void writeLog(Clients *cte){
		 	cout<<endl<<"Writing log to file...";
		 	cout<<endl<<cte->account;
		 	cout<<endl<<cte->name;
		 	cout<<endl<<cte->amount;
		 	file.write(reinterpret_cast<const char*>(cte), sizeof(Clients));	 	
		}	
		 
		void readFileInTerminal(){
		 	Clients ct;
		 	int c=0;
			while(file.read(reinterpret_cast<char*>(&ct),sizeof(Clients))){ 
		    	cout<<endl;
		        cout<<endl<<"Account: "<<ct.getaccount();
		        cout<<endl<<"Name: "<<ct.getname();
		        cout<<endl<<"Amount: "<<ct.getamount();
		        c++;
    		}
    		cout<<endl<<endl<<"Total logs: "<<c;		 	
		}	
		 
		 
		void closeFile() {
			file.close();
		}

		void uploadToArray(){
			/*GET THE TOTAL LOGS IN THE BINARY FILE*/
			long nLogs;

			file.clear(); //<------ IMPORTANT
			file.seekg(0); //<----- IMPORTANT

			file.seekg(0, ios::end); //place the cursor at the end of the file
			nLogs=file.tellg()/sizeof(Clients); //size in records

			cout<<endl<<"Total logs: "<<nLogs;

			/*CREATION OF DYNAMIC ARRAY*/
			Clients *array=new Clients[nLogs];

			file.clear(); //<----------- IMPORTANT
			file.seekg(0);

			/*WE PASS THE INFORMATION FROM THE BINARY FILE TO 
				A DYNAMIC ARRAY OF STRUCTURES
				WITH A SINGLE LINE OF CODE*/
			file.read((char*)array, sizeof(Clients)*nLogs); //<--------- IMPORTANT

			/*The dynamic structure array is printed*/
			cout<<endl<<"This information comes from the dynamic structure array"<<endl;
			for(int i=0; i<nLogs; i++){
				cout<<endl;
				cout<<endl<<"Account: "<<array[i].account;
				cout<<endl<<"Name: "<<array[i].name;
				cout<<endl<<"Amount: "<<array[i].amount;
			}
			delete[] array;
		} 
		 
		//get methods
		int getaccount(){
		 	return this->account; 	
		}  
		 
		char *getname(){  
		 	char *aux=new char[strlen(this->name)+2];
		 	strcpy(aux,this->name); 
			return aux;
		 } 
		 
		float getamount(){
		 	return this->amount;
		}
		
		//set methods
	    void setaccount(int account){
		 	this->account=account;
		}  
		 
		void setname(char *name){
		 	strcpy(this->name, name);
		} 
		 
		void setamount(float amount ){
		 	 this->amount=amount;
		}
};

//MAIN
int main(){
	//variables
	int account;
	char name[40];
	float amount;
	char *fileName = new char[40];
	strcpy(fileName,"bank.bin");
	    
	Clients *obj;
	string ans="yes";

    while(ans=="yes"){	
		cout<<endl<<"Give me the account number: ";
	    cin>>account;
	    cin.ignore();
	    cout<<"Give me the name: ";
	    //you can capture name with last names and blank spaces
	    cin.getline(name,40);
	    cout<<"Give me the amount: ";
	    cin>>amount;
	        
	    obj=new Clients(account, name, amount); 
	        
	    if( obj->openWriteMode(fileName) ){
	        obj->writeLog(obj);
	        obj->closeFile();	        
		}else
			cout<<endl<<"Could not open file";
				
		cout<<endl<<endl<<"Do you want to enter more data? yes/no: ";
		cin.ignore();
		getline(cin,ans);
	} 

	cout<<endl<<"Reading binary file";
	Clients *objL=new Clients; 
	         
	if(objL->openLectureMode(fileName)){
	    objL->uploadToArray();
	    objL->closeFile();
	}else
		cout<<endl<<"Could not open file";
	            
	return 0;      
}
	    
	    
        
     

