#include<iostream>
using namespace std;

// Time Complexity:
// push()-o(1)
// pop()-O(1)
// getFront()-O(1)
// getRear()-O(1)
// isEmpty()-O(1)
// isFull()-O(1)
// getSize()-O(1)
// print()-O(n)

// implement queue
class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    Queue(int n){
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
    }

    void push(int val){
        // check full
        if(rear==size-1){
            cout<<"Queue is full"<<endl;
        }

        // check empty
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[rear]=val;
        }

        else{
            rear++;
            arr[rear]=val;
        }
    }

    void pop(){
        // check empty
        if(front==-1 && rear==-1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }

    int getSize(){
        // yeh case yaad rkhna hai yeh almost bhul jaate hai 
        if(front==-1 && rear==-1){
            return 0;
        }
        else
            return rear-front+1;
    }

    int getFront(){
        if(front==-1 && rear==-1){
            cout<<"No element is present"<<endl;
            return -1;
        }
        else
            return arr[front];
    }

    int getRear(){
        if(front==-1 && rear==-1){
            cout<<"No element is present"<<endl;
            return -1;
        }
        else
            return arr[rear];
    }
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int print(){
        cout<<"Printing Queue ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q(5);

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    cout<<"Queue size is "<<q.getSize()<<endl;
    cout<<"Queue is empty or not "<<q.isEmpty()<<endl;

    cout<<"Front element is "<<q.getFront()<<endl;
    q.pop();
    cout<<"Front element is "<<q.getFront()<<endl;
    q.print();
    q.pop();
    q.print();
    cout<<"Queue is empty or not "<<q.isEmpty()<<endl;
    q.pop();

    cout<<"Queue size is "<<q.getSize()<<endl;
}