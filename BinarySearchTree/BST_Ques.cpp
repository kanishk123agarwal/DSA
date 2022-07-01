// LCA of two nodes

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    
    if(root==NULL){
        return NULL;
    }
    // check right side of the tree bcz root ka data smaller than p and q ka data 
if(root->data < P->data && root->data < Q->data){
    return LCAinaBST(root->right,P,Q);
}
  if(root->data > P->data && root->data > Q->data){
    return LCAinaBST(root->left,P,Q);
} 
    
    return root;
}



// Predecessor and successor
// to find pred - we search left side of the tree with maximum element
// to find suc - we search right side of the tree with minmum element
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* temp=root;
    int pred=-1;
    int succ=-1;
      

    //   iteration traversal takes o(n)
    while(temp->data != key){
        if(temp->data > key){
            succ=temp->data;
            temp=temp->left;
        }
        
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    
//     find succ and pred
//     pred
// go to left for pred 
    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree!=NULL){

        // when we find the max element so we do traverse in the right
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    // go to the right 
    BinaryTreeNode<int>* rightTree=temp->right;
    while(rightTree!=NULL){
        // when we find the min element so we do traverse in the left
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    
    return {pred,succ};
        
}

// Find kth smallest element 
//  we know that the smallest element find in the left side of the tree so 
// we do inorder traversal and every time increase the i var 
int solve(BinaryTreeNode<int>* root, int k,int &i){
//     base case
    if(root==NULL){
        return -1;
    }
//    left call
    int left=solve(root->left,k,i);
    if(left!=-1){
        return left;
    }
    
    // for the root
    i++;
    if(i==k){
        return root->data;
    }
    

    // right call
    return solve(root->right,k,i);
   
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    int ans=solve(root,k,i);
    return ans;
}


// validate BSt
bool solve(BinaryTreeNode<int> *root,int min,int  max){
    if(root==NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){
        bool left=solve(root->left,min,root->data);
        bool right=solve(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
    
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    bool ans=solve(root,INT_MIN,INT_MAX);
    return ans;
}

// TWO sum in a BST
void inorder(BinaryTreeNode<int>* root,vector<int> &in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here

    // first store the inorder element or 
    // we can say that a sorted manner in vector
    vector<int> inorderVal;
    inorder(root,inorderVal);
    
    int i=0,j=inorderVal.size()-1;
    while(i<j){

        // here we apply two pointer approach 
        int sum=inorderVal[i]+inorderVal[j];
        if(sum== target){
            return true;
        }
        else if(sum > target){
            j--;
            
        }
        else{
            i++;
        }
    }
    return false;
    
    
}

// flatten bst to linked list
void inorder(TreeNode<int>* root,vector<int> &in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    // first store the inorder tr to the vector 
    vector<int> inorderVal;
    inorder(root,inorderVal);
    
    int n=inorderVal.size();

    // make a root that point to the starting of the index of inorder tr.
    TreeNode<int>* newRoot=new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr=newRoot;
    for(int i=1;i<n;i++){
        TreeNode<int>* temp= new TreeNode<int>(inorderVal[i]);
        
        // we do curr ka left and and sorted one point to the further node
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    // for last node we do null for both side of the left and right
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
   
}


// Normal to BST
// here this problem is divided into two problem 
// 1) normal to BST 
// 2) inorder to BST 

void inorder(TreeNode<int>* root,vector<int> &in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

// here we do inorder to balanced BST
TreeNode<int>* inorderToBST(int s,int e,vector<int> &in){
    if(s>e){
        return NULL;
    }
    
    // find mid of the inorder tr. and sent to left part and right part 
    int mid=(s+e)/2;
    TreeNode<int>* root=new TreeNode<int>(in[mid]);
    root->left=inorderToBST(s,mid-1,in);
    root->right=inorderToBST(mid+1,e,in);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here
    
    // first find out inorder tr.and store into the vector
    vector<int> inorderVal;
    inorder(root,inorderVal);
    return inorderToBST(0,inorderVal.size()-1,inorderVal);
}


// preorder to BST - o(n)

BinaryTreeNode<int>* solve(vector<int> &preorder,int min,int max,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    // check the range 
    if(preorder[i] < min || preorder[i] > max){
        return NULL;
    }
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(preorder[i++]);
    root->left=solve(preorder,min,root->data,i);
    root->right=solve(preorder,root->data,max,i);
    return root;
    
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    // we do similiar like a validate bst question 
    int min=INT_MIN;
    int max=INT_MAX;
    int i=0;
    return solve(preorder,min,max,i);
}

// hard
// merge two bst

// make a every tree to the sorted doubly linked list 
void convertIntoSorDLL(TreeNode<int> *root,TreeNode<int> *&head){
    if(root==NULL){
        return;
    }
    convertIntoSorDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    
    head=root;
    convertIntoSorDLL(root->left,head); 
}
// Merge two linked list 
TreeNode<int> * mergeLinkedList(TreeNode<int> *a,TreeNode<int> *b){
    TreeNode<int> *head=NULL;
    TreeNode<int> *tail=NULL;
    
    while(a!=NULL && b!=NULL){
//         for first linnked list
        if(a->data < b->data){
            
            if(head==NULL){
                head=a;
                tail=a;
                a=a->right;
            }
            else{
                tail->right=a;
                a->left=tail;
                tail=a;
                a=a->right;
           }
            
        }
//         for another linked list 
        else{
            if(head==NULL){
                head=b;
                tail=b;
                b=b->right;
            }
            else{
                tail->right=b;
                b->left=tail;
                tail=b;
                b=b->right;
                
            }
        }
    }
    
    while(a!=NULL){
        tail->right=a;
        a->left=tail;
        tail=a;
        a=a->right;
    }
    
    while(b!=NULL){
        tail->right=b;
        b->left=tail;
        tail=b;
        b=b->right;
    }
    
    return head;
}

// calculate the size of sorted linked list
int countNode(TreeNode<int> * &head){
    int cnt=0;
    TreeNode<int> *temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
// make a bst from dll

TreeNode<int> * sortedLLToBST(TreeNode<int> * &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    
    TreeNode<int> *left=sortedLLToBST(head,n/2);
    
    TreeNode<int> *root=head;
    root->left = left;
    
    head=head->right;
    root->right=sortedLLToBST(head,n-n/2-1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
//     step 1 convert bst into sorted ll in place
    TreeNode<int> *head1=NULL;
    convertIntoSorDLL(root1,head1);
    head1->left=NULL;
    
    TreeNode<int> *head2=NULL;
    convertIntoSorDLL(root2,head2);
    head2->left=NULL;
    
//     step 2 merge two linked list
   TreeNode<int> *head =  mergeLinkedList(head1,head2);
    
//     step 3 convert sll to BST
    return sortedLLToBST(head,countNode(head));
}

// largest BST subtree

// we return four thing at one time so we use class
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root,int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    // first reach at the leaf node of left side 
    
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    
    info currNode;
    // this currNode help to keep track of left and right side of 4 thing 
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    

    // this is the condition in which we check that bst is valid or not 
    // 1) left subtree true
    // 2) right subtree true 
    // 3) left.max<root-.data < right.mini
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST=true;
    }
    
    else{
        currNode.isBST=false;
    }
    
    // update our answer
    if(currNode.isBST){
        ans=max(ans,currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize=0;
    info temp=solve(root,maxSize);
    return maxSize;
}
