// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <time.h>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    srand(time(NULL));
    set<int> setI;
    vector<int> vecI;
    int temp;

    for(int i=0; i<50; i++){
        temp=rand()%(100+1-1)+1;
        setI.insert(temp);
    }

    cout<<endl<<"Numbers in the set: "<<endl;
    for(auto var:setI)
        cout<<var<<" ";

    temp=1;
    for(int i=0; i<100; i++){
        auto here=setI.find(temp);
        if(here==setI.end()){
            vecI.push_back(temp);
        }
        temp++;
    }

    cout<<endl<<endl;
    cout<<"Numbers in the vector (that are missing in the set): "<<endl;
    for(auto i:vecI){
        cout<<i<<" ";
    }

    return 0;
}
