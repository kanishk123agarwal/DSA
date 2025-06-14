https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
3:Longest Substring Without Repeating Characters
class Solution {
public:
// T.C-O(N) S.C-O(1)
    int lengthOfLongestSubstring(string s) {
        vector<bool> count(256,0);
        int len=0;
        int first =0,second=0;
        // Delete character till the same element match jispai khade hai hum uske same element ko remove kr rhe hai
        while(second<s.size()){
            while(count[s[second]]){
                count[s[first]]=0;
                first++;
            }
            // jab hume new element milta hain to usko add krte jaate hain and find the length 
            count[s[second]]=1;
            len=max(len,second-first+1);
            second++;
        }
        return len;
    }
};

https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1
Smallest distinct Window
class Solution {
  public:
//   T.C-O(N) S.C-O(1)
    int findSubString(string& str) {
        // code here
        int first=0,second=0,len=str.size(),diff=0;
        vector<int> count(256,0);
        
        // find unique element that present in the array
        while(first<str.size()){
            if(count[str[first]]==0) diff++;
            count[str[first]]++;
            first++;
        }
        
        for(int i=0;i<256;i++){
            count[i]=0;
        }
        first=0;
        while(second<str.size()){
            // diff exist krta hain jb tk
            while(diff && second<str.size()){
                if(count[str[second]]==0) diff--;
                count[str[second]]++;
                second++;
            }
            // we already increase the second so we don't need to (second-first+1)
            len=min(len,second-first);
            
            // diff 1 ho jata hain jab
            
            while(diff!=1){
                // small cache we find length first because first ko delete kr rhe hain and usko baad mai update krenge to length aur small ho skti hain
                len=min(len,second-first);
                count[str[first]]--;
                
                if(count[str[first]]==0) diff++;
                first++;
                
            }
        }
        return len;
    }
};

https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
Zero Sum Subarrays
class Solution {
  // T.C-O(N) S.C-O(N)
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        int total=0;
        unordered_map<int,int> m;
        m[0]=1;
        int prefixSum=0;
        for(int i=0;i<arr.size();i++){
            prefixSum+=arr[i];
            if(m.count(prefixSum)){
                total+=m[prefixSum];
                m[prefixSum]++;
            }
            else m[prefixSum]++;
        }
        return total;
    }
};

https://leetcode.com/problems/subarray-sum-equals-k/description/
560:Subarray Sum Equals K
class Solution {
  // T.C-O(N) S.C-O(N)
public:
    int subarraySum(vector<int>& nums, int k) {
        int total=0,prefixSum=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            if(m.count(prefixSum-k)){
                total+=m[prefixSum-k];
                m[prefixSum]++;
            }
            else{
                m[prefixSum]++;
            }
        }
        return total;
    }
};

https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
974:Subarray Sums Divisible by K
class Solution {
  // T.C-O(N) S.C-O(N)
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int total=0,prefixSum=0,rem;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            rem=prefixSum%k;

            if(rem<0) rem=rem+k;

            if(m.count(rem)){
                total+=m[rem];
                m[rem]++;
            }
            else{
                m[rem]=1;
            }
        }
        return total;        
    }
};

https://leetcode.com/problems/subarray-product-less-than-k/description/
713:Subarray Product Less Than K
class Solution {
  // T.C-O(N) S.C-O(1)
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start=0,end=0,product=1,count=0;
        while(end<nums.size()){
            product*=nums[end];
            while(product>=k && start<=end){
                product/=nums[start];
                start++;
            }
            count+=end-start+1;
            end++;
        }
        return count;
    }
};

https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/
2302: Count Subarrays With Score Less Than K

class Solution {
  // T.C-O(N) S.C-O(1)
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int count=0,prefixSum=0,size,sum;
        int start=0,end=0;
        while(end<nums.size()){
            prefixSum+=nums[end];
            size=end-start+1;
            sum=prefixSum*size;
            while(sum>=k && start<=end){
                prefixSum-=nums[start];
                start++;
                size=end-start+1;
                sum=prefixSum*size;
            }
            count+=size;
            end++;
        }
        return count;
    }
};

https://leetcode.com/problems/minimum-size-subarray-sum/description/
209:Minimum size subarray sum 
class Solution {
    // T.C-O(N) S.C-O(1)
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0,size=INT_MAX;
        int sum=0;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=target){
                size=min(size,end-start+1);
                sum-=nums[start++];
            }
            end++;
        }
        // this case handle when the size is not updated and target value is big 
        if(size==INT_MAX) return 0;
        return size;
    }
};

https://leetcode.com/problems/minimum-window-substring/description/
76:Minimum window substring
class Solution {
public:
// let s.size()=n and t.size()=m
    // T.C-O(N) S.C-O(N)
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        int total=t.size();
        // find the number of character to be searched 
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }

        int start=0,end=0,ans=INT_MAX,index=-1;
        while(end<s.size()){
            // when we increase the window size so we decrease total and update in map
            m[s[end]]--;
            // if character is goes 1 to 0 then we update the total
            if(m[s[end]]>=0) total--;

            // when we see that total is 0 so we see all character present in t and now decrease the size of window to find minimum size
            while(!total && start<=end){
                if(ans>end-start+1){
                    ans=end-start+1;
                    index=start;
                }
                m[s[start]]++;
                if(m[s[start]]>0) total++;
                start++;
            }
            end++;
        }  
        if(index==-1) return "";
        string result;
        for(int i=index;i<index+ans;i++){
            result+=s[i];
        }
        return result;
    }
};

https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
2958:Length of Longest Subarray With At Most K Frequency
class Solution {
public:
// T.C-O(N) S.C-O(N)
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int len=0,start=0,end=0;
        while(end<nums.size()){
            count[nums[end]]++;
            while(count[nums[end]]>k){
                count[nums[start]]--;
                start++;
            }
            len=max(len,end-start+1);
            end++;
        }
        return len;
    }
};


https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
2962:Count Subarrays Where Maximum Element Appears at Least K Times

class Solution {
public:
// T.C-O(N) S.C-O(1)
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle=0;
        // find out the maxelement
        for(int i=0;i<nums.size();i++){
            if(maxEle<nums[i]) maxEle=nums[i];
        }
        int start=0,end=0,n=nums.size();
        long long int total=0,ans=0;
        while(end<n){
            if(nums[end]==maxEle) total++;
            while(total==k && start<=end){
                ans+=n-end;
                if(nums[start]==maxEle) total--;
                start++;
            }
            end++;
        }
        return ans;
    }
};

https://leetcode.com/problems/subarrays-with-k-different-integers/description/
992: Subarrays with K Different Integers
class Solution {
public:
// T.C-O(N) S.C-O(N)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // exactly(k)=atleast(k)-atleast(k+1);
        // exactly(k)=atmost(k)-atmost(k-1);
        unordered_map<int,int> freq;
        int total=0;
        int start=0,end=0,n=nums.size(),count=0;
        // atleast(k)
        while(end<n){
            freq[nums[end]]++;
            if(freq[nums[end]]==1) count++;

            while(count==k){
                total+=n-end;
                freq[nums[start]]--;
                if(freq[nums[start]]==0) count--;
                start++;
            }
            end++;
        }

        start=0,end=0,count=0;
        k++;
        freq.clear();

        while(end<n){
            freq[nums[end]]++;
            if(freq[nums[end]]==1) count++;

            while(count==k){
                total-=n-end;
                freq[nums[start]]--;
                if(freq[nums[start]]==0) count--;
                start++;
            }
            end++;
        }
        return total;
    }
};