#include<bits/stdc++.h>
using namespace std;
https://leetcode.com/problems/spiral-matrix/description/
54: Spiral Matrix
class Solution {

    // Most important question 
    // print a spiral matrix 
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        int totalSize=m*n;

        int startingRow=0;
        int endingCol=n-1;
        int endingRow=m-1;
        int startingCol=0;
        int count=0;
        while(count<totalSize){
            // printing starting row
            for(int i=startingCol;i<=endingCol && count<totalSize;i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            // printing ending column
            for(int i=startingRow;i<=endingRow && count<totalSize;i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            // printing ending row
            for(int i=endingCol;i>=startingCol && count<totalSize;i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            // printing starting col
            for(int i=endingRow;i>=startingRow && count<totalSize;i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            
            startingCol++;
        } 
        return ans;
    }
};

https://leetcode.com/problems/search-a-2d-matrix/description/
74:search a 2d Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // T.C- O(log(n*m)) S.C- O(1)
        int n=matrix.size();
        int m=matrix[0].size();
        int start=0,end=(n*m)-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            // find row index
            int row=mid/m;
            // find col index
            int col=mid%m;
            if(matrix[row][col]==target) return 1;
            else if(matrix[row][col]<target) start=mid+1;
            else end=mid-1;
        }
        return 0;
    }
};

https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
// Search in Sorted Matrix in which row and column are sorted
class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // T.C- O(n+m) S.C- O(1)
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(mat[i][j]==x) return 1;
            else if(mat[i][j]<x) i++;  //GO DOWN FOR SEARCHING
            else j--;  //GO LEFT FOR SEARCHING 
        }
        return 0;
    }
};