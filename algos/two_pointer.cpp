// trapping rain water
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        // two pointer approach
        // T.C O(N)  S.C O(1)
        int left=0;
        int right=n-1;
        int leftbar=arr[0];
        int rightbar=arr[n-1];
        long long water=0;
        while(left<=right){
            // to check the limit which one is greater
            if(leftbar<rightbar){
                // if element that you are seeing now ,if that become highest left so we cant store water
                if(arr[left] > leftbar){
                    leftbar=arr[left];
                }
                else{
                    water+=leftbar-arr[left];
                    left++;
                }
            }
            else{
                // if element that you are seeing now ,if that become highest right so we cant store water
                if(arr[right]>rightbar){
                    rightbar=arr[right];
                }
                else{
                    water+=rightbar-arr[right];
                    right--;
                }
            }
        }
        return water;
    }
};


// celebrity problem
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
class Solution 
{
    public:
    // knows function
    
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
    //   We solve with Two pointer approach
    // T.C O(N) , S.C O(1)
        int i=0,j=n-1;
        // step 2 run loop til i<j
        while(i<j){
            // if i knows j so i doesnt celebrity
            if(M[i][j]==1){
                i++;
            }
            else{
                j--;
            }
        }
        int candidate=i;
        // step 3 verify
        for(i=0;i<n;i++){
            if(i!=candidate){
                if(M[candidate][i]==1 || M[i][candidate]==0){
                return -1;
            }
            }
            
        }
        return candidate;
    }
};