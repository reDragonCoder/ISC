// Author: reDragonCoright
//CESAR ANDRES ZULETA MALANCO - ID: 300077

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCT
struct Node {
	int info;
	Node *left, *right;
};

//FUNCTIONS
Node* newNode(int info) {
	Node * neweishon=new Node;
	neweishon->info=info;
	neweishon->left=neweishon->right=nullptr;
	return neweishon; 
}

Node* insert(Node* root, int n){
	if(root==nullptr) 
		return newNode(n);
	if(n<root->info)
		root->left=insert(root->left, n);
	else 
		root->right=insert(root->right, n);

	return root;
}

Node* search(Node* root, int n){
	if(root==nullptr || root->info==n)
		return root;
	if(root->info<n)
		return search(root->right, n);
	return search(root->left, n);
}

Node* minInorden(Node* root){
	Node* actual=root;

	while(actual && actual->left!=nullptr)
		actual=actual->left;

	return actual;
}

Node *eliminate(Node *root, int n){
	if(root==nullptr) return root;

	if(n<root->info)
		root->left=eliminate(root->left, n);
	else if(n>root->info)
		root->right=eliminate(root->right, n);
	else{
		if(root->left==nullptr) {
			Node *temp=root->right;
			delete root;
			return temp;
		}
      else if (root->right==nullptr){
			Node *temp=root->left;
			delete root;
			return temp;
		}
		Node *temp=minInorden(root->right);
		root->info=temp->info;
		root->right=eliminate(root->right, temp->info);
	}
	return root;
}

void inOrden(Node* Node){
	if(Node!=nullptr) {
		inOrden(Node->left);
		cout << Node->info<<" ";
		inOrden(Node->right);
	}
}

void seeTree(Node* Node, int n){
	if(Node==nullptr)
		return;
	seeTree(Node->right, n+1);
	for(int i = 0; i < n; i++)
		cout<<"  ";
	cout<<Node->info<<endl;
	seeTree(Node->left, n+1);
}

int counter=0;

void print(Node *root, int k){
	if(root!=nullptr && counter<=k){
		print(root->right, k);
		counter++;
		if(counter==k)
			printf("%d ", root->info);
		print(root->left, k);
	}
}

//MAIN
int main() {
	Node *tree=nullptr;   // creating tree
	int n;

	do{
		cin >> n;
		if(n==0) break;
		tree=insert(tree, n);
	}while(true);

	print(tree, 3);

	do{
        cout<<"\n Showing pNode \n";
        seeTree(tree, 0);
        cout<<"\n Element to eliminate: ";
        cin>>n;
        if(n==0) break;

        if(search(tree, n)!=nullptr){
            tree=eliminate(tree, n);
        }else{
            cout<<"Item not found in tree\n";
        }
    } while(true);


	cout<<"\n pNode tours";
	cout<<"\n\n In order:  ";   
	inOrden(tree);
	cout<<endl << endl;
	return 0;
}