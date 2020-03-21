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
void constructbstree(int &i,node* &root,int pre[],char preln[],int s){
    if(i>=s)return;
    root=new node(pre[i]);
    if(preln[i]=='N'){
        constructbstree(++i,root->left,pre,preln,s);
        constructbstree(++i,root->right,pre,preln,s);
    }
    else return;
}
node* constructtree(int pre[],char preln[],int size){
    node* root=NULL;
    int i=0;
    constructbstree(i,root,pre,preln,size);
    return root;
}
void inorder(node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int pre[]={10,5,1,7,40,30,60};
    char preln[]={'N','N','L','L','N','L','L'};
    int size=sizeof(pre)/sizeof(pre[0]);
    node* root=constructtree(pre,preln,size);
    cout<<"inorder traversal"<<endl;
    inorder(root);
    return 0;
}