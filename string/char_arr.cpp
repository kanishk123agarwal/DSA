#include<iostream>
using namespace std;
int main(){
    // declare
    // char arr[100]=  "Apple is my best fruit";
    // int i=0;
    // while(arr[i]!='\0'){
    //     cout<<arr[i];
    //     i++;
    // }

    // take input and output
    // char arr[100];
    // cin>>arr;
    // cout<<arr;

    // check palindrome
    // int n;
    // cin>>n;
    // char arr[n+1];
    // cin>>arr;
    // bool check=1;
    // for(int i=0;i<n;i++){
    //     if(arr[i]!=arr[n-1-i]){
    //         check=0;
    //         break;
    //     }
    // }
    // if(check==true){
    //     cout<<"word is a palindrome";
    // }
    // else
    //  cout<<"Word is not a palindrome";

    // for tking sentence input we take getline function
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];
    
    cin.getline(arr,n);
    cin.ignore();
    int i=0,currlen=0,maxlen=0;
    while(1){
        if(arr[i]== ' ' || arr[i]=='\0'){
            if(currlen > maxlen){
                maxlen=currlen;
            }
            currlen=0;
        }
        else
        currlen++; 
        if(arr[i]=='\0'){
            break;
        }
        i++;
    }
    cout<<maxlen;  
    return 0;
}