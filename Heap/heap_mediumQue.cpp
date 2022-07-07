// Kth Largest Sum Subarray: 
https://www.codingninjas.com/codestud...

#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.

    // creation of min heap
    priority_queue<int,vector<int>,greater<int> > pq;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            // store the subarray sum into the min heap
            if(pq.size() < k){
                pq.push(sum);
            }
            else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        
    }
    return pq.top();
}

// Merge K sorted Arrays:
https://www.codingninjas.com/codestud...

// T.C-O(N*KLOGK)
// S.C-O(N*K)

// create our own data structure 
class node{
    public:
    int data,row,col;
    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};

// its necessary when we min heap and we create our own data 
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    priority_queue<node*,vector<node*>,compare> minheap;

    // insert the first element of all the array
    for(int i=0;i<k;i++){
        node* temp=new node(kArrays[i][0],i,0);
        minheap.push(temp);
    }

    // store the original ans
    vector<int>ans;
    while(minheap.size() > 0){
        node* temp=minheap.top();
        ans.push_back(temp->data);
        minheap.pop();
        int i=temp->row;
        int j=temp->col;

        // for further node 
        if(j+1 < kArrays[i].size()){
            node* next=new node(kArrays[i][j+1],i,j+1);
            minheap.push(next);
        }
    }
    return ans;
}

// Merge K sorted Linked List: 
https://www.codingninjas.com/codestud...


// similiar to k sorted linked list

// T.C-O(KLOGK)+O(N*KLOGK)=O(N*KLOGK)
// S.C-O(K)

class compare{
    public:
    bool operator()(Node<int>* a,Node<int>* b){
        return a->data > b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
 int k=listArray.size();
 if(k==0){
     return NULL;
 }   
 priority_queue<Node<int>*,vector<Node<int>*>,compare>minheap;
 for(int i=0;i<k;i++){
     if(listArray[i] != NULL){
         minheap.push(listArray[i]);
     }
 }
    Node<int>* head=NULL;
    Node<int>* tail=NULL;
    while(minheap.size() > 0){
        Node<int>* top=minheap.top();
        minheap.pop();
        if(top->next!=NULL){
            minheap.push(top->next);
        }
        
        if(head==NULL){
            head=tail=top;
        }
        else{
            tail->next=top;
            tail=top;
        }
        
    }
    return head;
}