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