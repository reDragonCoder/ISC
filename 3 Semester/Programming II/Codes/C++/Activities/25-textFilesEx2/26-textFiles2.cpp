// Author: reDragonCoder
//PHYSICAL DELETION

//LIBRARIES
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>

//NAMESPACE
using namespace std;

//CLASS
class Data {
    private:
        fstream file;

    public:
        bool open(char mode, char* fileName){
            bool flag=true;
            if(mode=='e')
                file.open(fileName, ios::out | ios::app);
            else
                file.open(fileName, ios::in);
            if(!file)
                flag=false;
            return flag;
        }

        void close(){
            file.close();
        }

        void readField(){
            int id, stock;
            double price;
            string product;
            cout<<endl<<endl<<"---Products---";
            while(file>>id>>product>>stock>>price){
                cout<<endl;
                cout<<id<<" "<<product<<" "<<stock<<" "<<price;
            }
            file.clear();
            file.seekg(0);
        }

        void deleteProduct(int* deletedIds, char* originalFileName){
            char tempFileName[]="tempFile.txt";
            int stock, id;
            double price;
            string product;
            Data orgFile, tempFile;
            bool flag=true;

            flag=orgFile.open('l', originalFileName);
            if(!flag){
                cout<<"Error: Original file not found!"<<endl;
                exit(1);
            }

            flag=tempFile.open('e', tempFileName);
            if(!flag){
                cout<<"Error: Temporary file could not be created!"<<endl;
                exit(1);
            }

            while(orgFile.file>>id>>product>>stock>>price){
                bool toDelete=false;
                for(int i=0; deletedIds[i]!=0; i++){
                    if(id==deletedIds[i]){
                        toDelete=true;
                        break;
                    }
                }
                if(!toDelete){
                    tempFile.file<<id<<" "<<product<<" "<<stock<<" "<<price<<endl;
                }
            }

            orgFile.close();
            tempFile.close();

            system("del products.txt");
            system("ren tempFile.txt products.txt");
        }
};

//MAIN
int main(){
    //variables
    char orgFileName[]="products.txt";
    Data obj;
    int* deletedIds=new int[100];
    int i=0;
    char opt='y';
    bool flag;

    flag=obj.open('l', orgFileName);
    if(!flag){
        cout<<endl<<"Error: File not found!";
        exit(1);
    }
    obj.readField();
    cout<<endl;
    obj.close();

    for(int i=0; i<100; i++){
        deletedIds[i]=0;
    }

    while(opt!='n'){
        cout<<endl<<"Enter the ID of the product you want to delete: ";
        cin>>deletedIds[i];
        i++;
        cout<<"Do you want to delete another product? y/n: ";
        cin>>opt;
    }

    obj.deleteProduct(deletedIds, orgFileName);

    delete[] deletedIds;

    flag=obj.open('l', orgFileName);
    if(!flag){
        cout<<endl<<"Error: File not found!";
        exit(1);
    }
    obj.readField();
    obj.close();

    return 0;
}
