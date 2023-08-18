#include<bits/stdc++.h>
using namespace std;

// BST iterator
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
       pushAll(root); 
    }
    
    int next() {
        TreeNode* next=st.top();
        st.pop();
        pushAll(next->right);
        return next->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
    private:
    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    
};

