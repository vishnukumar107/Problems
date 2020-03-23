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
int maxsum(node* root,int& sum){
    if(!root)return 0;
    int lh=maxsum(root->left,sum);
    int rh=maxsum(root->right,sum);
    int rootmax=max(max(lh,rh)+root->data,root->data);
    int atmax=max(rootmax,lh+rh+root->data);
    sum=max(sum,atmax);
    return rootmax;
}
int maxpathsum(node* root){
    if(!root)return 0;
    int sum=INT_MIN;
    maxsum(root,sum);
    return sum;
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
    cout<<maxpathsum(root);
    return 0;
}