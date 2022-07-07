#include<iostream>
using namespace std;
class Heap{
    public:
    int size,arr[1000];
    Heap(){
        size=0;
        arr[0]=-1;
    }

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"Nothing to print";
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int largest=i;
            int leftI=2*i;
            int rightI=2*i+1;
            // if(leftI<size && arr[i] < arr[leftI]){
            //     swap(arr[leftI],arr[i]);
            //     i=leftI;
            // }
            // else if(rightI<size && arr[i] < arr[rightI]){
            //     swap(arr[rightI],arr[i]);
            //     i=rightI;
            // }
            // else{
            //     return;
            // }

            if(leftI<size && arr[i]<arr[leftI]){
                largest=leftI;
            }
            if(rightI<size && arr[i]<arr[rightI]){
                largest=rightI;
            }
            if(largest!=i){
                swap(arr[largest],arr[i]);
                i=largest;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest] < arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest] < arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        // 2nd step
        heapify(arr,size,1);
    }
}
int main(){
    Heap h;
    h.insert(20);
    h.insert(15);
    h.insert(12);
    h.insert(4);
    h.insert(3);
    h.insert(30);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6]={-1,53,54,55,50,52};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
  cout<<"After heapify";
  cout<<endl;
  for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;

  heapsort(arr,n);
  cout<<"After sorting the array"<<endl;
  for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";

  }cout<<endl;
}