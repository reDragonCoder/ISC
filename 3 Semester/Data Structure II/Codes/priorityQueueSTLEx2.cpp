// AUthor: reDragonCoder

//LIBRARIES
#include <iostream>
#include <queue>
#include <vector>

//NAMESPACE
using namespace std;

//CLASS
class Person{
    public:
        int age;
        float weight;

        Person(int age, float weight):age(age), weight(weight){}
};

//STRUCT
struct compare{
    bool operator()(const Person &p1, const Person &p2){
        if(p1.weight!=p2.weight)
            return p1.weight>p2.weight;
        return p1.age<p2.age;
    }
};

//MAIN
int main(){
    vector<Person> v{{30, 55.5}, {25, 55}, {20, 60}, {33,60.1}, {23, 55.6}, {27, 55}};
    priority_queue<Person, vector<Person>, compare> pp;

    for(auto i:v){
        pp.push(Person(i.age, i.weight));
    }
    while(!pp.empty()){
        Person p=pp.top();
        pp.pop();
        cout<<p.age<<" "<<p.weight<<"\n";
    }
    return 0;
}