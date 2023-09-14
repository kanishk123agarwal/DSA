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