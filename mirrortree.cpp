#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
void inorder(node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//recursive solution
/*
void mirrortree(node* root){
    if(root==NULL)return;
    else{
        mirrortree(root->left);
        mirrortree(root->right);
        swap(root->left,root->right);
    }
}*/

//iterative solution
void mirrortree(node* root){
    if(root==NULL)return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        swap(curr->left,curr->right);
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    cout<<"before inorder traversal"<<endl;
    inorder(root);
    cout<<endl;
    mirrortree(root);
    cout<<"after inorder traversal"<<endl;
    inorder(root);
    return 0;
}