#include<algorithm>
#include<iostream>
using namespace std;
// trapping rain water

class Solution{
public:
long long trappingWater(int arr[],int n){
    // two pointer approach
    // T.C O(N)  S.C O(N)
    int left[n],right[n];
    left[0]=0;
    right[n-1]=0;
    // find left max building
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i-1]);
    }
    // find right max building 
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i+1]);
    }

    long long water=0;
    for(int i=0;i<n;i++){
        int miniHeight=min(left[i],right[i]);
        if(miniHeight-arr[i]>=0){
            water+=miniHeight-arr[i];
        }
    }
    return water;
}};
https://leetcode.com/problems/trapping-rain-water/description/
42: Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        // T.C->o(N), S.C->O(1)
        int n=height.size();
        int leftmax=0,rightmax=0,maxHeight=height[0],index=0;
        // find the max height 
        for(int i=1;i<n;i++){
            if(height[i]>maxHeight){
                maxHeight=height[i];
                index=i;
            }
        }
        int water=0;
        // do from the left side till we reach the max height 
        for(int i=0;i<index;i++){
            if(leftmax>height[i]){
                water+=leftmax-height[i];
            }
            else leftmax=height[i];
        }
        // do from the right side of the array till we reach the max height 
        for(int i=n-1;i>index;i--){
            if(rightmax>height[i]){
                water+=rightmax-height[i];
            }
            else rightmax=height[i];
        }
        return water;

    }
};

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        // two pointer approach
        // T.C O(N)  S.C O(1)
        int left=0;
        int right=n-1;
        int leftbar=arr[0];
        int rightbar=arr[n-1];
        long long water=0;
        while(left<=right){
            // to check the limit which one is greater
            if(leftbar<rightbar){
                // if element that you are seeing now ,if that become highest left so we cant store water
                if(arr[left] > leftbar){
                    leftbar=arr[left];
                }
                else{
                    water+=leftbar-arr[left];
                    left++;
                }
            }
            else{
                // if element that you are seeing now ,if that become highest right so we cant store water
                if(arr[right]>rightbar){
                    rightbar=arr[right];
                }
                else{
                    water+=rightbar-arr[right];
                    right--;
                }
            }
        }
        return water;
    }
};


// celebrity problem
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
class Solution 
{
    public:
    // knows function
    
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
    //   We solve with Two pointer approach
    // T.C O(N) , S.C O(1)
        int i=0,j=n-1;
        // step 2 run loop til i<j
        while(i<j){
            // if i knows j so i doesnt celebrity
            if(M[i][j]==1){
                i++;
            }
            else{
                j--;
            }
        }
        int candidate=i;
        // step 3 verify
        for(i=0;i<n;i++){
            if(i!=candidate){
                if(M[candidate][i]==1 || M[i][candidate]==0){
                return -1;
            }
            }
            
        }
        return candidate;
    }
};

167:Two sum II - Input array is sorted
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
  // t.c-o(n) s.c-o(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int start=0,end=n-1;
        vector<int> ans(2);
        while(start<end){
            if(numbers[start]+numbers[end]==target){
                ans[0]=start+1;
                ans[1]=end+1;
                break;
            }
            else if(numbers[start]+numbers[end]>target){
                end--;
            }
            else{
                start++;
            }
        }
        return ans;
    }
};
https://www.interviewbit.com/problems/pair-with-given-difference/
Pair with given difference
int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int start=0,end=1,n=A.size();
    // for the negative test case
    if(B<0){
        B=B*-1;
    }
    
    while(end<n){
        if(A[end]-A[start]==B){
            return 1;
        }
        else if(A[end]-A[start]<B){
            end++;
        }
        else {
            start++;
        }
        // when we increase both start and end in some case they come to same point so we increase end
        if(start==end){
            end++;
        }
    }
    return 0;
}

// Product Pair
class Solution {
  public:
    bool isProduct(vector<int> arr, long long x) {
        // code here
        sort(arr.begin(),arr.end());
        int start=0,end=arr.size()-1;
        while(start<end){
            long long prod=1LL*arr[start]*arr[end];
            if(prod==x) return true;
            else if(prod>x) end--;
            else start++;
        }
        return false;
    }
};

https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
3 sum problem
class Solution {
  public:
//   T.C O(N^2) S.C O(1)
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        // we take first element as one on the element and find the other two by using two pointer approach 
        for(int i=0;i<n-2;i++){
            int ans=target-arr[i];
            int start=i+1,end=n-1;
            while(start<end){
                if(arr[start]+arr[end]==ans) return 1;
                else if(arr[start]+arr[end]>ans) end--;
                else start++;
            }
        }
        return 0;
    }
};

https://www.geeksforgeeks.org/problems/four-elements2452/1
4 Sum problem
bool find4Numbers(int A[], int n, int X) {
    // T.C O(N^3) S.C O(1)
    // sort the element
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        // skip the duplicate element
        if(i>0 && A[i]==A[i-1]) continue;
        for(int j=i+1;j<n;j++){
            // skip the duplicate element
            if(j>i+1 && A[j]==A[j-1]) continue;
            // now use two pointer approach - start and end as k and l
            int k=j+1,l=n-1;
            while(k<l){
                long long sum=A[i]+A[j]+A[k]+A[l];
                if(sum==X){
                    return 1;
                }
                else if(sum<X) k++;
                else l--;
            }
        }
    }
    return 0;
}