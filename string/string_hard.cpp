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

// Brute force
class Solution{
  public:
  // T.C-O((N-M)*M)=O(NM) , S.C-O(1)
  int strstr(string haystack,string needle){
    int n=haystack.size(),m=needle.size();
    for(int i=0;i<=n-m;i++){
      int first=i,second=0;
      while(second<m){
        if(haystack[first]==needle[second]){
          first++;
          second++;
        }
        else{
          break;
        }
      }
      if(second==m){
        return i;
      }
    }
    return -1;
  }
};


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


https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1
Min characters to be added at front to make string palindrome
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string rev=s;
        reverse(rev.begin(),rev.end());
        // original string size;
        int size=s.size();
        s+='$';
        s+=rev;
        // string size combine with $ and rev string
        int n=s.size();
        // find lps using KMP Algo
        vector<int> lps(n,0);
        int pre=0,suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++,suf++;
            }
            else{
                if(pre==0) suf++;
                else{
                    pre=lps[pre-1];
                }
            }
        }
        // yeh hume last mai yeh batayega ki kitna string ka part palidrome ko follow kr rha hain jitna kr rha hoga usko original mai se substract kr denge 
        return (size-lps[n-1]);
    }
};


https://leetcode.com/problems/repeated-string-match/description/
686:Repeated String Match

class Solution {
public:
        // both function findLPS and KMP_Match is string match question and same code main is repeated string match function
    void findLPS(vector<int>& lps,string s){
        int pre=0,suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0) suf++;
                else{
                    pre=lps[pre-1];
                }
            }
        }
    }

    int KMP_Match(string a,string b){
        vector<int> lps(b.size(),0);
        findLPS(lps,b);

        int first=0,second=0;
        while(first<a.size() && second<b.size()){
            if(a[first]==b[second]){
                first++;
                second++;
            }
            else{
                if(second==0) first++;
                else{
                    second=lps[second-1];
                }
            }
        }
        if(second==b.size()) return 1;
        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        // base case if string is match so why we do KMP search 
        if(a==b) return 1;
        string temp=a;
        int repeat=1;

        // add string till the size of b
        while(temp.size()<b.size()){
            temp+=a;
            repeat++;
        }

        // KMP pattern match
        if(KMP_Match(temp,b)==1) return repeat;

        // Not match so we increase temp by 1
        if(KMP_Match(temp+a,b)==1) return repeat+1;

        return -1;
    }
};