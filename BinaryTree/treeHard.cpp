// Morris traversal

void morrisTr(Node* root){
    if(root==NULL){
        return;
    }

    Node* curr,*pre;
    curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data;
            curr=curr->right;
        }

        else{
            pre=curr->left;

            // second condition is most important bcz when we create the temporary link so we stop before to 
            // delete the link 
            while(pre->right!=NULL && pre->right != curr){
                pre=pre->right;
            }


// create the temporary link to the curr node
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
// remove the temporary link
            else{
                pre->right=NULL;
                cout<<curr->data;
                curr=curr->right;
            }
        }
    }
}


// Flatten binary tree to linked list 

// Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed.
//  After flattening, left of each node should point to NULL and right should contain next node in preorder.


// ****** THIS QUESTION IS TOTALLY BASED ON MORRIS TRAVERSAL AND THREADED BT
class FlattenBT_LL
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr = root;
        while(curr!=NULL){
            
            if(curr->left){

                // we find out the inorder predecessor then link to the curr->right 
                Node* pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                
                // we remove the link of the right side bcz we create a linked list 
                pred->right=curr->right;
                curr->right=curr->left;

                // According to the question 
                curr->left=NULL;
            }
           
        //    always move to the right side bcz we do left part null

           curr=curr->right;            
            
        }
        
        // left part null
        // curr=root;
        // while(curr!=NULL){
        //     curr->left=NULL;
        //     curr=curr->right;
        // }
    }
};


// Burning Tree 


// ALGO
// 1) WE CREATE A MAP IN WHICH WE STORE THE PARENT NODE
// 2) WE FIND THE TARGET WHERE IT LIES
// 3) IN THIS WE SET SOME CONDITION:

// A) CREATE A MAP OF NODE AND BOOL WHICH SHOW THAT THIS NODE IS VISITED OR NOT
// B) CREATE A QUEUE THAT PUSH THE ELEMENT FROM LEFT,RIGHT,AND PARENT NODE 
class Solution {
  public:
  
   Node* createNodePar(Node* root,int target,map<Node*,Node*> &nodeToParent){
       Node* res;

    //    we use a queue bcz to traverse the tree so we use LEVEL ORDER TR.
       queue<Node*> q;
       q.push(root);
       nodeToParent[root]=NULL;
       
       while(!q.empty()){
           Node* front=q.front();
           q.pop();
           

        //    if target find so we store into the res
           if(front->data==target){
               res=front;
            }
            
            if(front->left){
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
       }
       
       return res;
   }
  
  
    int burnTime(Node* root,map<Node*,Node*> &nodeToParent){
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root]=true;
        
        int ans=0;
        
        while(!q.empty()){
            int size=q.size();

            // we set a flag variable to shoqw that a new element is added in the queue 
            // so we increase the time acc to the flag variable
            bool flag=0;
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=1;
                }
                
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=1;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=true;
                    flag=1;
                }
            }
            
            if(flag==1){
                ans++;
            }
            
        }
        return ans;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> nodeToParent;
        
        Node* targetNode=createNodePar(root,target,nodeToParent);
        
        int ans=burnTime(targetNode,nodeToParent);
        return ans;
    }
};