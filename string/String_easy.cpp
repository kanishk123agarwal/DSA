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

// valid palindrome 2 -- remove at most 1 element and then check this is a palindrome or not 
https://leetcode.com/problems/valid-palindrome-ii/description/
class Solution {
public:

    bool checkPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                // to mai ek element remove kr skta hu 
                // only 1 allowed 

                // is baar i ke side ka remove
                bool left=checkPalindrome(s,i+1,j);

                // is baar j ke side ka remove krenge
                bool right=checkPalindrome(s,i,j-1);
                return left||right;
            }
        }
        return true;
    }
};

// 2325. Decode the Message
https://leetcode.com/problems/decode-the-message/description/
class Solution {
public:
    string decodeMessage(string key, string message) {
        // create mapping
        char start='a';
        char mapping[280]={0};
        // for each loop
        for(auto ch : key){
            if(ch != ' ' && mapping[ch] ==0){ //it's take because repeat of element is not coming that's why we give array size and give to 0 for all element
                mapping[ch]=start;
                start++;
            }
        }

        // use mapping
        string ans;
        for(int i=0;i<message.length();i++){
            char ch=message[i];
            if(ch==' '){
                ans.push_back(' ');
            }
            else{
                char decodedChar=mapping[ch];
                ans.push_back(decodedChar);
            }
            
        }
        return ans;
    }
};