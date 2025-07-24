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

// celebrity problem
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// USING STACK T.C O(N) S.C O(N);
// second approach in two pointer approach
class Solution 
{
    public:
    // knows function
    bool know(vector<vector<int> >& M,int a,int b){
        if(M[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        // push all the element into the stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        // step 2 run till stack can have only one candidate;
        while(s.size() > 1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(know(M,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int candidate = s.top();
        s.pop();
        
        // step 3 verify
        bool rowCheck=false;
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i] == 0){
                zeroCount++;
            }
        }
        if(zeroCount==n){
            rowCheck=true;
        }
        
        // for column
        bool colCheck=false;
        int oneCount=0;
        for(int i=0;i<n;i++){
            if(M[i][candidate] == 1){
                oneCount++;
            }
        }
        // except diagonally
        if(oneCount==n-1){
            colCheck=true;
        }
        if(rowCheck==true && colCheck==true){
            return candidate;
        }
        return -1;
    }
};

// 532: k diff pairs in the array 
https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // two pointer approach
        // ek case fatega to humne uske liye "set" use krliya hai 
        //t.c - o(nlogn) - for sorting 
        // space complexity o(n) for storing the element in the set 
        // it also done with binary search but it also take o(nlogn) time complexity 
        // simple cache that we start two pointer consecutive
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        set<pair<int,int>> ans;
        while(j<nums.size()){
            int diff=nums[j]-nums[i];
            if(diff==k){
                ans.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(diff>k)i++;
            else j++;
            // cache
            if(i==j)j++;
        }
        return ans.size();
    }
};

Maximum element after decreasing and rearranging
https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int res=0,n=arr.size();
        for(auto& el : arr){
            el=min(el,res+1);
            res=el;
        }
        return arr[n-1];
    }
};

https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-daily-week2-day1/problem/smallest-positive-missing-number-1587115621
Smallest positive missing number 
class Solution {
  public:
//   solve using the concept of cycle sort
// T.C-O(N),S.C-O(1)
    int missingNumber(vector<int> &arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            // check the number is in the range or not
            // and after the while loop we put the number of its right position 
            while(arr[i]>=1 && arr[i]<=n && arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
            }
        }
        // array start from 0 and the number range is from 1 to n so we do arr[i-1]
        for(int i=1;i<=n;i++){
            if(i!=arr[i-1]){
                return i;
            }
        }
        // if all number present then the smallest missing number is n+1
        return n+1;
    }
};

https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-daily-week2-day2/problem/sum-of-subarrays2229
Sum of aubarrays
class Solution {
  public:
//   T.C-O(N),S.C-O(1)
    int subarraySum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int result=0;
        // here w see some scenario 
        // 1) arr[i] = the element comes 
        // 2) i+1    = it show the number of times that element comes in a group of subarray
        // 3) n-i    = it show the frequency of that element 
        for(int i=0;i<n;i++){
            result+=(arr[i]*(i+1)*(n-i));
        }
        return result;
    }
};

https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week2/problem/track-the-trail
Local min and max occurence point 
class Solution {
  public:
    vector<int> extractPoints(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans;
        
        if(n==0) return ans;
        
        // insert the  first element 
        ans.push_back(arr[0]);
        
        for(int i=1;i<n-1;){
            int prev=arr[i-1];
            int curr=arr[i];
            
            // take j for skip the same elementor we collapse the element 
            int j=i;
            while(j<n-1 && arr[j]==arr[j+1]) ++j;
            
            int next=arr[j+1];
            
            // check for max || check for min point 
            if((curr>prev && curr>next) ||(curr<prev && curr<next)){
                ans.push_back(curr);
            }
            
            // if common element comes so i increased by that amt
            i=j+1;
        }
        // this case handle for 2 element that are equal so we don't push in the array 
        if(n>1 && ans.back()!=arr[n-1]) ans.push_back(arr[n-1]);
        
        return ans;
    }
};

https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week2/problem/construct-an-array-from-its-pair-sum-array
construct an array from its pair sum array 
class Solution {
  public:
    // T.C-O(n) S.C-O(1) it neglible of the answer array 
    vector<int> constructArr(vector<int>& arr) {
        // code here
        if(arr.size()==1){
            return {1,arr[0]-1};
        }
        // it comes from n(n-1)/2=arr.size then apply -b+sqrt(b^2-4ac)/2a
        int n=(1+sqrt(1+8*arr.size()))/2;
        
        vector<int> res(n);
        res[0]=(arr[0]+arr[1]-arr[n-1])/2;
        
        for(int i=1;i<n;i++){
            res[i]=arr[i-1]-res[0];
        }
        return res;
    }
};

https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week2/problem/wave-array-1587115621
Wave array 
class Solution {
  public:
    // T.C-O(N) S.C-O(1)
    void sortInWave(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
    }
};

https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week2/problem/max-sum-in-the-configuration
Max sum in the configuration
class Solution {
  public:
//   T.C-O(N) S.C-O(1)
    int maxSum(vector<int> &arr) {
        // code here
        int currSum=0,n=arr.size();
        for(int i=0;i<n;i++){
            currSum+=arr[i];
        }
        
        int currVal=0;
        for(int i=0;i<n;i++){
            currVal+=i*arr[i];
        }
        
        int res=currVal;
        int nextVal=0;
        for(int i=1;i<n;i++){
            nextVal=currVal-(currSum-arr[i-1])+arr[i-1]*(n-1);
            
            currVal=nextVal;
            res=max(res,nextVal);
        }
        return res;
    }
};

https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week2/problem/maximum-product-subarray3604
Maximum product subarray
class Solution {
  public:
    // T.C-O(N) S.C-O(1)
    int maxProduct(vector<int> &arr) {
        // code here
        int maxi=INT_MIN;
        int n=arr.size();
        int left=1,right=1;
        for(int i=0;i<n;i++){
            if(left==0) left=1;
            if(right==0) right=1;
            
            left=left*arr[i];
            
            int idx=n-i-1;
            right=right*arr[idx];
            maxi=max({maxi,left,right});
        }
        return maxi;
    }
};

https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week2/problem/majority-element-1587115620
Majority element
class Solution {
  public:
    // T.C-O(N) S.C-O(1)
    int majorityElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int cnt=0;
        int candidate=-1;
        
        // find a candidate
        for(int num:arr){
            if(cnt==0){
                cnt=1;
                candidate=num;
            }
            else if(num==candidate) cnt++;
            else cnt--;
        }
        // frequency of candidate find out if it isbigger than arr.size()/2
        cnt=0;
        for(int num:arr){
            if(num==candidate) cnt++;
        }
        
        if(cnt>n/2){
            return candidate;
        }
        else{
            return -1;
        }
    }
};