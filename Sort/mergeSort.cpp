#include<iostream>
using namespace std;

// it is a good sorting algorithm 
// T.C - O(NLOGN)
void merge(int arr[],int s,int e){
    int mid=(s+e)/2;
    int lenLeft=mid-s+1;
    int lenRight=e-mid;

    // create left and right array
    int *left=new int[lenLeft];
    int *right=new int[lenRight];

    // copy values from the original array
    int k=s;
    for(int i=0;i<lenLeft;i++){
        left[i]=arr[k];
        k++;
    }

    k=mid+1;
    for(int i=0;i<lenRight;i++){
        right[i]=arr[k];
        k++;
    }

    // actual merge logic here 
    // left array is sorted 
    // right array is sorted
    int i=0,j=0;
    // yha glti hogi jyada  
    k=s;
    while(i<lenLeft && j<lenRight){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;
            k++;
        }
        
    }

    while(i<lenLeft){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<lenRight){
        arr[k]=right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[],int s,int e){
    if(s>e){
        return;
    }
    if(s==e){
        // single element
        return;
    }
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e); 
}

int main(){
    int arr[]={2,1,6,9,4,5};
    int size=6;
    int s=0;
    int e=size-1;

    cout<<"Before merge sort"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    mergeSort(arr,s,e);
    cout<<"After merge sort"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}