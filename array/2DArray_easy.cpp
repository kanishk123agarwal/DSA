#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

// sum of row and give the maximum sum of 1 and return index
https://leetcode.com/problems/row-with-maximum-ones/
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int row=0,count=INT_MIN;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[i].size();j++){
                sum=sum+mat[i][j];
            }
            if(count<sum){
                count=sum;
                row=i;
            }
        }
        ans.push_back(row);
        ans.push_back(count);
        return ans; 
    }

    // rotate image
    // rotate 2d matrix by 90 degree
    https://leetcode.com/problems/rotate-image/
    class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the matrix
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // reverse the individual row 
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

    }
};
};

// Rotate matrix by 180 degree
https://www.geeksforgeeks.org/problems/c-matrix-rotation-by-180-degree0745/1
class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        
        // col reverse
        for(int i=0;i<n;i++){
            int start=0,end=n-1;
            while(start<end){
                swap(mat[start][i],mat[end][i]);
                start++;
                end--;
            }
        }
        
        // row reverse
        for(int i=0;i<n;i++){
            int start=0,end=n-1;
            while(start<end){
                swap(mat[i][start],mat[i][end]);
                start++;
                end--;
            }
        }
    }
};

https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1
Rotate 90 degree anticlockwise 
class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        
        // transpose the matrix
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        
        // reverse column
        for(int j=0;j<n;j++){
            int start=0,end=n-1;
            while(start<end){
                swap(mat[start][j],mat[end][j]);
                start++,end--;
            }
        }
    }
};
