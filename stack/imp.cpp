// #include<iostream>
// using namespace std;
// int n=5;
// int arr[5];
// int top=-1;
// bool isEmpty(){
//     if(top==-1){
//         return true;
//     }
//     return false;
// }
// bool isFull(){
//     if(top==n-1){
//         return true;
//     }
//     return false;
// }
// void push(int ele){
//     if(isFull()){
//         cout<<"Element is not entered bcz stack is full"<<endl;
//         return;
//     }
//     arr[++top]=ele;
// }
// void pop(){
//    if(isEmpty()){
//     cout<<"Stack is empty"<<endl;
//     return;
//    }
//    cout<<arr[top]<<" ";
//    top--;
// }
// int main(){
//    push(5);
//    push(3);
//    push(4);
//    push(2);
//    push(1);
// //    push(2);
// //    push(0);
//    pop();
//    pop();
//    pop();
//    pop();
//    pop();
//    pop();
// }

#include<iostream>
using namespace std;

class Stack{
 private:
 int *arr;
 int size;
 int top;
 public:
 Stack(int size){
    arr=new int(size);
    this->size=size;
    top=-1;
 }

//  insert the element
void push(int ele){
    top++;
    arr[top]=ele;
}

// remove the element 
void pop(){
    top--;
}

int getSize(){
    return top+1;
}

int getTop(){
    return arr[top];
}

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}
};

int main(){
    Stack st(8);
    st.push(10);
    st.push(20);
    st.push(30);
    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not Empty"<<endl;
    }
    cout<<"Stack top element "<<st.getTop()<<endl;
    st.pop();
    cout<<"Stack top element "<<st.getTop()<<endl;
    cout<<"Stack size "<<st.getSize()<<endl;
}