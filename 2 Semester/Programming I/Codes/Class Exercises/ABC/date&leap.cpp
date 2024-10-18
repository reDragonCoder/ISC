// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCTURE DECLARATION
struct Date{
    int dd, mm, yy;
};

//PROTOTYPES
void menu();
Date getDate();
void showDate(Date);
Date modifyDate(Date);
bool verifyDate(Date);

//MAIN
int main(){
    //CALLBACK
    menu();

    return 0;
}

//IMPLEMENTATIONS
void menu(){
    int opt=0;
    Date date1, newDate;
    cout<<"DATE OPTIONS"<<endl;
    cout<<"Capture date ... 1 \n";
    cout<<"Show date ...... 2 \n";
    cout<<"Modifiy date ... 3 \n";
    cout<<"Exit ........... 4 \n";
    cin>>opt;
    do{
        switch(opt){
            case 1:
                date1=getDate();
            break;
            case 2:
                showDate(date1);
            break;
            case 3:
                newDate=modifyDate(date1);
                showDate(newDate);
            break;
        }
        cout<<"Enter option: ";
        cin>>opt; 
    }while(opt!=4);
}

Date getDate(){
    Date aux;
    cout<<"DATE CAPTURE"<<endl;
    cout<<"Day: ";
    cin>>aux.dd;
    cout<<"Month: ";
    cin>>aux.mm;
    cout<<"Year: ";
    cin>>aux.yy;
    return aux;
}

void showDate(Date dateX){
    int leap=0;
    if((dateX.mm==2)&&(dateX.dd>28)){
        if (dateX.dd==29) {
            if(((dateX.yy%4!=0) && (dateX.yy%400!=0)) ||(dateX.yy%100==0)){
                cout<<"That's not a valid date! (Error type: leap year)"<<endl;
                leap=1;
            }
            else{
                leap=0;
            }
        }
        else{
            if(dateX.dd>29) {
                cout<<"That's not a valid date! (Error type: leap year)"<<endl;
                leap=1;
            }
        }
    }
    if(leap==0) {
        cout<<"Your date is: "<<endl;
        if(dateX.dd<10){
            cout<<"0"<<dateX.dd;
        }else{
            cout<<dateX.dd;
        }
        cout<<"/";
        if(dateX.mm<10){
            cout<<"0"<<dateX.mm;
        }else{
            cout<<dateX.mm;
        }
        cout<<"/";
        cout<<dateX.yy;
        cout<<endl;
    }
}

Date modifyDate(Date dateX){
    int opt=1;
    char modification;
    Date another;
    cout<<"What do you want to modify? d=day, m=month, y=year"<<endl;
    cin>>modification;
    cin.ignore();
    do{
        if(modification=='d'){
            cout<<"Enter another day: ";
            fflush(stdin);
            cin>>another.dd;
            dateX.dd=another.dd;
        }
        if(modification=='m'){
            cout<<"Enter another month: ";
            cin>>another.mm;
            dateX.mm=another.mm;
        }
        if(modification=='y'){
            cout<<"Enter another year: ";
            cin>>another.yy;
            dateX.yy=another.yy;
        }

        if(opt!=0){
        cout<<"Do you want to make another change? yes(1) no(0): ";
        cin>>opt;
    }
    }while(opt!=0);
    return dateX;
}