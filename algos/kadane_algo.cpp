https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// MAX SUM OF CONTIGUOUS SUBARRAY
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxSum=arr[0];
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            if(sum > maxSum){
                maxSum=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxSum;
        
    }
};

// Divide the array in 2 subarray with equal sum

#include <bits/stdc++.h>
using namespace std;
bool EqualSum(int arr[],int n){
  int total_sum=0;
  for(int i=0;i<n;i++){
    total_sum+=arr[i];
  }
  int prefix=0;
  // yha pr n-1 isliye liya kyoki last wala element ko lenge to uske aage koi element nhi bachega fir 2 equal part nhi honge
  for(int i=0;i<n-1;i++){
    prefix+=arr[i];
    int ans=total_sum-prefix;
    if(prefix==ans){
      return true;
    }
  }
  return false;
}

https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
// Maximum difference between two elements such that larger element appears after the smaller number
// T.c-O(n) S.c-O(1)
// By using Kadane Algo
int maxDiff(int arr[],int n){
  int diff=arr[1]-arr[0];
  int currSum=diff;
  int maxi=-1;
  if(currSum>0) maxi=currSum;
  for(int i=1;i<n-1;i++){
    diff=arr[i+1]-arr[i];
    if(currSum>0) currSum+=diff;
    else currSum=diff;
    if(currSum>0 && currSum>maxi) maxi=currSum;
  }
  return maxi;
}
https://www.geeksforgeeks.org/problems/maximum-prefix-sum-for-a-given-range0227/1
// Maximum Prefix sum for a given range 
class Solution {
  public:
    vector<int> maxPrefixes(vector<int>& arr, vector<int>& leftIndex,
                            vector<int>& rightIndex) {
        // code here.
        vector<int> ans;
        int n=leftIndex.size();
        for(int i=0;i<n;i++){
            int a=leftIndex[i],b=rightIndex[i];
            int prefix=arr[a];
            int maxi=prefix;
            // using prefix sum approach
            for(int j=a+1;j<=b;j++){
                prefix+=arr[j];
                maxi=max(prefix,maxi);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};