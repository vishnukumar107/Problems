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
int height(node* root){
    if(root==NULL)return 0;
    int lleft=height(root->left);
    int lright=height(root->right);
    if(lleft>lright)return 1+lleft;
    else return 1+lright;
}
int main(){
    node *root = new node(1);  
    root->left = new node(2);  
    root->right = new node(3);  
    root->left->left =new node(4);  
    root->left->right =new node(5);
    cout<<height(root);
    return 0;
}