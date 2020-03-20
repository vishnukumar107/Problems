#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;

    }
};
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void deletenode(node* temp){
    if(temp==NULL)return;
    temp->data=temp->next->data;
    node* next=temp->next;
    temp->next=next->next;
    delete next;
}
int main(){
    node* head=new node(5);
    head->next=new node(6);
    head->next->next=new node(7);
    head->next->next->next=new node(8);
    print(head);
    deletenode(head->next->next);
    print(head);
    return 0;
}