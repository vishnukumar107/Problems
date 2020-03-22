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
/*
node* concat(node* leftlist,node* rightlist){
    if(!leftlist)return rightlist;
    if(!rightlist)return leftlist;
    node* leftlast=leftlist->left;
    node* rightlast=rightlist->left;
    leftlast->right=rightlist;
    rightlist->left=leftlast;
    rightlast->right=leftlist;
    leftlist->left=rightlast;
    return leftlist;
}
node* converttocdl(node* root){
    if(!root)return NULL;
    node* left=converttocdl(root->left);
    node* right=converttocdl(root->right);
    root->left=root->right=root;
    return concat(concat(left,root),right);
}*/
void display(node* head){
    node* first=head;
    cout<<"doubly circular linked list\n";
    do{
        cout<<head->data<<" ";
        head=head->right;
    }while(head!=first);
}
void cdl(node* root,node* &head,node* &prev){
    if(!root)return;
    cdl(root->left,head,prev);
    if(prev)prev->right=root;
    else head=root;
    root->left=prev;
    prev=root;
    cdl(root->right,head,prev);
}
void converttocdl(node* root){
    if(!root)return;
    node* head=NULL;
    node* prev=NULL;
    cdl(root,head,prev);
    head->left=prev;
    prev->right=head;
    display(head);
}

int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    converttocdl(root);
    //display(head);
    return 0;
}