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

https://leetcode.com/problems/longest-palindrome/description/
409: Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        // store lowercase and uppercase character 
        vector<int> lower(26,0);
        vector<int> upper(26,0);
        int ans=0;
        // count the character 
        for(int i=0;s[i]!='\0';i++){
            if(s[i]>='a'){
                lower[s[i]-'a']++;
            }
            else upper[s[i]-'A']++;
        }

        // find out the answer
        int odd=0;
        for(int i=0;i<26;i++){
            // if we have even no of character then we add all into making the palindrome list 
            if(lower[i]%2==0) ans+=lower[i];
            else{
                ans+=lower[i]-1;
                odd=1;
            }
            if(upper[i]%2==0) ans+=upper[i];
            else{
                ans+=upper[i]-1;
                odd=1;
            }
        }
        // if we have odd no of character then add one
        ans+=odd;
        return ans;
    }
};

https://leetcode.com/problems/sorting-the-sentence/description/
1859. Sorting the Sentence
class Solution {
public:
    string sortSentence(string s) {
        // we have only 9 word to store so we make the array of size 9
        vector<string> ans(10);
        string temp;
        int index=0,count=0;
        while(s[index]!='\0'){
            if(s[index]==' '){
                // in temp variable it store the number in last position so that out from the string by direct addressing and it give me character value so that's why we minus character 0
                int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                count++;
            }
            // store the character by character and when we encounter space we applied our main logic
            else{
                temp+=s[index];
            }
            index++;
        }
        int pos=temp[temp.size()-1]-'0';
        temp.pop_back();
        ans[pos]=temp;
        temp.clear();
        count++;
        string result;
        // loop is running from 1 to 9 because we have only 9 word and result+=' ' is for space between the word 
        // Here is cache that after the last word it give space so it not a proper answer so we pop back the space 
        for(int i=1;i<=count;i++){
            result+=ans[i];
            result+=' ';
        }
        result.pop_back();
        return result;
    }
};

https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1
String rotated by 2 places
class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string& s1, string& s2) {
        // Your code here
        if(s1.size()!=s2.size()) return false;
        string temp1,temp2;
        
        string s3,s4;
        int i=0;
        while(s1[i]!='\0'){
            if(i<2) temp1+=s1[i];
            else s3+=s1[i];
            if(i<s1.size()-2) s4+=s1[i];
            else temp2+=s1[i];
            i++;
        }
        s3+=temp1;
        s4=temp2+s4;
        i=0;
        while(s2[i]!='\0'){
            if(s2[i]==s3[i]){
                i++;
                continue;
            } 
            else if(s2[i]==s4[i]){
                i++;
                continue;
            }
            else return false;
        }
        return true;
    }
};

// 2nd approach
class Solution {
  public:
  
    void rotateAntiClockWise(string &s){
        int index=1;
        char c=s[0];
        while(index<s.size()){
            s[index-1]=s[index];
            index++;
        }
        s[s.size()-1]=c;
    }
  
    void rotateClockWise(string &s){
        int index=s.size()-2;
        char c=s[s.size()-1];
        while(index>=0){
            s[index+1]=s[index];
            index--;
        }
        s[0]=c;
    }
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string& s1, string& s2) {
        // Your code here
        if(s1.size()!=s2.size()) return false;
        
        string clockwise=s1,anticlockwise=s1;
        
        rotateClockWise(clockwise);
        rotateClockWise(clockwise);
        
        if(clockwise==s2) return true;
        
        rotateAntiClockWise(anticlockwise);
        rotateAntiClockWise(anticlockwise);
        
        if(anticlockwise==s2) return true;
        
        return false;
    }
};

https://leetcode.com/problems/defanging-an-ip-address/description/
1108 : Defanging an IP Address
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        int index=0;
        while(address[index]!='\0'){
            if(address[index]=='.'){
                ans+="[.]";
            }
            else ans+=address[index];
            index++;
        }
        return ans;
    }
};

https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
1832 : Check if the Sentence Is Pangram
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> ans(26,0);
        int i=0;
        while(sentence[i]!='\0'){
            ans[sentence[i]-'a']++;
            i++;
        }
        for(int i=0;i<26;i++){
            if(ans[i]==0) return false;
        }
        return true;
    }
};

https://www.geeksforgeeks.org/problems/sort-a-string2943/1
Sort a string 
string sort(string s) {
    // complete the function here
    
    vector<int> ans(26,0);
        int i=0;
        while(s[i]!='\0'){
            ans[s[i]-'a']++;
            i++;
        }
        string result;
        for(int i=0;i<26;i++){
           char c='a'+i;
           int count=ans[i];
           while(count>0){
               result+=c;
               count--;
           }
        }
        return result;
}

https://leetcode.com/problems/add-strings/description/
415. Add Strings
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1;
        int carry=0,add;
        string ans;
        while(i>=0 && j>=0){
            int no1=num1[i]-'0';
            int no2=num2[j]-'0';
            add=no1+no2+carry;
            carry=add/10;
            add=add%10;
            char c='0'+add;
            ans=c+ans;
            i--;
            j--;
        }

        // for left num1 array
        while(i>=0){
            int no1=num1[i]-'0';
            add=no1+carry;
            carry=add/10;
            add=add%10;
            char c='0'+add;
            ans=c+ans;
            i--;
        }

        // for left num2 array
        while(j>=0){
            int no2=num2[j]-'0';
            add=no2+carry;
            carry=add/10;
            add=add%10;
            char c='0'+add;
            ans=c+ans;
            j--;
        }
        if(carry !=0) {
            char c=carry+'0';
            ans=c+ans;
        }
        return ans;
    }
};
