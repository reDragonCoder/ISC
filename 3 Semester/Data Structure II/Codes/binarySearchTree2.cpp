// Author: reDragonCoder
//BINARY SEARCH TREE - METHOD 2

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCTURES
struct Node{
     int info;
     struct Node *left, *right;
};

//DATA TYPE DEFINITION
typedef Node *pNode;

//PROTOTYPES-IMPLEMENTATIONS
pNode createNode(int x){
     pNode neweishon=new(struct Node);
     neweishon->info=x;
     neweishon->left=NULL;
     neweishon->right=NULL;

     return neweishon;
}
void insert(pNode &tree, int x){
     if(tree==NULL) 
           tree=createNode(x);
     else if(x<tree->info)
          insert(tree->left, x);
     else if(x>tree->info)
          insert(tree->right, x);
}

void inOrder(pNode tree){
     if(tree!=NULL){
          inOrder(tree->left);
          cout<<tree->info<< " ";
          inOrder(tree->right);
     }
}

void seeTree(pNode tree, int n){
     if(tree==NULL)
          return;
     seeTree(tree->right, n+1);
     for(int i=0; i<n; i++)
         cout<<"   ";
     cout<<tree->info <<endl;
     seeTree(tree->left, n+1);
}

//MAIN
int main(){
    pNode tree=NULL;   //creating tree

    int n;

    do{
        cin>>n;
        if(n==0) break;
        insert(tree, n);
    }while(true);

    cout<<"\n Showing pNode \n";
    seeTree(tree, 0);

    cout<<"\n\n In order:  ";   inOrder(tree);

    cout<<endl<<endl;

    return 0;
}