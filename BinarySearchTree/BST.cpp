#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;
    
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
Node* insertIntoBST(Node* root,int d){
    // base case
    if(root==NULL){
        root=new Node(d);
        return root;
    }

    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }

    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}

Node* minVal(Node* root){
  Node* temp=root;
  while(temp->left != NULL){
    temp=temp->left;
  }
  return temp;
}

Node* deleteFromBST(Node* root ,int d){
    if(root==NULL){
        return root;
    }

    if(root->data == d){
     
    //  0 child
       if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
       }

    // 1 child
    //    left child

        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

    // right child

    if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

    // 2) child 
        
        if(root->left != NULL && root->right != NULL){
            int min=minVal(root->right)->data;
            root->data=min;
            root->right = deleteFromBST(root->right,min);
            return root;
        }

    }

    else if(root->data > d){
        root->left=deleteFromBST(root->left,d);
        return root;
    }

    else{
        root->right=deleteFromBST(root->right,d);
        return root;
    }
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void takeInput(Node* &root){
    int d;
    cin>>d;

    while(d!=-1){
        root=insertIntoBST(root,d);
        cin>>d;
    }
}

int main(){
    Node* root=NULL;
    cout<<"Enter the data to create a BST:"<<endl;

    takeInput(root);

    cout<<"Print the data: "<<endl;
    preorder(root);

    root=deleteFromBST(root,50);
    
    cout<<"Print the data: "<<endl;
    preorder(root);

}

// 50 20 70 10 30 90 110 -1