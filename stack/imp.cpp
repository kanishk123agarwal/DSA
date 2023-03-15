#include<iostream>
using namespace std;
int n=5;
int arr[5];
int top=-1;
bool isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}
bool isFull(){
    if(top==n-1){
        return true;
    }
    return false;
}
void push(int ele){
    if(isFull()){
        cout<<"Element is not entered bcz stack is full"<<endl;
        return;
    }
    arr[++top]=ele;
}
void pop(){
   if(isEmpty()){
    cout<<"Stack is empty"<<endl;
    return;
   }
   cout<<arr[top]<<" ";
   top--;
}
int main(){
   push(5);
   push(3);
   push(4);
   push(2);
   push(1);
//    push(2);
//    push(0);
   pop();
   pop();
   pop();
   pop();
   pop();
   pop();
}