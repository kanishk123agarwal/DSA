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

// Ques6:sum of prime between the range
bool isPrime(int number,int divisor=2){
    if(number<=2){
        return (number==2);
    }
    if(number%divisor==0) return false;
    if(divisor*divisor > number) return true;

    return isPrime(number,divisor+1);
}
int sumPrime(int start,int end){
    if(start>end){
        return 0;
    }
    int sum=isPrime(start)?start:0;
    return sum+sumPrime(start+1,end);
}

// Ques7:sum of odd and even no between the range
void sumEvenOdd(int start,int end,int &evenS,int &oddS){
    if(start>end) return;

    if(start%2==0) evenS=evenS+start;
    else oddS=oddS+start;
    sumEvenOdd(start+1,end,evenS,oddS);
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

    // ques6:sum of prime no between the range
    int sumP = sumPrime(1,20);
    cout<<sumP<<endl;

    // Ques7: 
    int evenS=0,oddS=0;
    sumEvenOdd(10,20,evenS,oddS);
    cout<<evenS<<" "<<oddS<<endl;
}