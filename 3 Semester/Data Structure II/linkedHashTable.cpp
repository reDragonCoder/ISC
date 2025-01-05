// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <cmath>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANT
#define R 0.6180334 //inverse of the golden ratio 2/(1+sqrt(5))

//STRUCTURE DECLARATION
struct Date{
    int day;
    int month;
    int year;
};

//CLASS DECLARATION
class Member{
    private:
        int code;
        string name;
        int age;
        Date date;
    public:
        //constructors
        Member(){};

        Member(int c, string n, int a, Date d){
            code=c;
            name=n;
            age=a;
            date=d;
        }

        //get methods
        int getCode(){return code;}

        int getAge(){return age;}

        string getName(){return name;}

        Date getDate(){return date;}

        //set methods
        void setCode(int c){code=c;}

        void setAge(int a){age=a;}

        void setName(string n){name=n;}

        void setDate(Date d){date=d;}
};

class Node{
    protected:
        Member member;
        Node *next;
    public:
        //constructors
        Node(){}

        Node(Member m){
            member=m;
            next=NULL;
        }  

        //get methods
        Node* getNext(){return next;}
        Member getMember(){return member;}
        Member* getRawMember(){return &member;}

        //set methods
        void setNext(Node* nxt){next=nxt;}
        void setMember(Member m){member=m;}
};

class HashTable{
    private:
        int end;
        int elementNo;
        Node** table;
    public:
        //constructor
        HashTable(int n){
            elementNo=n;
            table=new Node*[n];
            for(int i=0; i<n; i++){
                table[i]=nullptr;
            }
        }

        ~HashTable(){
            Node* current;
            Node* toDelete;
            for(int i=0; i<elementNo; i++){
                current=table[i];
                while(current!=nullptr){
                    toDelete=current;
                    current=current->getNext(); 
                    delete toDelete;
                }
            }
            delete[] table;
        }

        //methods
        bool validateMember(int code){
            int hash=hashing(code);
            int index=hash%elementNo;
            Node* currentNode=table[index];
            bool validInsertion=false;

            if(currentNode!=nullptr){
                if(currentNode->getMember().getCode()==code){
                    validInsertion=false;
                }
                currentNode=currentNode->getNext();
            }else{
                validInsertion=true;
            }
            return validInsertion;
        }

        void insert(Member member){
            int hash=hashing(member.getCode());
            Node* newNode=new Node(member);
            Node* currentNode;

            if(table[hash]==nullptr){
                table[hash]=newNode;
            }else{
                currentNode=table[hash];
                while(currentNode->getNext()!=nullptr){
                    currentNode=currentNode->getNext();
                }
                currentNode->setNext(newNode);
            }
            cout<<endl<<"Member saved successfully!"<<endl;
        }

        Member* search(int code){
            int hash=hashing(code);
            Node* currentNode=table[hash];
            
            bool found=false;

            if(currentNode!=nullptr){
                if(currentNode->getMember().getCode()==code){
                    return currentNode->getRawMember();
                }
                currentNode=currentNode->getNext();
            }
            return nullptr;
        }

        void eliminate(int code){
            Member* referenceMember=search(code);
            int hash=hashing(code);
            Node* currentNode=table[hash];
            Node* previousNode=nullptr;
            char ans;
            if(referenceMember==nullptr){
                cout<<endl<<"ERROR: The member does not exists!"<<endl;
            }else{
                cout<<endl<<"Printing member data..."<<endl;
                cout<<"Code: "<<referenceMember->getCode()<<endl;
                cout<<"Name: "<<referenceMember->getName()<<endl;
                cout<<"Age: "<<referenceMember->getAge()<<endl;
                cout<<"Date: "<<endl;
                cout<<"--> Day: "<<referenceMember->getDate().day<<endl;
                cout<<"--> Month: "<<referenceMember->getDate().month<<endl;
                cout<<"--> Year: "<<referenceMember->getDate().year<<endl;
                do{
                    cout<<endl<<"Are you sure you want to delete this member? y/n: ";
                    cin>>ans;
                    if(ans!='y' && ans!='n'){
                        cout<<endl<<"ERROR: Please enter a valid option!"<<endl;
                    }
                }while(ans!='y' && ans!='n');
                if(ans=='n'){
                    cout<<endl<<"Canceling operation..."<<endl;
                }else if(ans=='y'){
                    while(currentNode!=nullptr){
                        if(currentNode->getMember().getCode()==code){
                            if(previousNode==nullptr){
                                table[hash]=currentNode->getNext();
                            }else{
                                previousNode->setNext(currentNode->getNext());
                            }
                            delete currentNode;
                            cout<<"Member deleted successfully"<<endl;
                            return;
                        }
                        previousNode=currentNode;
                        currentNode=currentNode->getNext();
                    }
                }
            }
        }
    
    private:
        int hashing(long x){
            double mult=0, d=0;
            int hx=0, m=elementNo;
            mult=R*x;
            d=mult-trunc(mult);
            hx=trunc(m*d);
            return hx;
        }
};

//functions
int menu(){
    int opt;
    cout<<endl<<endl;
    cout<<"--------- MENU ---------"<<endl;
    cout<<"1. Add a member"<<endl;
    cout<<"2. Search a member"<<endl;
    cout<<"3. Delete a member"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<endl<<"Please enter one option: ";
    cin>>opt;
    return opt;
}

bool monthDayValidation(int day, int month){
    bool validation=false;
    //months with 30 days
    if(month==4 || month==6 || month==9 || month==11){
        if(day>0 && day<31){
            validation=true;
        }
    }else{
        //months with 31 days
        if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
            if(day>0 && day<32){
                validation=true;
            }
        }
    }
    return validation;
}

bool leapValidation(int year){
    bool validation=false;
    if(year==0){
        validation=true;
    }else{
        if(year%400==0 && year%100!=0){
            validation=true;
        }
    }
    return validation;
}

bool dateValidation(int day, int month, int year){
    bool validation=false;
    if(year>=1924 && year<=2024){
        if(month>0 && month<13){
            if(day>0 && day<32){
                if(month==2){
                    if(day<29){
                        validation=true;
                    }else{
                        if(day==29){
                            if(leapValidation(year)==true){
                                validation=true;
                            }
                        }
                    }
                }else{
                    if(monthDayValidation(day, month)==true){
                        validation=true;
                    }
                }
            }
        }
    }
    return validation;
}

//MAIN
int main(){
    int n=0, opt=0;
    Member tempMember;
    Member* referenceMember;
    int code, age;
    string name;
    Date date;
    bool validDate;
    
    cout<<endl<<"\033[1;94mWELCOME TO LA PARRA MEMBER SYSTEM\033[0m"<<endl<<endl;
    cout<<"Please enter the max. number of members you want to add to the database: ";
    cin>>n;
    cout<<endl;
    HashTable table(n);

    do{
        opt=menu();
        switch(opt){
            case 1:
                cout<<endl<<"Capturing new member information..."<<endl;
                do{
                    cout<<"Member code: ";
                    cin>>code;
                    if(code<101 || code>1999){
                        cout<<endl<<"ERROR: Please enter a valid code!"<<endl;
                    }
                    if(table.validateMember(code)==false){
                        cout<<endl<<"ERROR: The entered code is already used!"<<endl;
                    }
                }while(code<100 || code>1999 || table.validateMember(code)==false);
                cout<<"Name: ";
                cin>>name;
                do{
                    cout<<"Age: ";
                    cin>>age;
                    if(age<0 || age>99){
                        cout<<endl<<"ERROR: Please enter a valid age between 1 & 99!"<<endl;
                    }
                }while(age<0 || age>99);
                do{
                    cout<<"Date: "<<endl;
                    cout<<"--> Day: ";
                    cin>>date.day;
                    cout<<"--> Month: ";
                    cin>>date.month;
                    cout<<"--> Year: ";
                    cin>>date.year;
                    validDate=dateValidation(date.day, date.month, date.year);
                    if(validDate==false){
                        cout<<"ERROR: Please enter a valid date!"<<endl;
                    }
                }while(validDate==false);
                tempMember.setCode(code);
                tempMember.setName(name);
                tempMember.setAge(age);
                tempMember.setDate(date);
                table.insert(tempMember);
                break;

            case 2:
                cout<<endl<<"Enter the code you want to search for: ";
                cin>>code;
                referenceMember=table.search(code);
                if(referenceMember==nullptr){
                    cout<<endl<<"Member not found!"<<endl;
                }else{
                    cout<<"Member found!"<<endl<<endl;
                    cout<<"Printing member data..."<<endl;
                    cout<<"Code: "<<referenceMember->getCode()<<endl;
                    cout<<"Name: "<<referenceMember->getName()<<endl;
                    cout<<"Age: "<<referenceMember->getAge()<<endl;
                    cout<<"Date: "<<endl;
                    cout<<"--> Day: "<<referenceMember->getDate().day<<endl;
                    cout<<"--> Month: "<<referenceMember->getDate().month<<endl;
                    cout<<"--> Year: "<<referenceMember->getDate().year<<endl;
                }
                break;

            case 3:
                cout<<endl<<"Enter the code you want to search for: ";
                cin>>code;
                table.eliminate(code);
                break;
        }
        if(opt==4){
            cout<<endl<<"\033[1;94mGoodbye user!\033[0m"<<endl;
        }
    }while(opt!=4);

    return 0;
}
