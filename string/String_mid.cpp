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

// sort vowels in a string 
https://leetcode.com/problems/sort-vowels-in-a-string/description/

class Solution {
public:
bool isVowel(char ch){
    switch(ch){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U': 
           return true;
        default:
           return false;
    }
    return false;
}
    string sortVowels(string s) {
        // store vowels
        vector<char> vow;
        for(char ch:s){
            if(isVowel(ch))vow.push_back(ch);
        }

        // sort vowels
        sort(vow.begin(),vow.end());

        // updating string
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=vow[j];
                j++;
            }
        }
        return s;
    }
};

// Unique length-3 palindromic subsequences
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>left(26);
        vector<int>right(26);
        unordered_set<string>h;

        // right fill 
        for(int i=0;i<s.size();i++){
            right[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            // remove element from the right and fill in the left array 
            right[s[i]-'a']--;
            for(int j=0;j<26;j++){
                // if the size of both array is larger than 0 then we add element 
                if(left[j]>0 && right[j]>0){
                    char x='a'+j;
                    string palindrome="";
                    palindrome+=x;
                    palindrome+=s[i];
                    palindrome+=x;

                    if(h.count(palindrome)==true){
                        continue;
                    }
                    h.insert(palindrome);
                }
            }
            left[s[i]-'a']++;
        }
        return h.size();
    }
};

https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1
Case-specific sorting of strings
class Solution {
  public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n) {
        // your code here
        int lower[26]={0};
        int upper[26]={0};
        
        int i=0;
        while(i<n){
            if(str[i]>='a'){
                lower[str[i]-'a']++;
            }
            else  upper[str[i]-'A']++;
            i++;
        }
        int l=0,u=0;
        string result=str;
        for(int j=0;j<n;j++){
            if(str[j]>='a'){
                while(lower[l]== 0){ l++; }
                result[j]='a'+l;
                lower[l]--;
            }
            else{
                while(upper[u]== 0) u++;
                result[j]='A'+u;
                upper[u]--;
            }
        }
        return result;
    }
};

https://leetcode.com/problems/roman-to-integer/description/
13:Roman to integer
class Solution {
public:

    int num(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        int sum=0;
        int index=0;
        while(index<s.size()-1){
            if(num(s[index]) < num(s[index+1])) sum-=num(s[index]);
            else sum+=num(s[index]);
            index++;
        }
        sum+=num(s[index]);
        return sum;
    }
};

https://leetcode.com/problems/integer-to-roman/description/
12:Integer to Roman
class Solution {
public:
    string intToRoman(int num) {
        string ones[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hund[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thous[]={"","M","MM","MMM"};

        return thous[num/1000]+hund[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

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