#include<iostream>
#include<string>
using namespace std;

// LONGEST COMMON SEQUENCE  GFG


class Solution{
  public:
    int findMinLen(string arr[],int N){
        int min=arr[0].length();
        for(int i=1;i<N;i++){
            if(arr[i].length()<min){
                min=arr[i].length();
            }
        }
        return min;
    }
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        int minlen=findMinLen(arr,N);
        string result;
        char current;
        for(int i=0;i<minlen;i++){
            current=arr[0][i];
            for(int j=1;j<N;j++){
                if(arr[j][i]!=current){
                    if(result.length()==0){
                        return "-1";
                    }
                    else {
                        return result;
                    }
                }
                
            }
            result.push_back(current);
        }
        if(result.length()==0){
            return "-1";
        }
        return (result);
        
    }
    
    // sort colors/ dutch national flag
    // two pointer approach - o(n) -- T.c
    https://leetcode.com/problems/sort-colors/
    
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int index=0;
        while(index<=high){
            if(nums[index]==0){
                swap(nums[index],nums[low]);
                low++;
                index++;
            }
            else if(nums[index]==2){
                swap(nums[index],nums[high]);
                // catch 
                // indexx plus plus nhi krna yha pr - bcz we sorted the left side already but right side is not sorted so we again check 
                // index value
                // index++;  XXX   wrong   XXX
                high--;
            }
            else{
                index++;
            }
        }
    }


    // find duplicate element in the array
    https://leetcode.com/problems/find-the-duplicate-number/description/
    class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // visitng technique in this we change the array so this is not good
        // int ans=-1;
        // for(int i=0;i<nums.size();i++){
        //     int index=abs(nums[i]);

        //     // already visit
        //     if(nums[index]<0)return index;

        //     // first visit
        //     nums[index]*= -1;
        // }
        // return ans;

        // second approach
        // positioning method
        while(nums[0] != nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
    
};

};
// Maximum average subarray1
https://leetcode.com/problems/maximum-average-subarray-i/description/
class Solution {
public:

    // o(n^2)
    // double bruteForce(vector<int>& nums, int& k){
    //     int maxSum = INT_MIN;
    //     int i=0,j=k-1;
    //     while(j<nums.size()){
    //         int sum=0;
    //         for(int y=i;y<=j;y++){
    //             sum+=nums[y];
    //         }
    //         maxSum=max(maxSum,sum);
    //         ++i , ++j;
    //     }
    //     double ans=maxSum/(double)k;
    //     return ans;
    // }

    // sliding window approach
    // o(n)
    double slidingWindow(vector<int>& nums, int& k){
        int i=0,j=k-1;
        int sum=0;
        for(int y=i;y<=j;y++){
            sum=sum+nums[y];
        }
        int maxSum=sum;
        j++;
        while(j<nums.size()){
            sum=sum-nums[i++];
            sum=sum+nums[j++];
            maxSum=max(sum,maxSum);
        }
        double ans=maxSum/(double)k;
        return ans;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        // return bruteForce(nums,k);
        return slidingWindow(nums,k);
    }
};

https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// find missing and repeating
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(2);
        for(int i=0;i<n;i++){
            arr[i]--;
        }
        
        // occurence
        for(int i=0;i<n;i++){
            arr[arr[i]%n]+=n;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]/n==2) ans[0]=i+1;
            else if(arr[i]/n==0) ans[1]=i+1;
        }
        return ans;
    }
};