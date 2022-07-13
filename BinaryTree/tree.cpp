#include <iostream>
#include <queue>
#include<stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *BuildTree(node *root)
{

    // inserting a node 
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left" << endl;
    root->left = BuildTree(root->left);

    cout << "Enter the data for inserting in right" << endl;

    root->right = BuildTree(root->right);
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << "The data is: " << root->data << endl;
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "The data is: " << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

// level order traversal
void levelorderTr(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// revrese level order traversal
void revlevelorderTr(node* root){
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
       node* temp= q.front();
       s.push(temp);
       q.pop();
       if(temp->left){
           q.push(temp->left);
       }
       if(temp->right){
           q.push(temp->right);
       }
    }
    while(!s.empty()){
        
        root=s.top();
        cout<<root->data<<" ";
        s.pop();
    }
    
}

// void  Buildfromlevelorder(node* &root){
//     queue<node*> q;
//     cout<<"Enter the data"<<endl;
//     int data;
//     cin>>data;
//     root=new node(data);
//     q.push(root);
//     while(!q.empty()){
//       node* temp=q.front();
//       q.pop();

//       cout<<"Enter left node for:"<<temp->data<<endl;
//       int leftdata;
//       cin>>leftdata;
//       if(leftdata!=-1){
//         temp->left=new node(leftdata);
//         q.push(temp->left);
//       }

//       cout<<"Enter right node for:"<<temp->data<<endl;
//       int rightdata;
//       cin>>rightdata;
//       if(rightdata!=-1){
//         temp->right=new node(rightdata);
//         q.push(temp->right);
//       }
//     }
// }
// void inorderITR(node *root)
// {
//     queue<node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         node *temp = q.front();

        
//         if (temp->left)
//         {
//             q.push(temp->left);
//         }
//         cout << temp->data << " ";

//         if (!q.empty())
//         {
//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }
int main()
{
    node *root = NULL;
    // Buildfromlevelorder(root);
    // // creating a tree
    root = BuildTree(root);
   inorder(root);
    // //    preorder(root);
    levelorderTr(root);
    // //   1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // // inorderITR(root);
    revlevelorderTr(root);
    // return 0;
}


// TREE TRAVERSAL
// 1) LEVEL ORDER tr
// 2) INORDER TR
// 3) PREORDER TR
// 4) POSTORDER TR
// 5) ZIG-ZAG TR 
// 6) BOUNDRY TR
// 7) VERTICAL TR
// 8) DIAGONAL TR

// VIEW IN BINARY TREE 
// 1) TOP VIEW
// 2) BOTTOM VIEW
// 3) RIGHT VIEW
// 4) LEFT VIEW