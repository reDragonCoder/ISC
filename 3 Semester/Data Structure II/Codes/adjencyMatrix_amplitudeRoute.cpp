// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iomanip>
#include <queue>

//NAMESPACE
using namespace std;

//PROTOTYPES
int** fill(int n);
void print(int **mat, int n);
void delitation(int **mat, int n);
void printParents(int parents[], int n);

//MAIN
int main(){
    int n=0, c=0;
    int **mat;
    bool *visited;
    queue <int> k;
    cout<<endl<<"How many nodes would you like the graph to have? "<<endl;
    cin>>n;

    int parents[n];
    
    mat=fill(n);
    print(mat,n);
    visited=new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
        parents[i]=0;
    }
    
    visited[0]=true;
    k.push(0);//start on A - 0
    while(!k.empty()){
        parents[c]=k.front();
        k.pop();
        c++;
        for(int i=0; i<n; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j]==1){
                    if (visited[j]==false){
                        visited[j]=true;
                        k.push(j);
                    }
                }
                
            }
        }
        cout<<endl;
    }
    printParents(parents,n);
    delitation(mat, n);
    return 0;
}

//IMPLEMENTATIONS
int** fill(int n){
    int **mat;
    char letter;
    char sletter;
    mat=new int*[n];
    for(int i=0; i<n; i++){
        mat[i]=new int[n];
        for(int j=0; j<n; j++){
            mat[i][j]=0;
        }
    }
    
    cout<<endl<<"Please fill out all of the conecting edges in the graph: ";
    for(int r=0; r<n; r++){
        letter=65+r;
        sletter=65;
        for(int c=0; c<n; c++){
            if(r==c){
                mat[r][c]=0;
                sletter++;
            }else{
                //mat[r][c]=1; TESTING MODULE
                cout<<endl<<"["<<letter<<"] -> ["<<sletter<<"]: ";
                cin>>mat[r][c];
                sletter++;
            }
        }
    }
   
    return mat;
}

void print(int **mat, int n){
    int i,j;
    cout<<endl;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<setw(5)<<mat[i][j];
        }
        cout<<endl;
    }
}

void delitation(int **mat, int n){
    for(int i=0; i<n; i++){
        delete[] mat[i];
    }
    delete[] mat;  
}

void printParents(int parents[], int n){
    int i;
    cout<<endl<<"The sequence of the visit was: ";
    for(i=0; i<n; i++){
        cout<<parents[i]<<" ";
    }
}