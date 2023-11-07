https://leetcode.com/problems/palindromic-substrings/
// 647 palindromic substring
// very very important
// Desc: issme hum basically odd and even length pr check kr rhe hai 
// usko apne pass lane ki jagah dur lekar jaa rhe hai
class Solution {
public:
    int expand(string s ,int i,int j){
        int ans=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            ans++;
            i--;
            j++;
        }
        
        return ans;
    }

    int countSubstrings(string s) {
        int totalCount=0;
        for(int count=0;count<s.length();count++){
            // odd
            int oddAns=expand(s,count,count);

            // even
            int evenAns=expand(s,count,count+1);
            totalCount=totalCount+oddAns+evenAns;
        }
        return totalCount;
    }
};

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
// 1209 : Remove all adjacent duplicates in string ii 
class Solution {
public:
    string removeDuplicates(string s, int k) {
        // o(n^2)
        // string ans="";
        // int i=0;
        // while(i<s.length()){
        //     if(ans.length()>0 && s[i]!=ans[ans.length()-1]) ans.push_back(s[i]);
        //     else{
        //         int count=0,j=ans.length()-1;
        //         while(j>=0){
        //             if(s[i]==ans[j]) count++;
        //             else break;
        //             j--;
        //         }
        //         if(count==k-1) ans.erase(j+1,k-1);
        //         else ans.push_back(s[i]);
        //     }
        //     i++;
        // }
        // return ans;


        // 2nd approach
        // T.C - O(N)
        // S.C - O(1) BECAUSE IN C++ STRING IS MUTABLE;
        int i=0,n=s.length();
        int count[n];
        for(int j=0;j<s.length();i++,j++){
            s[i]=s[j];
            count[i]=i>0 && s[i-1]==s[j] ? count[i-1]+1:1;
            if(count[i]==k)i=i-k;
        }
        return s.substr(0,i);
    }
};

2391. Minimum Amount of Time to Collect Garbage
https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP=0;
        int pickM=0;
        int pickG=0;

        int travelP=0;
        int travelM=0;
        int travelG=0;

        int lastP=0;
        int lastM=0;
        int lastG=0;
        // calculate picking time for every thing and find the last index
        for(int i=0;i<garbage.size();i++){
            string curr=garbage[i];
            for(int j=0;j<curr.length();j++){
                char ch=curr[j];
                if(ch=='G'){
                    pickG+=1;
                    lastG=i;
                }
                else if(ch=='P'){ 
                    pickP+=1;
                    lastP=i;
                }
                else if(ch=='M'){
                    pickM+=1;
                    lastM=i;
                }
            }
        }

        // calculate the travel time
        for(int i=0;i<lastG;i++){
            travelG+=travel[i];
        }
        for(int i=0;i<lastP;i++){
            travelP+=travel[i];
        }
        for(int i=0;i<lastM;i++){
            travelM+=travel[i];
        }

        int ans=(pickP+travelP)+(pickG+travelG)+(pickM+travelM);
        return ans;
    }
};

791 custom sort string
class Solution {
public:
    static string str;
    static bool compare(char x,char y){
        // this will return true, if position of x in str string is less than the position of y in str string .
        return (str.find(x)<str.find(y));
    }

    string customSortString(string order, string s) {
        str=order;
        sort(s.begin(),s.end(),compare);
        return s;
    }
};
string Solution::str;

https://leetcode.com/problems/find-and-replace-pattern/description/
890 find and replace pattern
class Solution {
public:
// T.C - o(word.length(),pattern.length())
//  this function normalises all the words and pattern into similiar format
    void createMapping(string& str){
        char start='a';
        char mapping[300]={0};
        for(auto ch:str){
            if(mapping[ch]==0){
               mapping[ch]=start;
               start++;
            }
            
        }

        // update
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            str[i]=mapping[ch];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // firstly normalize the pattern string
        createMapping(pattern);

        // words ke saath operation
        for(string str:words){
            string tempS=str;

            // normalize the word
            createMapping(tempS);

            // now check that this is pattern or not
            if(tempS==pattern){
                // it's a valid string that matches the pattern
                ans.push_back(str);
            }
        }
        return ans;
    }
};