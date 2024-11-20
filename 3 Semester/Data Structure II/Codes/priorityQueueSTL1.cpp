// AUthor: reDragonCoder

//LIBRARIES
#include <iostream>
#include <queue>

//NAMESPACE
using namespace std;

//FUNCTION
void displayQueue(priority_queue<int> pq){
    priority_queue<int> pqueue=pq;
    while(!pqueue.empty()){
        cout<<"\t"<<pqueue.top();
        pqueue.pop();
    }
    cout<<"\n";
}

//MAIN
int main(){
    priority_queue<int> pq;
    pq.push(7);
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(9);
    cout<<"The queue size: "<<pq.size();
    cout<<"\nFront element: "<<pq.top();
    cout<<"\nThe priority is: ";
    displayQueue(pq);

    return 0;
}