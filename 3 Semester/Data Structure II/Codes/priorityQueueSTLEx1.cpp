// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>
#include <queue>

//NAMESPACE
using namespace std;

//CLASS
class Patient{
    public:
        string name;
        int age;
        long long int famPhone;
        int turn;
        int emergencyLevel;

        Patient(string name, int age, long long famPhone, int turn, int emergencyLevel)
        :name(name), age(age), famPhone(famPhone), turn(turn), emergencyLevel(emergencyLevel){}
};

//STRUCT
struct compare{
    bool operator()(const Patient &p1, const Patient &p2){
        if(p1.emergencyLevel!=p2.emergencyLevel)
            return p1.emergencyLevel<p2.emergencyLevel;
        return p1.turn>p2.turn;
    }
};

//MAIN
int main(){
    vector<Patient> v{{"Cesar", 18, 4491819453, 1, 20}, {"Fer", 21, 4491634578, 2, 20}, {"Darely", 19, 4497563210, 3, 100}};

    priority_queue<Patient, vector<Patient>, compare> pp;

    for(auto i:v){
        pp.push(Patient(i.name, i.age, i.famPhone, i.turn, i.emergencyLevel));
    }

    while(!pp.empty()){
        Patient p=pp.top();
        pp.pop();
        cout<<p.name<<" "<<p.age<<" "<<p.famPhone<<" "<<p.turn<<" "<<p.emergencyLevel<<"\n";
    }

    return 0;
}