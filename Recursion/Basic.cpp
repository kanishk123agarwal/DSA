// Ques1: sum of all element in array

#include<iostream>
using namespace std;

int sumArray(int arr[],int i,int n){
    if(i==n){
        return 0;
    }
    return sumArray(arr,i+1,n)+arr[i];
}

// Ques2:Factorial of a no 

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

// Ques3:Find fibonacci series
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

// Ques4:Sum of a digit of number
int sumDigit(int digit){
    if(digit==0) return 0;
    int sum = sumDigit(digit/10);
    sum=sum+digit%10;
    return sum;
}

// Ques5: Find max and min
int findMax(int arr[],int n){
    if(n<=0) return arr[n];
    int max=findMax(arr,n-1);
    return (arr[n-1]<max)?max:arr[n-1];
}

int main(){
    int arr[5]={5,3,10,4,2};
    // int sum=sumArray(arr,0,5);
    // cout<<sum<<endl;

    // Ques2:
    // int fact=factorial(10);
    // cout<<fact<<endl;

    // Ques3:
    // int fib=fibonacci(3);
    // cout<<fib<<endl;

    // Ques4:
    // int digit=1234;
    // int sum=sumDigit(digit);
    // cout<<sum<<endl;

    // Ques5:
    int max=findMax(arr,5);
    cout<<max<<endl;
}