#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->next=NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void printLL(Node* head){
    // when we traverse so we always make a new varible bcz we don't have lost the initial pointer 
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int LLLength(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

int main(){
    Node* first=new Node(23);
    Node* second=new Node(25);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(10);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    Node* head=first;
    cout<<"Prinring LL: "<<endl;
    printLL(head);
    int length=LLLength(head);
    cout<<"Length of LL: "<<length;
}