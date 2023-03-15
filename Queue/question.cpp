#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// reverse the queue using stack
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> s;
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        s.push(ele);
    }
    queue<int> ans;
    while(!s.empty()){
        int ele=s.top();
        s.pop();
        ans.push(ele);
    }
    return ans;
}

// first negative number for every k window
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                            
    deque<long long int> dq ;
    vector<long long> ans;
    
    // process the window for k size
    for(int i=0;i<K;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    // process remaining window
    for(int i=K;i<N;i++){
        // remove first element
        if(!dq.empty() && i-dq.front()>=K){
            dq.pop_front();
        }
        
        // addition element
        if(A[i]<0){
            dq.push_back(i);
        }
        if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    }
    
    return ans;
    
 }

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    int t=q.size()-k;
    while(t--){
        int val=q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main(){
    int n=6;
    queue<int> q;
    for(int i=0;i<6;i++){
        int ele;
        cin>>ele;
        q.push(ele);
    }
    queue<int> d;
    for(int i=0;i<6;i++){
        int ele= q.front();
        cout<<ele<<" ";
        d.push(ele);
        q.pop();
    }
    for(int i=0;i<6;i++){
        cout<<d.front()<<" ";
        d.pop();
    }
    return 0;
}