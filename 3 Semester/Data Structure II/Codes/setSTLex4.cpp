// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <list>
#include <set>

//NAMESPACE
using namespace std;

//CLASS
class QueueNoRepetitions{
    private:
        set<int> set1;
        list<int> list1;

    public:
        void insert(int num){
            auto here=set1.find(num);
            if(here==set1.end()){
                set1.insert(num);
            }

            list1.push_back(num);
        }

        int extract(){
            if(!list1.empty()){
                int num=list1.front();
                list1.pop_front();
                set1.erase(num);
                return num;
            }
            return -1;
        }

        bool isEmpty(){
            if(list1.empty()){
                return true;
            }else{
                return false;
            }
        }

        void showSet(){
            for(auto i:set1){
                cout<<i<<" ";
            }
            cout<<endl<<endl;
        }
};

//MAIN
int main(){
    QueueNoRepetitions test;
    int tempNum;

    cout<<"Write numbers and press '0' when you're done: "<<endl;
    do{
        cin>>tempNum;
        if(tempNum!=0){
            test.insert(tempNum);
        }
    }while(tempNum!=0);
    cout<<endl;

    test.showSet();

    cout<<"Extracting numbers: "<<endl;
    while(test.isEmpty()==false){
        tempNum=test.extract();
        cout<<tempNum<<" ";
    }

    return 0;
}