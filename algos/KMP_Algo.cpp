https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
Longest Prefix Suffix
class Solution {
  public:
  // T.C O(N) S.C O(N)
  // it is solved by using KMP Algorithm
    int longestPrefixSuffix(string &s) {
        // Your code goes here
        vector<int> lps(s.size(),0);
        int pre=0,suf=1;
        while(suf<s.size()){
            // Match
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            // not match
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps[s.size()-1];
    }
};

https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
28. Find the Index of the First Occurrence in a String

// optimized by using KMP Algo
class Solution {
public:
  // T.C-O(M+N) , S.C-O(M)
    void findLPS(vector<int> &lps,string s) {
        int pre=0,suf=1;
        while(suf<s.size()){
            // Match
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            // not match
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        findLPS(lps,needle);

        int first=0,second=0;
        while(first<haystack.size()&& second<needle.size()){
            if(haystack[first]==needle[second]){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second-1];
                }
            }
        }
        if(second==needle.size()) return first-second;
        return -1;
    }
};