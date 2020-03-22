#include<iostream>
#include<queue>
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
int maxlevel(node* root){
    if(!root)return -1;
    queue<node*> q;
    q.push(root);
    int max=INT_MIN;
    int level=0;
    int nodecount=0;
    int max_level;
    while(!q.empty()){
        nodecount=q.size();
        if(nodecount>max){
            max=nodecount;
            max_level=level;
        }
        while(nodecount){
            node* curr=q.front();
            q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
            nodecount--;
        }
        level++;
    }
    return max_level;
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    // root->right->left=new node(60);
    // root->right->right=new node(70);
    cout<<maxlevel(root);
    return 0;
}