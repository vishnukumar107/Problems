#include<iostream>
#include<stack>
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
node* constructtree(int pre[],int size){
    stack<node*> s;
    node* root=new node(pre[0]);
    s.push(root);
    node* temp;
    for(int i=1;i<size;i++){
        temp=NULL;
        while(!s.empty() && pre[i]>s.top()->data){
            temp=s.top();
            s.pop();
        }
        if(temp!=NULL){
            temp->right=new node(pre[i]);
            s.push(temp->right);
        }
        else{
            temp=s.top();
            temp->left=new node(pre[i]);
            s.push(temp->left);
        }
    }
    return root;
}
void inorder(node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int pre[]={10,5,1,7,40,50};
    int size=sizeof(pre)/sizeof(pre[0]);
    node* root=constructtree(pre,size);
    cout<<"inorder traversal"<<endl;
    inorder(root);
    return 0;
}