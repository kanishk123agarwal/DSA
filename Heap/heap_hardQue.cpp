// Smallest Range in K sorted List:
https:www.codingninjas.com/codestud...

#include<queue>
#include<limits.h>

T.C-O(NLOGK)
S.C-O(K)

class node{
    public:
    int data;
    int row,col;
    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int mini=INT_MAX;
    int maxi=INT_MIN;
    priority_queue<node*,vector<node*>,compare> minH;
    
    for(int i=0;i<k;i++){
        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minH.push(new node(element,i,0));
    }
    int start=mini,end=maxi;
    
//     process range
    while(!minH.empty()){
//         mini fetch
        node* temp=minH.top();
        minH.pop();
        mini=temp->data;
        
//         range or update the answer
        if(maxi-mini <end-start){
            start=mini;
            end=maxi;
        }
//         next element exist
        if(temp->col+1 < n){
            maxi=max(maxi,a[temp->row][temp->col+1]);
            minH.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            break;
        }
    }
    return (end-start+1);
}


// Median in a Stream:
https://www.codingninjas.com/codestud...


int signum(int a,int b){
    if(a==b){
        return 0;
    }
    else if(a > b){
        return 1;
    }
    else{
        return -1;
    }
}

void callMedian(int element,priority_queue<int> &maxi,
    priority_queue<int,vector<int>,greater<int> > &mini,int & median ){
    switch(signum(maxi.size(),mini.size())){
        case 0: 
            if(element > median){
                mini.push(element);
                median=mini.top();
            }
            else{
                maxi.push(element);
                median=maxi.top();
            }
            break;
            
        case 1:
            if(element > median){
                mini.push(element);
                median=(mini.top()+maxi.top())/2;
            }
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median=(mini.top()+maxi.top())/2;
            }
            break;
        case -1:
            if(element > median){
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median=(mini.top()+maxi.top())/2; 
            }
            else{
                maxi.push(element);
                median=(mini.top()+maxi.top())/2;
            }
            break;
    }
}



vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
    priority_queue<int>maxH;
    priority_queue<int,vector<int>,greater<int> > minH;
    vector<int> ans;
    int median=-1;
    for(int i=0;i<n;i++){
        callMedian(arr[i],maxH,minH,median);
        ans.push_back(median);
    }
    return ans;
}
