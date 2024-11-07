// Author: reDragonCoder

//LIBRARIES
#include <vector>
#include <iostream>
#include <list>
#include <queue>

//NAMESPACE
using namespace std;

//FUNCTIONS
void printStrCin(vector< list<int>> &temp, int vertices){
    vector <bool> boolVec(vertices,false);
    for(int i=0; i< vertices; i++) 
        if(boolVec[i]==false){
        cout<<i<<"->";
        for(int& x:temp[i]){
            boolVec[x]=true;
            cout<<x<<"->";
        }
        cout<<endl;
    }
}

bool stronglyConectedComp(vector<vector<int>> &accessMat, int s, int e){
    vector <int> aux(accessMat.size(),-1);
    vector <int> temp(accessMat.size(),-1);
    bool yup;

    for(int i=0; i<accessMat.size(); i++){
        aux[i]=accessMat[s][i];
    }

    for(int t=0; t<accessMat.size(); t++){
        temp[t]=accessMat [e][t];
    }

    yup=equal(begin(aux), end(aux), begin(temp));
    return yup;
}

vector<bool> breathFirst(vector<vector<int>> & conections, int s){
    vector<bool> visited(conections.size(),false);
    vector<int> parents(conections.size(),0);
    int c=0;
    visited[s] = true;
    queue<int> stack;
    stack.push(s);
    cout<<endl;
    while(!stack.empty() ){
        int actual = stack.front();
        stack.pop();
        //cout << actual << " ";
        for(int i=0; i < conections.size(); i++ ){
            if( conections[actual][i] && !visited[i] ){
                stack.push(i);
                visited[i]=true;
                parents[i]=actual;
            }
        }
    }
    return visited;
}

vector<vector<int>> accessMatrix(vector<vector<int>> & conections){
    vector<vector<int>> aux;
    aux=vector<vector<int>>(conections.size() ,vector<int> (conections.size(), 0));

    for(int i=0; i<conections.size(); i++){
        vector<bool> temp=breathFirst(conections,i);
        for(int j=0; j<conections.size(); j++){
            if(i==j)
                aux[i][j]=1;
            else if(temp[j]==true){
                aux[i][j]=1;  
            }
        }
    }

    cout<<endl;
    cout<<"The access matrix is: "<<endl;

    for(int i=0; i<conections.size(); i++) {
        for(int j=0; j<conections.size(); j++){
            cout<<aux[i][j]<<" ";
        }
        cout<<endl;
    }
    return aux;
}

//MAIN
int main(){
    int vertices;
    vector<vector<int>> vec;
    cout<<"Please especify how many nodes are in the graph: ";
    cin >> vertices;
    //fill the matrix with 0's
    vector< list<int> > temp;
    vector<bool> visited(vertices,false);

    temp=vector<list<int>>(vertices);
    vec=vector<vector<int>>(vertices ,vector<int> (vertices, 0));

    for(int i=0; i<vec.size(); i++)
        for(int j=0; j<vec.size(); j++){
            cout<<"["<<i<<"]"<<"["<<j<<"]: ";
            cin>>vec[i][j];
    }

    cout<<endl;
    cout<<"The original matrix is: "<<endl;
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec.size(); j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> vec2=accessMatrix(vec);
    cout<<endl;
    for(int i=0; i<vec2.size(); i++) {
        for(int m=i+1; m<vec2.size(); m++){
            if(stronglyConectedComp(vec2, i, m)&&visited[m]==false){
                visited[m]=true;
                temp[i].push_back(m);
            }
        }
    }
    printStrCin(temp,vertices);    
}