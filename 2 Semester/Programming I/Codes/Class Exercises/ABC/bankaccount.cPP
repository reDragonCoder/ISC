// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <string.h>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANTS
#define MAX 5

//STRUCTURE DECLARATION
struct Atm{ //typedef does not affect, it's the same as struct alone
    int cardNum;
    char userName[25];
    int nip;
    float balanceishon;
    bool status;
}; //struct global variable if you write something between }here;

//PROTOTYPES
void menu(Atm[], int);
bool findUser(int, int, Atm[], int&); 
void showBalance(Atm[]);
void addCash(Atm[], const int);
bool takeCash(Atm[], const int);
void showBalance(Atm[], const int); //const for no editing the &-variable
void fillData(Atm[]);

//MAIN
int main(){
    int nip=0, accountNum=0, position=0;
    bool exists=false;
    Atm bank[MAX];
    fillData(bank);
    cout<<"Account Number: ";
    cin>>accountNum;
    cout<<"Nip: ";
    cin>>nip;
    exists=findUser(accountNum, nip, bank, position);
    if(exists==true){
        menu(bank, position);
    }else{
        cout<<"Incorrect data!"<<endl;
    }
    return 0;
}

void menu(Atm bank[], int position){   
    int opt=0;
    bool taken=false;
    do{
        cout<<endl;
        cout<<"Treasure Bank"<<endl;
        cout<<"1... Show balance"<<endl;
        cout<<"2... Add cash"<<endl;
        cout<<"3... Take cash"<<endl;
        cout<<"4... Exit"<<endl;
        cout<<"Option: ";
        cin>>opt;
        switch(opt){
            case 1: showBalance(bank, position);
                break;
            case 2: addCash(bank, position);
                break;
            case 3: 
            taken=takeCash(bank, position);
                if(!taken){
                    cout<<"Insufficient founds"<<endl;
                }
                break;
        }
    }while(opt<4);
    cout<<endl;
    cout<<"See you next time...";
}

void fillData(Atm bank[]){
    bank[0].cardNum=123;
    strcpy(bank[0].userName, "Copito");
    bank[0].nip=123;
    bank[0].balanceishon=12500;
    bank[0].status=true;

    bank[1].cardNum=456;
    strcpy(bank[1].userName, "Sam");
    bank[1].nip=456;
    bank[1].balanceishon=500;
    bank[1].status=true;

    bank[2].cardNum=789;
    strcpy(bank[2].userName, "Fiona");
    bank[2].nip=789;
    bank[2].balanceishon=800;
    bank[2].status=true;

    bank[3].cardNum=987;
    strcpy(bank[3].userName, "Maya");
    bank[3].nip=987;
    bank[3].balanceishon=7600;
    bank[3].status=true;

    bank[4].cardNum=321;
    strcpy(bank[4].userName, "Kipo");
    bank[4].nip=321;
    bank[4].balanceishon=10;
    bank[4].status=true;
}

bool findUser(int accN, int nip, Atm bank[], int &position){ //& -> memory direction
    bool ok=false;
    for(int i=0; i<MAX; i++){
        if(bank[i].cardNum==accN){
            if(bank[i].nip==nip){
                ok=true;
                position=i;
                break;
            }
        }
    }
    return ok;
}

void showBalance(Atm bank[], const int position){
    if(bank[position].status==true){
        cout<<bank[position].cardNum<<"\t"<<bank[position].userName<<"\t"<<"\t"<<bank[position].balanceishon<<endl;
    }
}

void addCash(Atm bank[], const int position){
    float money;
    cout<<"Amount to deposit: ";
    cin>>money;
    bank[position].balanceishon+=money;
}

bool takeCash(Atm bank[], const int position){
    float money;
    cout<<"Aumount to withdrawal: ";
    cin>>money;
    if(bank[position].balanceishon<money){
        return false;
    }else{
        bank[position].balanceishon-=money;
        return true;
    }
}