// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iterator>
#include <iomanip>
#include <map>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    int tc, treeCounter=0;
    string blankSpace, tree;
    map<string, double> map1;

    cout<<"Enter the number of testcases: ";
    cin>>tc;

    while(tc--){
        cin.ignore();
        cout<<endl<<"Write the tree names & press * when you're done"<<endl;
        treeCounter=0;

        do{
            getline(cin, tree);
            if(tree!="*"){
                auto it=map1.find(tree);
                if(it!=map1.end()){
                    it->second++;
                }else{
                    map1[tree]=1;
                }
            }
            treeCounter++;
        }while(tree!="*");

        cout<<endl;
        treeCounter--;

        for(auto i:map1){
            cout<<i.first;
            cout<<" ";
            cout<<fixed<<setprecision(4)<<(i.second*100)/treeCounter;
            cout<<endl;
        }

        cout<<endl;
        treeCounter=0;
        map1.clear();
    }

    return 0;
}
