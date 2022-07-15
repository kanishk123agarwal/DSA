// Rat in maze
https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


 bool isSafe(int newx,int newy,vector<vector<bool>> &vis,vector<vector<int>> &arr,int n){
    // we check the 3 condition here
    // x and y in the range 
    // not visited the row and column
    // check arr[row][c ol] == 1 if 0 so we dont go there
        if((newx>=0 && newx<n) && (newy>=0 && newy<n)  && vis[newx][newy] != 1  &&
        arr[newx][newy] == 1){
            return true;
        }
        return false;
    }
    
    
    
    // it traverse the whole matrix and find all possible solution 
    void solve(int x,int y,vector<vector<int>> &arr,int n,vector<string> &ans,
    vector<vector<bool>> &vis,string path){
        
        // base case 
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
         
        //  we visited the corresponding 1 to row and col
        vis[x][y]=1;
        // here we go for the 4 movement
        
        // DOWN
        if(isSafe(x+1,y,vis,arr,n)){
            solve(x+1,y,arr,n,ans,vis,path+'D');
        }
        
        // Left
        if(isSafe(x,y-1,vis,arr,n )){
            solve(x,y-1,arr,n,ans,vis,path+'L');
        }
        
        // right
        if(isSafe(x,y+1,vis,arr,n)){
            solve(x,y+1,arr,n,ans,vis,path+'R');
        }
        
        // UP
        if(isSafe(x-1,y,vis,arr,n)){
            solve(x-1,y,arr,n,ans,vis,path+'U');
        }
        vis[x][y]=0;
        
    }



vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
        // visited vector that show where i am going 
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        string path="";
        if(arr[0][0]==0){
            return ans;
        }
        solve(0,0,arr,n,ans,visited,path);
        return ans;
}

// sudoku solver
https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


bool isSafe(int row,int col,vector<vector<int>> &board,int val){
    for(int i=0;i<board.size();i++){
//         for row
        if(board[row][i]==val){
            return false;
        }
//         for col
        if(board[i][col]==val){
            return false;
        }
//         for 3*3 matrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}



bool solve(vector<vector<int>> &board){
   int n=board[0].size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
//             empty cell
            if(board[row][col]==0){
//                 put the value where we find the 0 value 
                for(int val=1;val<=9;val++){
//                     we try for all 9 valuee here 
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
//                         recursive call 
                        bool forwardSol=solve(board);
                        if(forwardSol){
                            return true;
                        }
                        else{
//                             backtrack
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}