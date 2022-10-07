// Minimum no of elements to reach end point in the array 
// By solving dp TC O(N2) SC O(N);
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n<=1){
            return 0;
        }
        
        if(arr[0] == 0){
            return -1;
        }
        
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(i<=(j+arr[j])){
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        if(dp[n-1] == INT_MAX){
            return -1;
        }
        return dp[n-1];
    }
};


// BY  SOLVING GREEDY T.C O(N) S.C O(1);
class Solution{
  public:
    // by using greedy 
        if(n<=1)
            return 0;
        if(arr[0] == 0){
            return -1;
        }
        
        // we declare 3 variable
        int maxReach=arr[0];
        int steps=arr[0];
        int jump=1;
        for(int i=1;i<n;i++){
            if(i==n-1){
                return jump;
            }
            maxReach=max(maxReach,i+arr[i]);
            steps--;
            if(steps==0){
                jump++;
                // checking for ith index not goes to the out of maxReach 
                if(i >= maxReach){
                    return -1;
                }
                // it means we take that steps also with the same jump
                steps=maxReach-i;
            }
        }
        return -1;
    }
};

https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// TRAPPING RAIN WATER PROBLEM

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        // PRECALCULATION
        // TC O(N)  S.C O(N)
        int left[n],right[n];
        left[0]=arr[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],arr[i]);
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],arr[i]);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(min(left[i],right[i]) - arr[i]);
        }
        return ans;
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