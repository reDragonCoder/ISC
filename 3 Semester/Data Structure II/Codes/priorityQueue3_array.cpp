// Author: reDragonCoder

//LIBRARIES
#include<iostream>
using namespace std;

//GLOABL CONSTANTS
#define MAX_NUM 3 

//STRUCTS
struct Task{
    int priority;
    string task;
};

struct PriorityQueue{
    Task *queue;
    int nData, nDataActual;
};

PriorityQueue pq;

//FUNCTIONS
void Constructor(){
    pq.nData=MAX_NUM;
    pq.queue=new Task [pq.nData];
    pq.nDataActual=0;
}

void Constructor(int n){
    pq.nData=n;
    pq.queue=new Task [pq.nData];
    pq.nDataActual=0;    
}

void insert(Task t){
    int i=0;
    bool found=false;
    while(!found && i<pq.nDataActual)
        if (pq.queue[i].priority<t.priority)
            i++;
        else
            found=true;
    if(pq.nDataActual<pq.nData) {
        for(int j=pq.nDataActual; j>i; j--)
            pq.queue[j]=pq.queue[j-1];
        pq.queue[i]=t;
        pq.nDataActual++;
    }else 
        cout<<"Full queue";
}

Task minElement(){
    if(pq.nDataActual>0)
        return pq.queue[0];
    else
        cout<<"Empty queue";
    Task t;
    t.task="Empty";
    return t;
}

void eliminateMin(){
    if(pq.nDataActual>0){
        for(int i=1; i<pq.nDataActual; i++)
            pq.queue[i-1] = pq.queue[i];
        pq.nDataActual--;
    } else
        cout<<"queue empty";
}

bool empty(){
    return pq.nDataActual==0;
}

//MAIN
int main(){
    Constructor(MAX_NUM);
    Task p;
    for(int i=0; i<MAX_NUM; i++){
        cout<<"Process-Priority: ";
        cin>>p.task>>p.priority;
        insert(p);
    }
    cout<<"In queue \n";
    while(!empty()){
        p=minElement();
        cout<<p.task<<" "<<p.priority<<endl;
        eliminateMin();
    }
}