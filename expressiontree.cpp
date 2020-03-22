#include<iostream>
using namespace std;
class node{
    public:
        string data;
        node* left;
        node* right;
        node(string data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
int tointeger(string s){
    int num=0;
    if(s[0]!='-'){
        for(int i=0;i<s.size();i++)
            num=num*10+(s[i]-'0');
    }
    else{
        for(int i=1;i<s.size();i++)
            num=num*10+(s[i]-'0');
        num*=-1;
    }
    return num;
}
int eval(node* root){
    if(!root)return 0;
    if(!root->left && !root->right)return tointeger(root->data);
    int left=eval(root->left);
    int right=eval(root->right);
    if(root->data=="+")return left+right;
    if(root->data=="-")return left-right;
    if(root->data=="*")return left*right;
    return left/right;
}
int main()  
{  
    node *root = new node("+");  
    root->left = new node("*");  
    root->left->left = new node("5");  
    root->left->right = new node("-4");  
    root->right = new node("-");  
    root->right->left = new node("100");  
    root->right->right = new node("20");  
    cout << eval(root) << endl;  
    return 0;
}