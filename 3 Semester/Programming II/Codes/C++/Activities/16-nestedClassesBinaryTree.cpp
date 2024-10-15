// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASSES
class BinaryTree{
    public:
        class Node{
        public:
            int data;
            Node* left;
            Node* right;

            Node(int value):data(value), left(nullptr), right(nullptr) {}
        };

        BinaryTree():root(nullptr){}

        void insert(int value){
            root=insertRec(root, value);
        }

        void inorder(){
            inorderRec(root);
        }

    private:
        Node* root;

        Node* insertRec(Node* node, int value){
            if(node==nullptr){
                return new Node(value);
            }
            if(value<node->data) {
                node->left=insertRec(node->left, value);
            }else{
                node->right=insertRec(node->right, value);
            }
            return node;
        }

        void inorderRec(Node* node){
            if(node!=nullptr){
                inorderRec(node->left);
                cout<<node->data <<" ";
                inorderRec(node->right);
            }
        }
};

//MAIN
int main() {
    //tree testing
    BinaryTree tree1;
    tree1.insert(7);
    tree1.insert(5);
    tree1.insert(18);
    tree1.insert(21
    );

    cout<<"Inorder tree: ";
    tree1.inorder(); 
    
    return 0;
}
