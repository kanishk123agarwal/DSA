#include<iostream>
#include<queue>
using namespace std;
int main(){
    deque<int>d;
    d.push_back(12);
    d.push_front(14);
    // cout<<d.front()<<" "<<d.back()<<endl;
    d.pop_front();
    // cout<<d.front()<<" "<<d.back()<<endl;
    d.pop_back();
    cout<<d.front()<<" "<<d.back()<<endl;
    cout<<d.size()<<endl;
    if(d.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
}