//top view 
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node*left ,*right;
}
class TopView
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> topnode;
        queue<pair<Node* ,int>> q;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node* ,int> temp = q.front();
            q.pop();
            Node* frontnode=temp.first;
            int hd=temp.second;
            
            // skip krdo after entering the one node at one hd 
            if(topnode.find(hd)==topnode.end()){
                topnode[hd]=frontnode->data;
            }
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:topnode){
            ans.push_back(i.second);
        }
        return ans;
    }

};



// bottom view
class BottomView {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> topnode;
        queue<pair<Node* ,int>> q;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node* ,int> temp = q.front();
            q.pop();
            Node* frontnode=temp.first;
            int hd=temp.second;
            
            // skip krdo after entering the one node at one hd 
            
                topnode[hd]=frontnode->data;
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:topnode){
            ans.push_back(i.second);
        }
        return ans;
    }
};


// left view
void solve(Node* root,vector<int> & ans,int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}



// right view
class Rightview
{
    
    void solve(Node* root,vector<int> & ans,int level){
        if(root==NULL){
          return;
        }
        if(level==ans.size()){
          ans.push_back(root->data);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
        
    }
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }
};
