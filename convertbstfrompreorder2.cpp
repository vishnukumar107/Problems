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
node* constructtree(int pre[],int* index,int key,int min,int max,int size){
    if(*index>=size)return NULL;
    node* root=NULL;
    if(key>min && key<max){
        root=new node(key);
        *index+=1;
        if(*index<size){
        root->left=constructtree(pre,index,pre[*index],min,key,size);
        root->right=constructtree(pre,index,pre[*index],key,max,size);
        }
    }
    return root;
}
node* bstfrompreorder(int pre[],int size){
    int index=0;
    return constructtree(pre,&index,pre[0],INT_MIN,INT_MAX,size);
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
    node* root=bstfrompreorder(pre,size);
    cout<<"inorder traversal"<<endl;
    inorder(root);
    return 0;
}