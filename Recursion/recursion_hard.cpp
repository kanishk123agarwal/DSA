https://leetcode.com/problems/permutations-ii/description/
47:Permutations II
class Solution {
    // Time Complexity: O(n × n!)

    // Auxiliary Space Complexity: O(n)
public:

    void permutation(vector<int>& nums,vector<vector<int>>& ans,vector<int>& curr,vector<bool>& visited){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
            if(!visited[i]){
                visited[i]=true;
                curr.push_back(nums[i]);
                permutation(nums,ans,curr,visited);
                curr.pop_back();
                visited[i]=false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(),false);
        permutation(nums,ans,curr,visited);
        return ans;
    }
};

https://leetcode.com/problems/palindrome-partitioning/
131: Palindrome Partitioning

class Solution {
public:
    // T.C-O(N*2^N) S.C-O(N*2^N) HERE 2^N FOR STORAGE OF THE STRING
    bool isPalindrome(string sub){
        int i=0,j=sub.size()-1;
        while(i<j){
            if(sub[i]!=sub[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void partitioning(string s,vector<vector<string>>& ans,vector<string> &curr,int start){
        if(start==s.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=start;i<s.size();i++){
            string sub=s.substr(start,i-start+1);
            if(isPalindrome(sub)){
                curr.push_back(sub);
                partitioning(s,ans,curr,i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        partitioning(s,ans,curr,0);
        return ans;
    }
};

https://leetcode.com/problems/sudoku-solver/description/
37:Sudoku Solver
class Solution {
public:
    // T.C-O(9^81) S.C-O(1)-(RECURSION +BOARD NEAARLY ORDER OF 1)
    pair<int,int> findEmptyCell(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') return {i,j};
            }
        }
        return {-1,-1};
    }

    bool isValid(vector<vector<char>>& board,char num,int row,int col){
        // row check
        for(int j=0;j<9;j++){
            if(board[row][j]==num) return false;
        }

        // for col
        for(int i=0;i<9;i++){
            if(board[i][col]==num) return false;
        }

        // for 3*3 grid
        int startRow=row-row%3;
        int startCol=col-col%3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[startRow+i][startCol+j]==num) return false;
            }
        }
        return true;
    }

    bool sudoku(vector<vector<char>>& board){
        auto [row,col]=findEmptyCell(board);

        if(row==-1 && col==-1) return true;
        for(char num='1';num<='9';num++){
            if(isValid(board,num,row,col)){
                board[row][col]=num;

                if(sudoku(board)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};

https://leetcode.com/problems/n-queens/description/
51:N-Queens
class Solution {
public:
    // T.C-O(N^N.N) S.C-O(N^2) -EXCLUDING OUTPUT STORAGE 
    bool isSafe(int row,int col,vector<string>& ans,int n){
        int i=row-1,j=col+1;
        while(i>=0 && j<n){
            if(ans[i][j]=='Q') return false;
            i--;
            j++;
        }
        i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(ans[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row-1,j=col;
        while(i>=0){
            if(ans[i][j]=='Q') return  false;
            i--;
        }
        return true;
    }

    void nQueen(int n,int row,vector<vector<string>>& board,vector<string>& ans){
        if(row==n){
            board.push_back(ans);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(row,col,ans,n)){
                ans[row][col]='Q';
                nQueen(n,row+1,board,ans);
                ans[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board;
        vector<string> ans(n,string(n,'.'));
        nQueen(n,0,board,ans);
        return board;
    }
};