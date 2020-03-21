#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node* random;
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
            this->random=NULL;
        }
};

//recursive approach
/*
node* clonelrnodes(node* root,unordered_map<node*,node*>& hash){
    if(!root)return NULL;
    node* clonenode=new node(root->data);
    hash[root]=clonenode;
    clonenode->left=clonelrnodes(root->left,hash);
    clonenode->right=clonelrnodes(root->right,hash);
    return clonenode;
}
void clonepointer(node* root,node* cloneroot,unordered_map<node*,node*> hash){
    if(!root)return;
    cloneroot->random=hash[root->random];
    clonepointer(root->left,cloneroot->left,hash);
    clonepointer(root->right,cloneroot->right,hash);
}
node* clonetree(node* root){
    if(!root)return NULL;
    unordered_map<node*,node*>hash;
    node* clonetree=clonelrnodes(root,hash);
    clonepointer(root,clonetree,hash);
    return clonetree;
}
*/

//iterative approach

node* clonetree(node* root){
    if(!root)return NULL;
    queue<node*> q;
    unordered_map<node*,node*> hash;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        node* clone=new node(curr->data);
        hash[curr]=clone;
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        hash[curr]->left=hash[curr->left];
        hash[curr]->right=hash[curr->right];
        hash[curr]->random=hash[curr->random];
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
    return hash[root];
}


void inorder(node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<"["<<root->data<<" ";
    if(root->random==NULL)cout<<"NULL] ";
    else cout<<root->random->data<<"] ";
    inorder(root->right);
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->random = root->left->right; 
    root->left->left->random = root; 
    root->left->right->random = root->right; 
    cout<<"original tree\n";
    inorder(root);
    cout<<endl;
    node* cloneroot=clonetree(root);
    cout<<"clone tree\n";
    inorder(cloneroot);
    return 0;
}