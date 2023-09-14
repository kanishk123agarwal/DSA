#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target)return mid;
        else if(target > arr[mid])left=mid+1;
        else if(target<arr[mid])right=mid-1;
    }
    return -1;
}
int findFirstOccurence(int arr[],int target,int n){
    int left=0,right=n-1;
    int ans=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            right=mid-1;
            ans=mid;
        }
        else if(target>arr[mid])left=mid+1;
        else right=mid-1;
    }
    return ans;
}

int findLastOccurence(int arr[],int target,int n){
    int left=0,right=n-1;
    int ans=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            left=mid+1;
            ans=mid;
        }
        else if(target>arr[mid])left=mid+1;
        else right=mid-1;
    }
    return ans;
}
int findTotalOccurence(int arr[],int target,int n){
    int firstOccurence=findFirstOccurence(arr,target,n);
    int lastOccurence=findLastOccurence(arr,target,n);
    int ans=lastOccurence-firstOccurence+1;
    return ans;
}

// find missing
int findMissing(int arr[],int n){
    int s=0,e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int diff=arr[mid]-mid;
        if(diff==1) s=mid+1;
        else{
            ans=mid;
            e=mid-1;
        }
    }
    // catch here
    if(ans+1==0) return n+1;
    return ans+1;
}
int main(){
    // int arr[5]={10,20,30,40,50};
    // int target=15;
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int ans=binarySearch(arr,n,target);

    // first occurence of the element
    // int arr[5]={10,20,20,20,30};
    // int target=20;
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int ans=findFirstOccurence(arr,target,n);
    // cout<<ans;


     // last occurence of the element
    // int arr[6]={20,20,30,30,30,40};
    // int target=20;
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int ans=findLastOccurence(arr,target,n);
    // cout<<ans;


// total occurences of the element
    // int arr[6]={20,20,30,30,30,40};
    // int target=30;
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int ans=findTotalOccurence(arr,target,n);
    // cout<<ans;

    // missing element with the help of binary search
    int arr[6]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=findMissing(arr,n);
    cout<<ans;
}