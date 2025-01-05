// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <fstream>
#include <string>

//NAMESPACE
using namespace std;

//CLASSES
class Data{
    private:
        ifstream file;  

    public:
        bool open(const string& nameFile) {
            file.open(nameFile);  
            return file.is_open(); 
        }

        void close() {
            file.close();
        }

        void isCorrect() {
            string line;

            while(getline(file, line)){
                for(char ch:line) {
                    if(ch!='(' && ch!=')' && ch!='[' && ch!=']' && ch!='\n' && ch!=' '){
                        if(ch=='a' || ch=='b'){
                            cout<<"YES"<<endl;
                        } else {
                            cout<<"NO"<<endl;
                        }
                    }
                }
            }
        }
};

//MAIN
int main(){
    string nameFile="file.txt";  

    Data obj;
    bool band=obj.open(nameFile);  

    if(band){
        obj.isCorrect(); 
        obj.close();  
    }else{
        cout<<"ERROR: FILE NOT FOUND!"<<endl; 
    }

    return 0;
}
