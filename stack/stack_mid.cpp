#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string str){
    stack<char> st;
    
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        // maine pehle saare element push krdiye exept 'a,b' or any alphabet that is present in the expression
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%'){
            st.push(ch);
        }
        // ab yha pr apan ne check kiye top jab tk '(' yeh nhi hoga jabn tk apan count krenge operator ka 
        else if(ch==')'){
            int countOp=0;
            while(!st.empty() && st.top()!='('){
                // char temp=st.top();
                // if(temp=='+' || temp=='*' || temp=='-' || temp=='%' || temp=='/'){
                //     countOp++;
                // }
                countOp++;
                st.pop();
            }
            // yha pr stack ka top '(' is pai hoga to isko bhi remove krna hai 
            // mistake ho skti hai yha pr 
            st.pop();
            // agar koi operator present nhi hai to vo redundant brackets hai 
            if(countOp==0){
                return true;
            }
        }

    }
    return false;
}

int main(){
    string str="(((a+b)*(c+d)))";
    bool ans=checkRedundant(str);
    if(ans==true){
        cout<<"Redundant Brackets present"<<endl;
    }
    else{
        cout<<"Redundant Brackets not present"<<endl;
    }
}

// question 2 : min stack 
// in this we write function of push pop top and getMin in o(1) time complexity
class MinStack {
public:
    vector<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int,int> p;
        if(st.empty()){
            p.first=val;
            p.second=val;
        }
        else{
            p.first=val;
            int oldMin=st.back().second;
            p.second=min(val,oldMin);
        }
        st.push_back(p);
    }
    
    void pop() {
        if(!st.empty()){
            st.pop_back();
        }
        
    }
    
    int top() {
        pair<int,int> rightMost=st.back();
        return rightMost.first;
    }
    
    int getMin() {
        pair<int,int> rightMost=st.back();
        return rightMost.second;
    }
};

// Question :3
// problem : next smallest element 
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

vector<int> nextSmaller(int *arr,int size,vector<int> ans){
    stack<int> st;
    st.push(-1);
// in this we traverse right to left direction 
    for(int i=size-1;i>=0;i--){
        int curr=arr[i];
        while(curr <= st.top()){
            st.pop();
        }
        ans[i]=st.top(); 
        st.push(curr);
    }
    return ans;
}

// question 4: previous smaller element 
vector<int> prevSmaller(int *arr,int size,vector<int> ans){
    stack<int> st;
    st.push(-1);
// in this we have to traverse in left tot right direction
    for(int i=0;i<size;i++){
        int curr=arr[i];
        while(curr <= st.top()){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}
int main(){
    int arr[]={8,4,6,2,3};
    int size=5;
    vector<int> ans(size);
    ans=nextSmaller(arr,size,ans);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

// Question 5: next smaller element
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(const vector<int>& nums) {
    stack<int> s;
    vector<int> result(nums.size(), -1);

    for (int i = 0; i < nums.size(); ++i) {
        while (!s.empty() && nums[i] < nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> result = nextSmallerElement(nums);
    for (int num : result)
        cout << num << " ";
    return 0;
}

// Question 6: Next greater element
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums) {
    stack<int> s;
    vector<int> result(nums.size(), -1);

    for (int i = 0; i < nums.size(); ++i) {
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 1, 3, 4, 5};
    vector<int> result = nextGreaterElement(nums);
    for (int num : result)
        cout << num << " ";
    return 0;
}