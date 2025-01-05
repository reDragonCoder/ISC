// Author: reDragonCoder
//LINKED LIST THAT WORKS AS A PRIORITY QUEUE

//LIBRARIES
#include <iostream>
#include <string>

//NAMESPACE
using namespace std;

//CLASSES
class Task{
    public:
        int priority;
        string name;
        
        Task(int p, const string& n):priority(p), name(n){}
};

class Node{
    public:
        Task task;
        Node* next;

        Node(const Task& t):task(t), next(nullptr){}
};

class PriorityQueue{
    private:
        Node* start;

    public:
        PriorityQueue():start(nullptr){}

        ~PriorityQueue(){
            while(!isEmpty()){
                deleteMin();
            }
        }

        void insert(int priority, const string& name){
            Task newTask(priority, name);
            Node* newNode=new Node(newTask);

            if(start==nullptr || start->task.priority>newTask.priority){
                newNode->next=start;
                start=newNode;
            }else{
                Node* actual=start;
                while(actual->next!=nullptr && actual->next->task.priority<newTask.priority){
                    actual=actual->next;
                }
                newNode->next=actual->next;
                actual->next=newNode;
            }
        }

        Task* obtainMin(){
            if(!isEmpty()){
                return &start->task;
            }
            return nullptr; 
        }

        void deleteMin(){
            if(!isEmpty()){
                Node* nodeToEliminate=start;
                start=start->next;
                delete nodeToEliminate; 
            }
        }

        bool isEmpty()const{
            return start==nullptr;
        }

        void print() const{
            Node* actual=start;
            cout<<endl<<"Actual priority queue:\n";
            while(actual!=nullptr){
                cout<<"Task "<<actual->task.name<<" [Priority "<<actual->task.priority<< "]\n";
                actual=actual->next;
            }
            if(isEmpty()){
                cout<<"La cola está vacía.\n";
            }
        }
};

//MAIN
int main(){
    //variables
    int opc, priority;
    string taskName;
    PriorityQueue queue;
    
    do{
        cout<<endl<<"MENU"<<endl;
        cout<<"Insert a task...........................................1"<<endl;
        cout<<"Show the task with the highest priority.................2"<<endl;
        cout<<"Delete the task with the highest priority...............3"<<endl;
        cout<<"Verify queue emptiness..................................4"<<endl;
        cout<<"Exit....................................................5"<<endl;
        cout<<endl<<"Select your option: ";
        cin>>opc;
        cin.ignore();
        switch(opc){
            case 1:{
                cout<<endl<<"What is the priority of the task?: ";
                cin>>priority;
                cin.ignore();
                cout<<"What is the name of the task?: ";
                getline(cin, taskName);
                queue.insert(priority,taskName);
                queue.print();
                break;
            }
            case 2:{
                Task *minTask=queue.obtainMin();
                if(minTask){
                    cout<<"The minimum element in the queue is: "<<minTask->name<<" [Priority "<<minTask->priority<< "]"<<endl;
                }else{
                    cout<<"The queue is empty!"<< endl;
                }
                break;
            }
            case 3:{
                queue.deleteMin();
                cout<<endl<<"Deleting task...";
                if (!queue.isEmpty()){
                    queue.print();
                } else {
                    cout<<endl<<"Your queue is now empty!"<<endl;
                }
                break;
            }
            case 4:{
                if (queue.isEmpty()){
                    cout<<endl<<"Your queue is currently empty!"<<endl;
                } else {
                    cout<<endl<<"Your queue is NOT empty!"<<endl;
                }
                break;
            }
        }
    } while(opc!=5);
    
    return 0;
}