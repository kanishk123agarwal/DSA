// implement k queue by using a single array
#include<iostream>
using namespace std;

class kQueue{
    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    kQueue(int n,int k){
        this->n=n;
        this->k=k;
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }  
        arr=new int[n];
        next=new int[n];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        freespot=0;
    }

    // push method
    // Algo
    // 1) check overflow_error
    // 2) find index which give a free slot
    // 3) update freespot 
    // 4) check the qi is empty or not by using the front array 
        // if not so
        // link to the other element where it exits 
    // 5) update next array whichh show that this is not the place where I insert a new element 
    // 6) update rear array which show the last position of any queue 
    // 7) update array
    void enqueue(int data,int qn){
        // overflow
        if(freespot==-1){
            cout<<"No Empty space is present"<<endl;
            return;
        }

        // find first free index
        int index=freespot;

        // update freespot
        freespot=next[index];

        // check whether the first element is 
        if(front[qn-1] == -1)
           front[qn-1]=index;
        else{
            // link new element to the previous element
            next[rear[qn-1]]=index;
        }

        // update next
        next[index]=-1;

        // update rear
        rear[qn-1]=index;

        // push element
        arr[index]=data;

    }

    // pop the element
    // algo
    // 1) check the underflow 
    // 2) find index with the help of front array
    // 3) take forward front 
    // 4) give next array to free spot which is free after dequeue operation
    // 5) freespot goes to the next spot 
    // 6) return ans
    int dequeue(int qn){
        // underflow
        if(front[qn-1] == -1){
            cout<<"Queue underflow"<<endl;
            return -1;
        }

        // find index to top
        int index=front[qn-1];

        // front ko aage badhao
        front[qn-1]=next[index];

        // free spot manage
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};
int main(){
    kQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);
    
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    // q.enqueue(10,1);
    return 0;
}