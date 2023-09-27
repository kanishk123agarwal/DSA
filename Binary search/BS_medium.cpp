#include<bits/stdc++.h>
using namespace std;

https://leetcode.com/problems/search-in-rotated-sorted-array/
// 33. Search in Rotated Sorted Array
class Solution {
public:
//    find pivot index
    int findPivotIndex(vector<int> &nums){
        int n=nums.size();
        int s=0,e=n-1;

        while(s<=e){
            int mid=s+(e-s)/2;
    // corner case : for single element in the array 
            if(s==e) return s;
            
            // case 1
            if(mid-1>=0 && nums[mid]<nums[mid-1]){
                return mid-1;
            }
            // case 2
            else if(mid+1<n && nums[mid]>nums[mid+1]){
                return mid;
            }
            // case 3
            else if(nums[s]>nums[mid]){
                // left
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }

    // binary search
    int BS(vector<int>& nums , int s,int e,int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]) s=mid+1;
            else e=mid-1;
        } 
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivotIndex=findPivotIndex(nums);
        int n=nums.size();
        int ans=-1;
        // search in A
        if(target>=nums[0] && target <= nums[pivotIndex]){
            ans=BS(nums,0,pivotIndex,target);  
        }
        // search in B
        else{
            ans=BS(nums,pivotIndex+1,n-1,target);
        }
        return ans;
    }
};


// Square root x in o(logn)
https://leetcode.com/problems/sqrtx/
// search space
// predicate function
class Solution {
public:
    int mySqrt(int x) {
        int s=0, e=x;
        int ans=-1;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid<x){
                // ans store kro aur right jao
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
};

// sqrt of x and find in precision value 
#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int n)
{
    int s = 0, e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;

        // predicate fn
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1; // go right
        }
        else
            e = mid - 1; // go left
    }
    return ans;
}

double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);
    int precision = 10;
    double step = 0.1;
    for (int i = 0; i < precision; ++i)
    {
        double j = sqrt;
        while (j * j <= n)
        {
            sqrt = j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}

// divide the number and find out the quotient in precision terms
int divide(int dividend, int divisor)
{
    int s = 0, e = dividend;
    int ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;
        // check if mid is the answer, treat mid as Quotient
        // Quotient * Divisor + Reminder = Dividend,
        // Predicate: Quotient * Divisor <= Dividend
        if (mid * divisor <= dividend)
        {
            ans = mid;
            // go right for more precise answer
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

double myPrecisionDivide(int dividend, int divisor)
{
    double quotient = divide(dividend, divisor);
    int precision = 5; // to take the precision point
    double step = 0.1;  //we increase the step by 0.1 then 0.01 then 0.001 by dividing the steps 10
    for (int i = 0; i < precision; ++i)
    {
        double j = quotient;
        while (j * divisor <= dividend) //predicate function
        {
            quotient = j;
            j += step;
        }
        step /= 10;
    }
    return quotient;
}

int main()
{
    int n = 63;
    // cout << mySqrt(n) << endl;
    cout << myPrecisionSqrt(n) << endl;
    return 0;
}


// 74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/description/
// O(log(m * n)) time complexity.
// 1d to 2d formula
// rowIndex=mid/no of column
// columnIndex=mid%no of column
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int s=0;
        int n=row*col;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int rowIndex=mid/col;
            int colIndex=mid%col;
            if(matrix[rowIndex][colIndex]==target)return true;
            else if(target>matrix[rowIndex][colIndex])s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};


// search in nearly sorted array 
int searchNearlySorted(int arr[],int n,int target){
    int s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid-1>=0 && arr[mid-1]==target) return mid-1;
        if(arr[mid]==target) return mid;
        if(mid+1<n && arr[mid+1]==target) return mid+1;
        if(target>arr[mid]){
            // right
            // cache
            s=mid+2;
        }
        else{
            // cache
            e=mid-2;
        }
    }
    return -1;
}
// index based problem 
int findOddOccuring(int arr[],int n){
    int s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        // single element
        if(s==e)return s;

        // mid check-> even or odd
        if(mid & 1){ //mid&1 -> true ->odd number
            if(mid-1>=0 && arr[mid]==arr[mid-1]) s=mid+1;
            else e=mid-1;
        }else{
            if(mid+1<n && arr[mid]==arr[mid+1]) {
                // cache
                s=mid+2;
            }
            else {
                // ya to mai right part pr hu
                // ya toh mai ans pr khada hu 
                // that's why e=mid kr rha hu
                // cache
                e=mid;
            }
        }
    }
    return -1;
}

int main(){
    int arr[]={20,10,30,50,40,70,60};
    int n=7;
    int target=70;
    int ans=searchNearlySorted(arr,n,target);
    if(ans==-1) cout<<"Element not found";
    else cout<<"Elemetn are found"<<ans;
    

    // find odd occuring number
    int arr[] = {10,10,2,2,4,3,3,5,5,6,6,7,7};
    int n=13;
    int ans= findOddOccuring(arr,n);
    cout<<arr[ans];
    return 0;
}