// Author: reDragonCoder
//COUNTING CHARACTERS, WORDS & LINES

//LIBRARIES
#include <iostream>
#include <windows.h>
#include <fstream>

//NAMESPACE
using namespace std;

//CLASS
class Data{
    private:
        fstream file;
    public:
        bool open(char mode, char *fileName){
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

        int readCharacter(){
            char c;
            int characters=0;
            file.clear();
            file.seekg(0);
            while(file.get(c)){
                characters++;
                cout<<c;
                Sleep(10);
            }
            cout<<endl;
            return characters;
        }

        int readWord(){
            char word[30];
            int words=0;
            file.clear();
            file.seekg(0);
            while(file>>word){
                words++;
            }
            return words;
        }

        int readLine(){
            char line[150];
            int lines=0;
            file.clear();
            file.seekg(0);
            while(file.getline(line, 150)){
                lines++;
            }
            return lines;
        }
};

//MAIN
int main(){
    //variables
    int characters=0, words=0, lines=0;
    Data obj;
    bool flag=0;
    char file[100]="textFilesEx1.txt";

    flag=obj.open('l', file);
    if(flag==true){
        cout<<endl;
        cout<<endl<<"The number of characters in the file is: "<<obj.readCharacter()<<endl;
        cout<<"The number of words in the file is: "<<obj.readWord()<<endl;
        cout<<"The number of lines in the file is: "<<obj.readLine()<<endl;
        obj.close();
    }else{
        cout<<endl<<"Error: File not found!";
    }

    return 0;
}