// Author: reDragonCoder
//BINARY SEARCH TREE - METHOD 1

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCTURES
struct Node{
	int info;
	Node *left, *right;
};

//FUNCTIONS
Node *newNode(int info){
	Node *neweishon=new Node;
	neweishon->info=info;
	neweishon->left=neweishon->right=nullptr;
	return neweishon; 
}

Node *insert(Node *root, int n){
	if(root==nullptr) 
		return newNode(n);
	if(n<root->info)
		root->left=insert(root->left, n);
	else 
		root->right=insert(root->right, n);

	return root;
}

Node *search(Node * root, int n){
	if(root==nullptr || root->info==n)
		return root;
	if(root->info<n)
		return search(root->right, n);
	return search(root->left, n);
}


void inOrder(Node *Node){
	if(Node!=nullptr){
		inOrder(Node->left);
		cout<<Node->info<<" ";
		inOrder(Node->right);
	}
}

void seeTree(Node *Node, int n) {
	if(Node==nullptr)
		return;
	seeTree(Node->right, n+1);
	for(int i=0; i<n; i++)
		cout<<"  ";
	cout<<Node->info<<endl;
	seeTree(Node->left, n+1);
}

//MAIN
int main(){
	Node *tree=nullptr; //creating tree
	int n;

	do{
		cin>>n;
		if(n==0) break;
		tree=insert(tree, n);
	}while(true);

	cout<<"\n Showing pNode \n";
	seeTree(tree, 0);

	cout<<"\n pNode paths";
	cout << "\n\n In order:  ";   
	inOrder(tree);
	cout<<endl;

	cin>>n;
	Node *t=search(tree, n);
	cout<<"\nI found "<< t->info<<endl;

	return 0;
}