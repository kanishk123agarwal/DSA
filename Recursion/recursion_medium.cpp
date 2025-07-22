#include <bits/stdc++.h>
using namespace std;
https://leetcode.com/problems/subsets/description/
78: Subsets
class Solution {
  // T.C-O(2^n) S.C-O(n*2^n+n^2)==O(n*2^n)
public:
// optimized space by giving temp as a reference variable and not creating a new vector everytime when we call the function so in last we pop_back the temp value 
    void subseq(vector<int>& nums,int index,int n,vector<vector<int>>& ans,vector<int> temp){

        // base condition
        if(n==index){
            ans.push_back(temp);
            return;
        }

        // no selection
        subseq(nums,index+1,n,ans,temp);

        // yes
        temp.push_back(nums[index]);
        subseq(nums,index+1,n,ans,temp);
        // temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        subseq(nums,0,n,ans,temp);
        return ans;
    }
};


https://leetcode.com/problems/generate-parentheses/description/
22: Generate Parentheses

class Solution {
public:
  // T.C-O(2^n*n) S.C-O(n)
    void parenthesis(int n,int left,int right,vector<string>& ans,string& temp){
        // base condition
        if(left+right==2*n){
            ans.push_back(temp);
            return;
        }

        // for left 
        if(left<n){
            temp.push_back('(');
            parenthesis(n,left+1,right,ans,temp);
            temp.pop_back();
        }

        // for right
        if(right<left){
            temp.push_back(')');
            parenthesis(n,left,right+1,ans,temp);
            temp.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        parenthesis(n,0,0,ans,temp);
        return ans;
    }
};

https://leetcode.com/problems/permutations/description/
46:Permutations
class Solution {
public:
// T.C - O(N! * N) S.C - O(N)
    void permuteFun(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,vector<bool> visited){
        if(nums.size()==temp.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                temp.push_back(nums[i]);
                permuteFun(nums,ans,temp,visited);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        permuteFun(nums,ans,temp,visited);
        return ans;
    }
};

// ___________________________________________________
// SAME QUESTION WITHOUT USING TEMP AND VISITED ARRAY
// ___________________________________________________
class Solution {
public:
// T.C - O(N! * N) S.C - O(N)
    void permuteFun(vector<int>& nums,vector<vector<int>>& ans,int index){
        if(nums.size()==index){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            permuteFun(nums,ans,index+1);
            swap(nums[i],nums[index]);
            
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        permuteFun(nums,ans,0);
        return ans;
    }
};


https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
// Tower of Hanoi
class Solution {
  public:
//      T.C-O(2^n) S.C-O(n)
    // You need to complete this function

    void tohCal(int n,int source,int help,int dest){
        if(n==1){
            // cout<<"move disk "<<n<<" from  rod "<<source<<" to rod "<<dest<<endl;
            return;
        }
        
        tohCal(n-1,source,dest,help);
        // cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<dest<<endl;
        tohCal(n-1,help,source,dest);
    }

    int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        // tohCal(n,from,aux,to);
        return pow(2,n)-1;
        
    }
};


https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
1823: Find the Winner of the Circular Game
class Solution {
public:
//  T.C-O(n^2) S.C-O(n)
    int winner(vector<bool>& person,int n,int index,int person_left,int k){
        if(person_left==1){
            for(int i=0;i<n;i++){
                if(person[i]==0) return i;
            }
        }

        // Find the position kill
        int kill=(k-1)%person_left;
        while(kill--){
            index=(index+1)%n;
            while(person[index]==1){
                index=(index+1)%n;  //skip the kill person
            }
        }

        person[index]=1;
        while(person[index]==1){
            index=(index+1)%n;
        }
        return winner(person,n,index,person_left-1,k);
    }

    int findTheWinner(int n, int k) {
        vector<bool> person(n,0);
        return winner(person,n,0,n,k)+1;
    }
};

// without any extra space
class Solution {
public:
    // T.C-O(n) S.C-O(1)
    int winner(int n,int k){
        if(n==1)return 0;
        return (winner(n-1,k)+k)%n;
    }

    int findTheWinner(int n, int k) {
        return winner(n,k)+1;
    }
};

https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
// Print n bit binary numbers having more 1s than 0s
class Solution {
  public:
  
  void nBit(int n,vector<string>& ans,string& temp,int zero,int one){
      if(temp.size()==n){
          ans.push_back(temp);
          return;
      }
      
      if(zero<one){
          temp.push_back('0');
          nBit(n,ans,temp,zero+1,one);
          temp.pop_back();
      }
      temp.push_back('1');
      nBit(n,ans,temp,zero,one+1);
      temp.pop_back();
  }
  
    vector<string> NBitBinary(int n) {
        // Your code goes here
        vector<string> ans;
        string temp;
        nBit(n,ans,temp,0,0);
        sort(ans.begin(),ans.end(),greater<string>());
        return ans;
    }
};