#include<bits/stdc++.h>
using namespace std;
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