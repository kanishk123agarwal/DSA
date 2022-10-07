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

