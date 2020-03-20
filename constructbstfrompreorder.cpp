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
node* constructtree(int pre[],int* index,int low,int high,int size){
    if(*index>=size ||low>high)return NULL;
    node* root=new node(pre[*index]);
    *index+=1;
    if(low==high)return root;
    int i;
    for(i=low;low<=high;i++){
        if(pre[i]>root->data)
            break;
    }
    root->left=constructtree(pre,index,*index,i-1,size);
    root->right=constructtree(pre,index,i,high,size);
    return root;
}
node* bstfrompreorder(int pre[],int size){
    int index=0;
    return constructtree(pre,&index,0,size-1,size);
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