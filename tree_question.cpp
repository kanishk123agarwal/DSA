
// Lowest common ancestor
class LCA
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL){
           return NULL;
       }
       
       if(root->data==n1 || root->data==n2){
           return root;
       }
       
    //    move left part
       Node* leftans=lca(root->left,n1,n2);

    //    move right part
       Node* rightans=lca(root->right,n1,n2);
       
    //    4 cases in which we return some answer
       if(leftans!=NULL && rightans!=NULL){
           return root;
       }
       
       else if(leftans!=NULL && rightans==NULL){
           return leftans;
       }
       
       else if(leftans==NULL && rightans!=NULL){
           return rightans;
       }
       
       else{
           return NULL;
       }
    }
};

// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node) 
class Solution
{
public:
    void solve(Node* root,int sum,int &maxSum,int len,int & maxLen){
        if(root==NULL){

            // if length is greater than max len so we change maxlen bcz we have a idea that this is max node
            if(len>maxLen){
                maxLen=len;
                maxSum =sum;
            }
            else if(len==maxLen){
                maxSum = max(sum,maxSum);
            }
            return;
        }
        
        // add the root data to the sum
        sum+=root->data;
        solve(root->left,sum,maxSum,len+1,maxLen);
        
        solve(root->right,sum,maxSum,len+1,maxLen);
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum=0;
        int maxSum=INT_MIN;
        
        int len=0;
        int maxLen=0;
        
        solve(root,sum,maxSum,len,maxLen);
        return maxSum;
    }
};

// Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
// A path may start from any node and end at any node in the downward direction.

class KPathSum{
  public:
    
    void solve(Node* root,int k,vector<int> path,int &cnt){
        if(root==NULL){
            return;
        }

        // push the initial data to the path
        path.push_back(root->data);

        // move to the leaf node 
        solve(root->left,k,path,cnt);
        solve(root->right,k,path,cnt);
        
        // check the sum is equal to the k then increase the count
        // we do sum from the last 
        int size=path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum=sum+path[i];
            if(sum==k){
                cnt++;
            }
        }
    }
    
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int count=0;
        solve(root,k,path,count);
        return count;
    }
};

// kth ancestor
Node* solve(Node* root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    
    Node* leftans=solve(root->left,k,node);
    Node* rightans= solve(root->right,k,node);
    
    if(leftans!=NULL && rightans==NULL){
        k--;
        // we reach k at the max no of int bcz this doesnot come from there and we return root 
        if(k<=0){
            k=INT_MAX;
            return root;
        }

        // otherwise normally return leftans and decrease the k--
        return leftans;
    }
    
    if(leftans==NULL && rightans!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node){
        return -1;
    }
    else{
        return ans->data;
    }
}


// Maximum sum of non adjacent node
class MaxSumNA{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    
    pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        pair<int,int> res;

        // summ of root node bcz we include the root and both left and right take the exclude term bcz of non adjacent
        res.first=root->data+left.second+right.second;

        // we find the max of both include and exclude from left and right ans
        res.second=max(left.first,left.second) + max(right.first,right.second);
        
        return res;
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        // here first for include the root node
        // second for exclude the root node
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }
};