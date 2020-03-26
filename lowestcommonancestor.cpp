#include<iostream>
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
node* lca(node* root,int n1,int n2){
    if(!root)return NULL;
    if(root->data==n1 ||root->data==n2)return root;
    node* leftlca=lca(root->left,n1,n2);
    node* rightlca=lca(root->right,n1,n2);
    if(leftlca && rightlca)return root;
    return (leftlca)?leftlca:rightlca;
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->left->left->right=new node(8);
    cout<<lca(root,8,5)->data;
    return 0;
}