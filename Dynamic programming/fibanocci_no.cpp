// in this we use a top down approach of dp series 
// in which we use rucursion and memorization so the time complexity will reduce 

#include<bits/stdc++.h>
using namespace std;

// T.C O(N)
// S.C O(N)
int fib(int n,vector<int>&dp){
//     base case
    if(n==0 || n==1){
        return n;
    }
    
//    step 3
    if(dp[n]!=-1){
        return dp[n];
    }

//     step 2
    dp[n] =  fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

int main()
{
//     step1
    int n;
    cin>> n;
    vector<int> dparr(n+1);
    for(int i=0;i<=n;i++){
        dparr[i] = -1;
    }
    cout<<fib(n,dparr);
}