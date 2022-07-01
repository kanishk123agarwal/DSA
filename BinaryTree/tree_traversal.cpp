
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

ZigZag Traversal: https://practice.geeksforgeeks.org/pr...
- Boundary Traversal:https://practice.geeksforgeeks.org/pr...
- Vertical Order Traversal:https://practice.geeksforgeeks.org/pr...

//Boundary traversal
class BoundryTr {

//     The idea is to split the problem into 3 parts:

// Print the left boundary in a top-down fashion.
// Print the leaf nodes in the same order as in the inorder traversal.
// Print the right boundary in a bottom-up fashion.

// This approach looks simple, but there are several edge cases the solution should handle to avoid printing duplicates:

// Both the left boundary and the right boundary traversal prints the root node.
//  We can avoid this by printing the root node first and performing the left boundary traversal on the root’s left child and
//  the right boundary traversal on the root’s right child.
// The leftmost and the rightmost node of the binary tree are leaf nodes. 
// They will get printed while performing the left boundary and the right boundary traversal while printing the leaf nodes. 
// To avoid it, exclude the leaf nodes while doing the left boundary and the right boundary traversal.




    
    //traverse the left part 
    void traverseLeft(Node* root,vector<int> &ans){
        if ((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseLeft(root->left,ans);
        }
        else{
            traverseLeft(root->right,ans);
        }
    }
    
    //traverse thee leaf node
    
    void traverseLeaf(Node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    
    //traverse the right part
    void traverseRight(Node* root,vector<int> &ans){
         if ((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        if(root->right){
            traverseRight(root->right,ans);
        }
        
        else{
            traverseRight(root->left,ans);
        }
        
        ans.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        //left part
        traverseLeft(root->left,ans);
        
        //left subtree
        traverseLeaf(root->left,ans);
        
        //right subtree
        traverseLeaf(root->right,ans);
        
        //right part
        traverseRight(root->right,ans);
        
        return ans;
    }
};


//Zig zag trav
class ZigZagTr{


 vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result;
    	if(root==NULL){
    	    return result;
    	}
    //declare queue
    	queue<Node*> q;
    	q.push(root);

        //this is a flag for to show the left to right and right to left when we do level order traversal
    	bool LToR=true;
    	while(!q.empty()){
    	    int size=q.size();
            //store the temporary answer or store the element of every traversal acc to LToR 
    	    vector<int>ans(size);
    	    for(int i=0;i<size;i++){
    	        Node* frontnode=q.front();
    	        q.pop();

                // if LToR i true then always store the element acc to i otherwise second one
    	        int index=LToR?i:size-1-i;
    	        ans[index]=frontnode->data;

                // move left side of the tree
    	        if(frontnode->left){
    	            q.push(frontnode->left);
    	        }
                
                // move right side of the tree
    	        if(frontnode->right){
    	            q.push(frontnode->right);
    	        }
    	    }

            // after every traversl we change the flag variable
    	    LToR=!LToR;
            // push the element in the result acc to the ans
    	    for(auto i:ans){
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }
};

//vertical traversal
class VerticalTr
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here

        // We make a map of map in which we have hd,lvl,node->data
        map<int ,map< int,vector<int> > > nodes;
        // make a queue for level order traversal
        queue< pair<Node* , pair<int,int> > > q;
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){

            // temp only take queue front data in the formn of pair
            pair<Node* , pair<int,int> > temp = q.front();
            q.pop();
            Node* frontnode=temp.first;
            int hd=temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontnode->data);
            
            // for left side hd always -1 from root node 
            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }

            // for right side hd always +1 from root node
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i: nodes){
            for(auto j: i.second){
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

// diagonal view
void diagonalview(Node* root,int dis,map<int,vector<int> > &m){
    if(root==NULL){
        return;
    }
    m[dis].push_back(root->data);

// both recursive call are implemented when we come back 
    // do recursive when left side go so we increase distance +1 
    diagonalview(root->left,dis+1,m);

    // do recursive when the right side so we same the distance 
    diagonalview(root->right,dis,m);
}
vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   if(root==NULL){
       return ans;
   }

//    map create 
   map<int,vector<int> > nodes;
   diagonalview(root,0,nodes);
   for(auto i: nodes){
       for(auto j: i.second){
           ans.push_back(j);
       }
   }
   return ans;
}
