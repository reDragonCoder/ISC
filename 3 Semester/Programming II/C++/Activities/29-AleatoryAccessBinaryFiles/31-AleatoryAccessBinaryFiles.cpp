// Author: reDragonCoder
//ALEATORY ACCESS OR DIRECT ACCESS BINARY FILES

//LIBRARIES
#include <iostream>
#include <fstream>
#include <cstring>

//NAMESPACE
using namespace std;

//CLASS
class Clients{
	private:
		int account; //key field
		char name[50];
		float amount;
		
		fstream file; 
		
	public:
		Clients();	 
		bool openBinaryFile(char *fileName);
		bool openTextFile(char mode, char *filename);		 
		void closeFile();  		
		void createShell(char *fileName);
		void writeLog();
		void readLog();
		int captureAccount();
		void showLogs();
		void logicalDeletion();
		void modify();
		void binaryToText(char* binaryFileName);
	    ~Clients(){}
};

Clients::Clients(){  
    this->account=0; //key field
	strcpy(this->name,"");
	this->amount=0;
}
	
bool Clients::openBinaryFile(char *fileName){
	cout<<endl<<"Open file in read/write mode";
	file.open(fileName,ios::binary|ios::out|ios::in);//<-------------I M P O R T A N T 
	if (!file)
		return false;
	else
		return true;  
}

bool Clients::openTextFile(char mode, char *fileName){
	bool flag=true;
	if(mode=='w')
		file.open(fileName, ios::out | ios::app);
	else
		file.open(fileName, ios::in);
	if(!file)
		flag=false;
	return flag;
}
				 
void Clients::closeFile(){
	cout<<endl<<"Closing file ";
		file.close();
} 	
	
void Clients::createShell(char *fileName){
	file.open(fileName,ios::binary|ios::out  );//openBinaryFile in write mode
	Clients blank; //blank log
	 	
	//creating shell with 10 logs in blank
	cout<<endl;
	for(int i=0; i<10; i++){
		file.write((char*)(&blank),sizeof(Clients));
	}
	cout <<endl<<"File shell successfully created for 10 records!!!\n"<<endl; 
    file.close();
} 
	
int Clients::captureAccount(){
	//validation for account
	int account;	
	do{
		cout <<endl<<"Enter the account: ";
		fflush(stdin);
		cin>>account;
		if(account<1 || account>10)
		    cout<<endl<<"ERROR, account only from 1 to 10";
	   }while(account<1 || account>10);	
	return account;   
}
	
	
void Clients::writeLog(){
	Clients *log=new Clients; //<------I M P O R T A N T 
		
	cout<<endl<<"Data log"<<endl;
	int acc=captureAccount();
	fflush(stdin);	 
	cout<<"Give me a name: ";
	cin.getline(log->name,50);
	cout<<"Give me the amount: ";
	cin>>log->amount;
	log->account=acc;
	     
	/* seekp searches the requested log from the beginning
		of the file */
	file.seekp((log->account-1)*sizeof(Clients), ios::beg);//<------I M P O R T A N T 
		
	//write in the log
	file.write(reinterpret_cast<char*>(log), sizeof(Clients));//<------I M P O R T A N T 
	cout<<endl<<endl<<"Log saved successfully"<<endl<<endl;  
	delete log;
		
}
	
void Clients::readLog(){
	Clients *log=new Clients;

	file.clear();   
	file.seekg( 0 );  
	  	       
	cout<<endl<<"Accounts consult"<<endl; 
	int acc=captureAccount();	  
	cout<<endl<<"Account: "<<acc;
	   
	/* moves to a specific location by account */
	file.seekg((acc-1)*sizeof(Clients)); //<------I M P O R T A N T 
		
	/* extracts the number of bytes from sizeof and places them
		in log */
	file.read(reinterpret_cast<char*>(log), sizeof(Clients));//<------I M P O R T A N T 
		    
	if(strlen(log->name)==0){
		cout<<endl<<endl<<"Blank log"<<endl;
	}
	else{
		cout<<endl<<endl<<"Client data...\n";
		cout<<"Name: "<<log->name<<endl<<"Amount: "<<log->amount<< endl;		
	}    	 
}
	
	
void Clients::showLogs(){
		
	Clients *log; //dynamic object
		 
	cout<<endl<<endl<<"SEQUENTIALLY reading the binary file";
	 
	int c=0;
	file.clear();  
	file.seekg( 0 );  
		
	cout<<endl;
	
	for(int i=1; i<=10; i++){ 
		log=new Clients;
		file.read( reinterpret_cast<char*>(log),sizeof(Clients));   //  <-----------------IMPORTANT
		if(strcmp(log->name,"")!=0){
			c++;
			cout<<endl;
			cout<<endl<<"Account: "<<log->account;	     
			cout<<endl<<"Name: "<<log->name;
			cout<<endl<<"Amount: "<<log->amount;
		}			 	 
	}
	if(c==0){
		cout<<endl<<"All logs are in blank";
	}	 
}

void Clients::logicalDeletion(){
	Clients *deletedAcc=new Clients;
	char ans;

	file.clear();   
	file.seekg(0);  
	  	       
	cout<<endl<<"Which account do you want to delete?"<<endl; 
	int acc=captureAccount();	  
	cout<<endl<<"Account: "<<acc;
	   
	file.seekg((acc-1)*sizeof(Clients)); 
	file.read(reinterpret_cast<char*>(deletedAcc), sizeof(Clients));
		    
	if(strlen(deletedAcc->name)==0){
		cout<<endl<<endl<<"Error: Blank log"<<endl;
		delete deletedAcc;
		return;
	}
	else{
		cout<<endl<<endl<<"Client data...\n";
		cout<<"Name: "<<deletedAcc->name<<endl<<"Amount: "<<deletedAcc->amount<< endl;		
		cout<<"Do you want to proceed with the deletion? y/n: ";
		cin>>ans;
		if(ans=='y'){
			deletedAcc->account=0;
			strcpy(deletedAcc->name,"");
			deletedAcc->amount=0;
			file.seekp((acc-1)*sizeof(Clients), ios::beg);
			file.write(reinterpret_cast<char*>(deletedAcc), sizeof(Clients));
			cout<<endl<<endl<<"Account deleted successfully"<<endl<<endl;  
			delete deletedAcc;
		}else{
			cout<<"Canceling operation..."<<endl;
		}
	}    
}	

void Clients::modify(){
	Clients *modifiedAcc=new Clients;
	char nameAns, amountAns, name[50];

	file.clear();   
	file.seekg(0);  
	  	       
	cout<<endl<<"Which account do you want to modify?"<<endl; 
	int acc=captureAccount();	  
	cout<<endl<<"Account: "<<acc;
	   
	file.seekg((acc-1)*sizeof(Clients)); 
	file.read(reinterpret_cast<char*>(modifiedAcc), sizeof(Clients));
		    
	if(strlen(modifiedAcc->name)==0){
		cout<<endl<<endl<<"Error: Blank log"<<endl;
		delete modifiedAcc;
		return;
	}
	else{
		cout<<endl<<endl<<"Client data...\n";
		cout<<"Name: "<<modifiedAcc->name<<endl;
		cout<<"Do you want to modify the name? y/n: ";
		cin>>nameAns;
		if(nameAns=='y'){
			cout<<"Enter the new name: ";
			cin.ignore();
			cin.getline(modifiedAcc->name,50);
			cout<<"Name modified successfully"<<endl<<endl;
		}
		cout<<"Amount: "<<modifiedAcc->amount<<endl;		
		cout<<"Do you want to modify the amount? y/n: ";
		cin>>amountAns;
		if(amountAns=='y'){
			cout<<"Enter the new amount: ";
			cin>>modifiedAcc->amount;
			cout<<"Amount modified successfully"<<endl<<endl;
		}
		file.seekp((acc-1)*sizeof(Clients), ios::beg);
		file.write(reinterpret_cast<char*>(modifiedAcc), sizeof(Clients));
		delete modifiedAcc;
	}
}

void Clients::binaryToText(char* binaryFileName){
	char textFileName[]="bancomer.txt";
	Clients *binary;
	Clients text;

	file.clear();  
	file.seekg(0);

	if(text.openTextFile('w', textFileName)){
		binary=new Clients;
		while(file.read(reinterpret_cast<char*>(binary),sizeof(Clients))){
			if(strcmp(binary->name,"")!=0){
				text.file<<binary->account<<" "<<binary->name<<" "<<binary->amount<<endl;
			}
		}
		cout<<endl<<"Successfully exported logs from binary to text!"<<endl;
	}
	text.closeFile();
}
	

//FUNCTION
int menu(){
	int op;
	cout<<endl<<endl;
		
	cout<<endl<<"Menu to test direct access or random binary files\n";
	cout<<endl<<"1. Write a log";
	cout<<endl<<"2. Read a log";
	cout<<endl<<"3. Show logs with information";
	cout<<endl<<"4. Delete a log";
	cout<<endl<<"5. Modify a log";
	cout<<endl<<"6. Save information in a text file";
	cout<<endl<<"7. Exit";
	cout<<endl<<"Which option?: ";
	fflush(stdin);
	cin>>op;
	return op;
}
	

//MAIN	
int main (){
	//variables
	int op;
	char ans;
	char fileName[]="bancomer.dat";
	Clients cte;
	    
	cout<<endl<<"Do you want to create the shell? y/n: ";
	cin>>ans;
	if(ans=='y'){
		cte.createShell(fileName);
    }
    if(cte.openBinaryFile(fileName)){ //the file is kept open in read/write mode
		do{
		    op=menu();
		    
		    switch(op){
		    	case 1: cte.writeLog();
		    	        break;
		    	case 2: cte.readLog();
				        break;  
				case 3: cte.showLogs();	        
		    	        break; 
				case 4: cte.logicalDeletion();	        
		    	        break; 
				case 5: cte.modify();	        
		    	        break; 
				case 6: cte.binaryToText(fileName);	        
		    	        break;  
				case 7: cout<<endl<<"Goodbye user!";
				        break;
				default: cout<<endl<<"Error in the option";				     	        
			}
    	}while (op!=7);
    	cte.closeFile();
    }else
	   cout<<endl<<"File cannot be open";		
 
    return 0;
}
