// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <set>

//NAMESPACE
using namespace std;

//CLASS
class Friend{
public:
    int age;
    string name;
    
    void print() const{
        cout<<"[ Friend name = "<<name<<", age = "<<age<< "]\n";
    }

    bool operator<(const Friend& otro) const{
        return(this->age>otro.age);
    }
};

//MAIN
int main() {
    set<Friend> b={{17, "Luis"}, {19, "Karla"}};
    Friend a;
    cin>>a.age;
    cin>>a.name;
    b.insert(a);
    for(auto& bh:b)
        bh.print();
    
    return 0;
}
