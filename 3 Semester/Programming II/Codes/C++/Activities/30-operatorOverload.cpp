// Author: reDragonCoder
//OPERATOR OVERFLOW

//LIBRARIES
#include <iostream>
#include <fstream>
#include <cstring>

//NAMESPACE
using namespace std;

//CLASS
class Chain{
    private:
        string ch;
    
    public:
        Chain(){}

        Chain(string text){this->ch=text;}

        string getCh(){
            return this->ch;
        }

        Chain operator+(Chain tempObj){
            Chain temp;
            temp.ch=this->ch+tempObj.ch;
            return temp;
        }

        bool operator!=(Chain tempObj){
            if(this->ch!=tempObj.ch)
                return false;
            else
                return true;
        }

        string operator+=(Chain tempObj){
            string temp;
            temp=this->ch;
            temp=temp+tempObj.ch;
            this->ch=temp;
            return temp;
        }

        ~Chain(){}
};

//MAIN
int main(){
    Chain ch1("juana ");
    Chain ch2("diana ");
    Chain ch3("pedro ");

    Chain sum;
    sum=ch1+ch2;
    cout<<sum.getCh()<<endl;

    Chain ch4("dianita");
    if(ch4!=ch2)
        cout<<"They're the same"<<endl;
    else
        cout<<"They're different"<<endl;
    
    Chain c1("poker ");
    Chain c2("blackJack ");
    c1+=c2;
    cout<<c1.getCh()<<endl;

    Chain ch5;
    ch5=ch1+ch2+ch3;
    cout<<ch5.getCh();
}