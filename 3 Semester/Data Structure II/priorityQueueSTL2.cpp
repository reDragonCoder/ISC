// AUthor: reDragonCoder

//LIBRARIES
#include <iostream>
#include <queue>

//NAMESPACE
using namespace std;

struct compare{
    bool operator()(const int &l, const int &r){
        return l>r;
    }
};

//MAIN
int main(){
    priority_queue<int, vector<int>, compare> pq;
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(8);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}