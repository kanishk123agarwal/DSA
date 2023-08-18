#include<bits/stdc++.h>
using namespace std;

void explainPairs(){
    pair<int,int> p={2,3};
    cout<<p.first<<" "<<p.second<<endl;
   
    // nested pair
    pair<int,pair<int,int>> a={1,{5,6}};
    cout<<a.first<<" "<<a.second.first<<" "<<a.second.second<<endl;

    // array in pair
    pair<int,int> arr[]={{1,4},{20,30},{20,90}};
    cout<<arr[1].second<<" "<<arr[1].first;
}

void explainVector(){
    vector<int> a;
    a.push_back(1);
    a.emplace_back(4);

    // pair in vector
    vector<pair<int,int>> b;
    b.push_back({5,6});
    b.emplace_back(9,10);

    // put size and value
    vector<int> c(5,100);
    vector<int> d(5);  //5 size and 0 in all the place

    vector<int> v1(5,20);
    vector<int>v2(v1);

    // iterator to access
    vector<int>::iterator it=v1.begin();
    it++;
    cout<<*(it);

    // for loop 
    for(auto it1=v2.begin();it1!=v2.end();it1++){
        cout<<*(it1);
    }

    // for each loop
    for(auto it:v2){
        cout<<it;
    }
}
int main(){
    explainPairs();
    // vector
    // list
    // deque
    // stack
    // queue
    // priority_queue
    // set
    //   1)unique
    //   2) sorted 
    // multiset
    //   1)sorted 
    // unordered_set
    //   1)unique 
    // map
    //    1) unique keys
    //   2)sorted order
    // multimap
    //   1)sorted
    //   2)duplicate keys
    return 0;
}