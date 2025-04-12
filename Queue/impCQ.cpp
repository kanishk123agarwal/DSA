#include<iostream>
using namespace std;

// implementing circular queue
class CQueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    CQueue(int n){
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
    }

    void push(int val){
        // overflow
        if(front==0 && rear==size-1 || front==rear+1){
            cout<<"Overflow"<<endl;
            return;
        }
        // empty case
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[rear]=val;
        }
        // circular nature
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=val;
        }
        // normal case
        else{
            rear++;
            arr[rear]=val;
        }
    }

    // pop operation
    void pop(){
        // underflow
        if(front==-1 && rear==-1){
            cout<<"Underflow"<<endl;
        }
        // single element
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        // circular nature
        else if(front==size-1){
            arr[front]=-1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
    

    // get front element
    int getFront(){
        if(front==-1 && rear==-1){
            cout<<"No element is present"<<endl;
            return -1;
        }
        else    
            return arr[front];
    }

    // get rear element
    int getRear(){
        if(front==-1 && rear==-1){
            cout<<"No element is present"<<endl;
            return -1;
        }
        else
            return arr[rear];
    }

    // get size
    int getSize(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        else{
            if(front<=rear){
                return rear-front+1;
            }
            else
                return size-front+rear+1;
        }
    }

    // check empty
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else
            return false;
    }

    // check full 
    bool isFull(){
        if((rear+1)%size==front){
            return true;
        }
        else
            return false;
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
    CQueue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();

    q.push(50);
    q.print();

    q.push(100);
    q.print();

    q.pop();
    q.print();
    q.push(100);
    q.print();

    cout<<"Queue size is "<<q.getSize()<<endl;
    cout<<"Queue is empty or not "<<q.isEmpty()<<endl;

    q.pop();
    q.print();
    cout<<"Queue size is "<<q.getSize()<<endl;
}