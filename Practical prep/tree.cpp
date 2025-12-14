#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insertNode(Node* root, int value){
    if(root==NULL)
    {
            Node* newNode= new Node();
            newNode->data=value;
            newNode->left=newNode->right=NULL;
            return newNode;
    }

    if(value < root->data)
    {
        root->left=insertNode(root->left,value);
    }

     if(value > root->data)
     {
        root->right=insertNode(root->right,value);
    }
    return root;
}


//traversal
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){

    Node* root=NULL;
    root=insertNode(root,10);
    root=insertNode(root,5);
    root=insertNode(root,11);
    root=insertNode(root,6);
    root=insertNode(root,1);
    root=insertNode(root,7);
    root=insertNode(root,2);
    root=insertNode(root,4);

    cout<<"inorder traversal :"<<endl;
    inorder(root);


    cout<<"\npreorder traversal :"<<endl;
    preorder(root);

    cout<<"\npostorder traversal :"<<endl;
    postorder(root);

    return 0;
}