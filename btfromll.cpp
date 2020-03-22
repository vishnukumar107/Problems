#include<iostream>
#include<queue>
using namespace std;
class tree{
    public:
        int data;
        tree* left;
        tree* right;
        tree(int data){
            this->data=data;
            this->left=this->right=NULL;
        }
};
class node{
    public:
        int key;
        node* next;
        node(int key){
            this->key=key;
            this->next=NULL;
        }
};
void inorder(tree* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void convertobt(node* head,tree* &root){
    if(!head){
        root=NULL;
        return;
    }
    queue<tree*>q;
    root=new tree(head->key);
    q.push(root);
    head=head->next;
    while(head){
        tree* parent=q.front();
        q.pop();
        parent->left=new tree(head->key);
        q.push(parent->left);
        head=head->next;
        if(head){
            parent->right=new tree(head->key);
            q.push(parent->right);
            head=head->next;
        }
        
    }


}
int main(){
    node* head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    tree* root;
    convertobt(head,root);
    cout<<"inorder traversal";
    inorder(root);
    return 0;
}