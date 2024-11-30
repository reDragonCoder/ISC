// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iterator>
#include <map>

//NAMESPACE
using namespace std;

//CLASS
class Datos{
    private: 
        string name;
        int age;
        string phone;
    public:
        Datos(){}

        Datos(string name, int age, string phone):
            name(name), age(age), phone(phone){}

        string getName(){
            return this->name;
        }

        friend ostream &operator<<(ostream &out, Datos & d);
    };

    ostream &operator<<(ostream &out, Datos & d){
        out<<d.name<<" "<<d.age<<" "<<d.phone<< endl;
        return out;
}

//MAIN
int main(){
    Datos a("Pancho", 19, "4491234545");
    Datos b("Angela", 21, "4493214556");
    map<string, Datos> map1;
    map<string, Datos>::iterator cursor;

    map1[a.getName()]=a;
    map1[b.getName()]=b;
    cout<<"Original container"<<endl;
    cout<<"key\telement"<<endl;
    for(cursor=map1.begin(); cursor!=map1.end(); cursor++){
        cout<<cursor->first;
        cout<<'\t'<<cursor->second
             <<endl;
    }
    Datos c("Jorge", 18, "4492113839");
    pair<string, Datos> t(c.getName(), c);
    map1.insert(t);

    cout<<"Uptaded container"<<endl;
    cout<<"key\telement"<<endl;
    for(auto i:map1){
        cout<<i.first;
        cout<<'\t'<<i.second
             <<endl;
    }
}
