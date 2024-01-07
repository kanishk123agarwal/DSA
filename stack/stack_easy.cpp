#include<iostream>
#include<stack>
using namespace std;

void middleEle(stack<int>st,int pos){
    // base condition
    if(pos==1){
        cout<<"Middle Element "<<st.top();
        return;
    }
    pos--;
    int temp=st.top();
    st.pop();
    middleEle(st,pos);
    st.push(temp);

}
void insertSort(stack<int> &st,int element){
    if(st.empty() || element>st.top()){
        st.push(element);
        return;
    }
    int temp=st.top();
    st.pop();

    insertSort(st,element);

    st.push(temp);
}
void sortStack(stack<int>& st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    sortStack(st);
    insertSort(st,temp);
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(2);
    st.push(34);
    st.push(90);
    st.push(4);
    st.push(50);
    int pos;
    if(st.size()%2==0){
        pos=(st.size())/2;
    }
    else{
        pos=(st.size()/2)+1;
    }
    // pattern to find middle and insert at any position in the stack without disturbing stack element
    // question: Insert at the bottom 

    // middleEle(st,pos); -o(n)

    // Question 2: Inserted in sorted array - o(n)
    // insertSort(st,25);
    // print
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }

    // question 3: sort a stack - o(n^2)
    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}