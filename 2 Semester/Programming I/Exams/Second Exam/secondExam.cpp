// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCT DECLARATION
struct Date{
    int dd;
    int mm;
    int yy;
};

struct Student{
    int id;
    char *name;
    Date birthday;
    float gpa;
    int missings;
};

//PROTOTYPES
void menu(Student *, int);
void fillList(Student *, int);
bool captureValidation(Student *, int);
bool dateValidation(Student *, int);
bool monthDayValidation(Student *, int);
bool leapValidation(Student *, int);
void showReport(Student *, int);
void showEightGpa(Student *, int);
void studentSituation(Student*, int);
void showLeapStudents(Student *, int);
void groupalReport(Student *, int);

//MAIN
int main(){
    int n;
    cout<<"Enter the number of students to add: ";
    cin>>n;
    Student *list=new struct Student[n];
    fillList(list, n);
    if(captureValidation(list, n)==true){
        menu(list, n);
    }else{
        cout<<endl;
        cout<<"Something gone wrong, try again!";
    }
    
    return 0;
}

//IMPLEMENTATIONS
void menu(Student *list, int n){
    int opt=0;
    do{
        cout<<endl;
        cout<<"          MENU        "<<endl;
        cout<<"1) Student report"<<endl;
        cout<<"2) Student with gpa greater than 8.5"<<endl;
        cout<<"3) Show student situation"<<endl;
        cout<<"4) Show student born in leap year"<<endl;
        cout<<"5) Groupal report"<<endl;
        cout<<"6) Exit"<<endl;
        cout<<"Enter your option: ";
        cin>>opt;
        switch(opt){
            case 1:
                showReport(list, n);
            break;
            case 2:
                showEightGpa(list, n);
            break;
            case 3:
                studentSituation(list, n);
            break;
            case 4:
                showLeapStudents(list,n);
            break;
            case 5:
                groupalReport(list,n);
            break;
        }
    }while(opt!=6);
}

void fillList(Student *list, int n){
    for(int i=0; i<n; i++){
        //id capture
        cout<<"ID: ";
        cin>>list[i].id;
        //name capture
        cout<<"Name: ";
        list[i].name=new char[30];
        fflush(stdin);
        cin>>list[i].name;
        //birthday capture
        cout<<"Birthday: \n";
        cout<<"Day: ";
        cin>>list[i].birthday.dd;
        cout<<"Month: ";
        cin>>list[i].birthday.mm;
        cout<<"Year: ";
        cin>>list[i].birthday.yy;
        //gpa capture
        cout<<"GPA: ";
        cin>>list[i].gpa;
        //missings capture
        cout<<"Missings: ";
        cin>>list[i].missings;
    }
}

bool captureValidation(Student *list, int n){
    bool validation=false;
    for(int i=0; i<n; i++){
        if(list[i].gpa>=0 && list[i].gpa<=10){
            if(list[i].missings>0){
                if(dateValidation(list, n)==true){
                    validation=true;
                }
            }
        }
    }
    return validation;
}

bool dateValidation(Student *list, int n){
    bool validation=false;
    for(int i=0; i<n; i++){
        if(list[i].birthday.yy>=1924 && list[i].birthday.yy<=2024){
            if(list[i].birthday.mm>0 && list[i].birthday.mm<13){
                if(list[i].birthday.dd>0 && list[i].birthday.dd<32){
                    if(list[i].birthday.mm==2){
                        if(list[i].birthday.dd<29){
                            validation=true;
                        }else{
                            if(list[i].birthday.dd==29){
                                if(leapValidation(list, n)==true){
                                    validation=true;
                                }
                            }
                        }
                    }else{
                        if(monthDayValidation(list, n)==true){
                            validation=true;
                        }
                    }
                }
            }
        }
    }
    return validation;
}

bool monthDayValidation(Student *list, int n){
    bool validation=false;
    for(int i=0; i<n; i++){
        //months with 30 days
        if(list[i].birthday.mm==4 || list[i].birthday.mm==6 || list[i].birthday.mm==9 || list[i].birthday.mm==11){
            if(list[i].birthday.dd>0 && list[i].birthday.dd<31){
                validation=true;
            }
        }else{
            //months with 31 days
            if(list[i].birthday.mm==1 || list[i].birthday.mm==3 || list[i].birthday.mm==5 || list[i].birthday.mm==7 || list[i].birthday.mm==8 || list[i].birthday.mm==10 || list[i].birthday.mm==12){
                if(list[i].birthday.dd>0 && list[i].birthday.dd<32){
                    validation=true;
                }
            }
        }
    }
    return validation;
}

bool leapValidation(Student *list, int n){
    bool validation=false;
    for(int i=0; i<n; i++){
        if(list[i].birthday.yy%4==0){
            validation=true;
        }else{
            if(list[i].birthday.yy%400==0 && list[i].birthday.yy%100!=0){
                validation=true;
            }
        }
    }
    return validation;
}

void showReport(Student *list, int n){
    Student temp[n];
    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped=false;
        for(int j=0; j<n-i-1; j++){
            if(list[j].id>list[j+1].id){
                temp[i].id=list[j].id;
                list[j].id=list[j+1].id;
                list[j+1].id=temp[i].id;
                swapped=true;
            }
        }
        if(!swapped) {
            break;
        }
    }
    for(int i=0; i<n; i++){
        cout<<temp[i].id;
        cout<<"\n";
    }
}

void showEightGpa(Student *list, int n){
    cout<<endl;
    for(int i=0; i<n; i++){
        if(list[i].gpa>8.5){
            cout<<list[i].id<<"  "<<list[i].name<<"  "<<list[i].gpa;
        }
    }
}

void studentSituation(Student*list, int n){
    bool aproved=false, found=false;
    int searchId=0;
    cout<<"Enter the id student: ";
    cin>>searchId;
    for(int i=0; i<n; i++){
        if(list[i].id==searchId){
            found=true;
            if(list[i].gpa<7 && list[i].missings>16){
                aproved=false;
            }else{
                aproved=false;
            }
            if(aproved==true){
                cout<<list[i].id<<" "<<list[i].name<<" "<<list[i].gpa<<" "<<list[i].missings<<" "<<"Aproved";
            }else{
                if(aproved==false){
                    cout<<list[i].id<<" "<<list[i].name<<" "<<list[i].gpa<<" "<<list[i].missings<<" "<<"Reproved";
                }
            }
        }
    }
    if(found==false){
        cout<<"The student has not been found!";
    }
}

void showLeapStudents(Student *list, int n){
    for(int i=0; i<n; i++){
        if(list[i].birthday.yy%4==0){
            cout<<list[i].id<<" "<<list[i].name;
        }else{
            if(list[i].birthday.yy%400==0 && list[i].birthday.yy%100!=0){
                cout<<list[i].id<<" "<<list[i].name;
            }
        }
    }
}

void groupalReport(Student *list, int n){
    bool aproved=false;
    cout<<endl;
    for(int i=0; i<n; i++){
        if(list[i].gpa<7 && list[i].missings>16){
            aproved=false;
        }else{
            aproved=false;
        }
        if(aproved==true){
            cout<<list[i].id<<" "<<list[i].name<<" "<<list[i].gpa<<" "<<list[i].missings<<" "<<"Aproved";
        }else{
            if(aproved==false){
                cout<<list[i].id<<" "<<list[i].name<<" "<<list[i].gpa<<" "<<list[i].missings<<" "<<"Reproved";
            }
        }
    }
}