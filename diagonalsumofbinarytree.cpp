#include<iostream>
#include<map>
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
void diagonalsumbt(node* root,int i,map<int,int>& d){
    if(root==NULL)return;
    d[i]+=root->data;
    diagonalsumbt(root->left,i+1,d);
    diagonalsumbt(root->right,i,d);
}
void diagonalsum(node* root){
    map<int,int> d;
    diagonalsumbt(root,0,d);
    map<int,int>::iterator it;
    for(it=d.begin();it!=d.end();it++)
        cout<<it->second<<" ";
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    diagonalsum(root);
    return 0;
}