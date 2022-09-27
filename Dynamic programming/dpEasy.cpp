
// https://leetcode.com/problems/min-cost-climbing-stairs/
// MINIMUM COST OF CLIMBING STAIRS 
class Solution {
public:
    
//     top to down appraoch  TC - O(n)   SC - O(n) + O(n)
    
//     int solve(vector<int>& cost,int n,vector<int>& dp){
// //         base case
// //         here we decide two test case for the climb stairs because we can start with 0 or 1 
// //         level
//         if(n == 0){
//             return cost[0];
//         }
//         if(n == 1){
//             return cost[1];
//         }
        
//         if(dp[n] != -1){
//             return dp[n];
//         }
        
// //         store the value in dp at only one time 
//         dp[n] = cost[n] + min(solve(cost,n-1,dp) , solve(cost,n-2,dp));
//         return dp[n];
//     }
    
    
//     bottom to up approach  -- tabulation  TC - O(n)  SC - O(n)
    int solve2(vector<int>& cost,int n){
         
        vector<int>dp(n+1);
        
//         base case
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        return min(dp[n-1] , dp[n-2]);
    }
    
// optimized space  TC - O(n)   SC - O(1)
    int solve3(vector<int>& cost , int n){
        int prev2=cost[0];
        int prev1=cost[1];
        
        for(int i=2;i<n;i++){
            int curr = cost[i] + min(prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
//         first no of cost
        // int n=cost.size();
        
//         now we use recursion wtih memory -- DP
        // vector<int> dp(n+1,-1);
        // int ans=min(solve(cost,n-1,dp) , solve(cost,n-2,dp));
        // return ans;
        
        
//         for solve2
        // int n=cost.size();
        // return solve2(cost,n);
        
        // solve3
        int n=cost.size();
        return solve3(cost,n);
        
    }
};
