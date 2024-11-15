// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//NAMESPACE
using namespace std;

//CLASSES
class Data{
    public:
        int age;
        string name;
};

//FUNCTIONS
bool compare(const Data &a, const Data &b){
    if(a.age!=b.age) return a.age<b.age;
        return a.name<b.name;
}

bool minor(const Data &a, const Data &b){
    return a.age<b.age;
}

void print(const vector<Data> &v){
    for(int j=0; j<v.size(); j++){
        toupper(v[j].name[0]);
    }
}

int main(){
    vector<Data> group;

    for(int i=0; i<3; i++){
        Data x;
        cin>>x.age;
        cin>>x.name;
        group.push_back(x); //to fill the vector
    }
    print(group);

    //sorting algorithm in the "algorithm" library
    sort(group.begin(), group.end(), compare);

    //container iterator
    for(vector<Data>::iterator i=group.begin(); i!=group.end(); i++){
        cout<<i->age<<" "<<i->name<<endl;
    }

    //extract the smallest element from the container
    vector<Data>::iterator i=min_element(group.begin(), group.end(), minor);
    cout<<"Minor "<<i->name<<endl;

    int t[]={2, 4, 1, 5, 7};
    //passes the array values ​​to the object
    vector<int> v(t, t+sizeof(t)/sizeof(t[0]));

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
}