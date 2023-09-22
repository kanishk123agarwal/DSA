#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    // 1910  Remove All Occurrences of a Substring
    https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
    class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos=s.find(part);
        while(pos != string::npos){
            s.erase(pos,part.length());
            pos=s.find(part);
        }
        return s;
    }
};

// 1047. Remove All Adjacent Duplicates In String
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string s) {
        
        // 2nd answer
        string ans="";
        for(int i=0;i<s.length();i++){
            if( (ans.length()>0) && s[i]==ans[ans.length()-1]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
}