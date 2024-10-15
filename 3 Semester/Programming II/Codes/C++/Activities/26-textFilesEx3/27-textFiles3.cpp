// Author: reDragonCoder
//ITEM ARRAY, ASK SPECIFIC ITEM BY ID OR PRICE

//LIBRARIES
#include <iostream>
#include <fstream>
#include <string>

//NAMESPACE
using namespace std;

//CLASSES
class Item{
    private:
        int id;
        string name;
        double price;
        int stock;

        fstream file; 
    public:
        Item(){}

        Item(int id, string name, double price, int stock){
            this->id=id;
            this->name=name;
            this->price=price;
            this->stock=stock;
        }

        ~Item(){};

        bool openRead(char *fileName){
            bool flag=true;
            file.open(fileName, ios::in); 
            if(!file)
                flag=false;
            return flag;
        }

        bool readItem(const string& line) {
            int state=0; // 0-ID, 1-Name, 2-Price, 3-Stock
            string temp;
            for(char c:line){
                if(c==' ') {
                    switch(state){
                        case 0:
                            this->id=stoi(temp);
                            break;
                        case 1:
                            this->name=temp;
                            break;
                        case 2:
                            this->price=stod(temp);
                            break;
                    }
                    temp=" ";
                    state++;
                }else{
                    temp+=c;
                }
            }
            if(state==3){
                this->stock=stoi(temp);
                return true;
            }
            return false; 
        }

        void displayItem(){
            cout<<"ID: "<<id<<"\t\tName: "<<name<<"\t\tPrice: "<<price<<"\t\tStock: "<<stock<<endl;
        }

        int getId(){
            return id;
        }

        double getPrice(){
            return price;
        }
};

int menu(){
    int op;
    cout<<endl;
    do{
        cout<<endl<<"---MENU---";
        cout<<endl<<"1. Print item array";
        cout<<endl<<"2. Search by ID";
        cout<<endl<<"3. Search by price";
        cout<<endl<<"4. Exit";
        cout<<endl<<endl<<"Select yout option: ";
        cin>>op;
        if(op<1 || op>4)
            cout<<endl<<"Error!";
    }while(op<1 || op>4);
    return op;
}

//MAIN
int main(){
    //variables
    char fileName[]="items.txt";
    Item items[100];
    string line;
    bool flag;
    int i=0, op=0;

    ifstream file("items.txt");
    if(!file){
        cout<<"Error: File not found!"<<endl;
        exit(1);
    }

    while(getline(file, line) && i<100){
        if(items[i].readItem(line)){
            i++;
        }
    }

    do{
        op=menu();
        switch(op){
            case 1:{
                for(int k=0; k<i; k++){
                    items[k].displayItem();
                }
                cout<<endl;
            }
                break;
            case 2:{
                int id=0;
                bool found=false;
                cout<<"Enter the ID you want to search for: ";
                cin>>id;
                for(int k=0; k<i; k++){
                    if(items[k].getId()==id){
                        cout<<endl;
                        items[k].displayItem();
                        cout<<endl;
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"The ID you searched for does not exists"<<endl;
                }
            }
                break;
            case 3:{ 
                double upperLim, lowLimit;
                bool found=false;
                cout<<"Enter the lower price limit: ";
                cin>>lowLimit;
                cout<<"Enter the higher price limit: ";
                cin>>upperLim;
                for(int k=0; k<i; k++){
                    if(items[k].getPrice()>=lowLimit && items[k].getPrice()<=upperLim){
                        items[k].displayItem();
                        cout<<endl;
                        found=true;
                    }
                }
                if(!found){
                    cout<<"There's no product that matches with that price range"<<endl;
                }
            }
                break;
            case 4:{ 
                cout<<endl<<"Goodbye! :)";
            }
        }
    }while(op!=4);

    file.close();

    return 0;
}